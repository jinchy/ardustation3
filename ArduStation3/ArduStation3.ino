#define MAVLINK10
//#define DEBUG_PARAM
//#define DEBUG_MAV

#include <FastSerial.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <math.h>
#include <UTFT.h>
#include <ITDB02_Touch.h>

#include <TinyGPS.h>
#include <GCS_MAVLink.h>
#include <Stream.h>
#include <stdint.h>
//#include <AP_EEPROMB.h>
#include <EEPROM.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <Wire.h>                       // For some strange reasons, Wire.h must be included here
#include <DS1307new.h>
const uint8_t chipSelect = 53;
const uint8_t spiSpeed = SPI_FULL_SPEED;

//int i;
Sd2Card card;
SdFat sd;

SdFile eLog;
boolean beLog;

SdFile tLog;
boolean btLog;

uint16_t startAddr = 0x0000;            // Start address to store in the NV-RAM
uint16_t lastAddr;                      // new address for storing in NV-RAM
uint16_t TimeIsSet = 0xaa55;            // Helper that time must not set again

//SdFile file;
//boolean bfile;

uint32_t cardSizeBlocks;
uint16_t cardCapacityMB;
cache_t cache;
uint8_t partType;
uint32_t relSector;
uint32_t partSize;
uint8_t numberOfHeads;
uint8_t sectorsPerTrack;
uint16_t reservedSectors;
uint8_t sectorsPerCluster;
uint32_t fatStart;
uint32_t fatSize;
uint32_t dataStart;
uint16_t const BU16 = 128;
uint16_t const BU32 = 8192;

char noName[] = "JBGS3   ";
char fat16str[] = "FAT16   ";
char fat32str[] = "FAT32   ";
#define toRad(x) (x*PI)/180.0
#define toDeg(x) (x*180.0)/PI

uint8_t received_sysid=0;   ///< ID of heartbeat sender
uint8_t received_compid=0;  // component id of heartbeat sender

#define GET_PARAMS_TIMEOUT 250 //(20 seconds)

#undef PROGMEM 
#define PROGMEM __attribute__(( section(".progmem.data") )) 

#undef PSTR 
#define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];})) 

// data streams active and rates
#define MAV_DATA_STREAM_POSITION_ACTIVE 1
#define MAV_DATA_STREAM_RAW_SENSORS_ACTIVE 1
#define MAV_DATA_STREAM_EXTENDED_STATUS_ACTIVE 1
#define MAV_DATA_STREAM_RAW_CONTROLLER_ACTIVE 1
#define MAV_DATA_STREAM_EXTRA1_ACTIVE 1

// update rate is times per second (hz)
#define MAV_DATA_STREAM_POSITION_RATE 1
#define MAV_DATA_STREAM_RAW_SENSORS_RATE 1
#define MAV_DATA_STREAM_EXTENDED_STATUS_RATE 1
#define MAV_DATA_STREAM_RAW_CONTROLLER_RATE 1
#define MAV_DATA_STREAM_EXTRA1_RATE 1

// Uncomment the next line for Arduino Mega
UTFT myGLCD(ITDB32S,38,39,40,41);   // Remember to change the model parameter to suit your display module!
ITDB02_Touch  myTouch(6,5,4,3,2);
char p_buffer[80];
#define P(str) (strcpy_P(p_buffer, PSTR(str)), p_buffer)

static bool feeds = false;
boolean bSPT = false;
TinyGPS gps;
float flat;
float flon;
unsigned long age;
static void gpsdump(TinyGPS &gps);
static bool feedgps();
unsigned long tx=0;
unsigned long ty=0;
int pot;
float value;
boolean SDReady = false;
boolean pSend = false;
boolean TimeSet = false;
float tuneP;
float tuneI;
float tuneD;
float tuneIMax;
int CurrentMenu = 999;
int GoToMenu = 0;
uint8_t Touched;
uint8_t time_usec;
float flow_comp_m_x;
float flow_comp_m_y;
float ground_distance;
float flow_x;
float flow_y;
uint8_t sensor_id;
uint8_t quality;
int relative_alt;
unsigned int hdg;
uint8_t command;
uint8_t result;
uint8_t baseMode;
uint8_t customMode;
boolean mChange = true;
int limitMeters = 0;
int softLimitMeters = 0;
int pIndex;
int lsx;  //last pitch from HUD
int lsy;   //last roll from HUD
int lex;
int ley;
int mapLastX;
int mapLastY;
float mapZoom = 1.0;
char cFloat[15];
float offset = 0;
// flight data
int altitude=0;
float pitch=0;
float roll=0;
float yaw=0;
float longitude=0;
float latitude=0;
float velocity = 0;
int numSats=0;
float battery=0;
float current=0;
int currentSMode=0;
int currentNMode=0;
int gpsfix=0;
int SensorHelth=0;
int SensorsPresent=0;
int SensorsEnabled=0;
int RemainingBat=0;
int waitingAck=0;
int paramsRecv=0;
int beat=0;
int xacc;
int	yacc;
int zacc;
int xgyro;
int ygyro;
int zgyro;
int xmag;
int ymag;
int zmag;
int droneType = 1;  // 0 = Not established, 1 = APM, 2 = ACM  - Normally read from Mavlink heartbeat, but ACM returns 0, not 2
int autoPilot = 3;  // This should be 3 for ArdupilotMeg
long timeLastByte = 0;
long maxByteTime = 0;
char bline[256];


// Wrong Mavlink Version detector
byte wrongMavlinkState = 0; // Check incoming serial seperately from Mavlink library - in case we have wrong Mavlink source 
                           // State 0 means Mavlink header not yet detected
                           // if State = 5 we are receiving the wrong Mavlink format
byte packetStartByte = 0;  // first byte detected used to store which wrong Mavlink was detected 0x55 Mavlink 0.9, 0xFE Mavlink 1.0

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
//String bline;

FastSerialPort0(Serial);
FastSerialPort1(Serial1);
FastSerialPort2(Serial2);

#define DEBUG
void setup()
{
// Setup the LCD
	pinMode(2, INPUT);                    // Test of the SQW pin, D2 = INPUT
	digitalWrite(2, HIGH);                // Test of the SQW pin, D2 = Pullup on
    myGLCD.InitLCD();
    myGLCD.clrScr();
    myGLCD.setFont(SmallFont);
    myGLCD.setColor(0, 0, 128);
    myGLCD.fillRect(0, 0, 319, 239);
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(0, 0, 319, 13);
    myGLCD.setColor(255, 255, 255);
    myGLCD.setBackColor(255, 0, 0);
	RTC.setRAM(0, (uint8_t *)&startAddr, sizeof(uint16_t));// Store startAddr in NV-RAM address 0x08 
	myGLCD.print(P("Jesse's Aardustation"), CENTER, 1);
    myGLCD.setBackColor(0, 0, 128);
    myGLCD.setColor(255,255,0);   
    myTouch.InitTouch(1);
    myTouch.setPrecision(PREC_LOW);
    int i = 20;
	int logID;
	logID = GetLogID();
	char logName[12];

	date();
	myGLCD.print(bline, LEFT, i);
	i += 12;

	beLog = false;
	btLog = false;
	//bfile = false;
		
	if (!sd.begin(chipSelect, SPI_FULL_SPEED))
		{
			myGLCD.print(P("No SD Card Detected, logging disabled"), LEFT, i);
			beLog = false;
			btLog = false;
			//bfile = false;
		}
	else
		{
			i += 12;
			myGLCD.print(P("SD Card Detected"), LEFT, i);
			SdFile::dateTimeCallback(dateTime);

			strcpy(bline, P("ELog"));
			itoa(logID, cFloat, 10);
			strcat(bline, cFloat);
			strcat(bline, P(".txt"));

		if(eLogging())
		{
			i += 12;
			myGLCD.print(P("Error Logging On!"), LEFT, i);
			
			if (!eLog.open(bline, O_RDWR | O_CREAT | O_AT_END)) 
			{
				i += 12;
		 		myGLCD.print(P("Error Log Not created"), LEFT, i);
				beLog = false;
			}
		
			else
			{
				i += 12;
				myGLCD.print(P("Error Logging Started: "), LEFT, i);
				myGLCD.print(bline, 180, i);
				eLog.println();
				eLog.println(P("=============================================================="));
				beLog = true;
			}

		}
		
		else
		{
			i += 12;
			myGLCD.print(P("Error Logging Off!"), LEFT, i);
			beLog = false;
		}

		if(tLogging())
		//if(false)
		{
			i += 12;
			myGLCD.print(P("Telemetry Logging On!"), LEFT, i);
			strcpy(bline, P("tlog"));
			itoa(logID, cFloat, 10);
			strcat(bline, cFloat);
			strcat(bline,P(".log"));

			if (!tLog.open(bline, O_RDWR | O_CREAT | O_AT_END)) 
				{
					i += 12;
					myGLCD.print(P("Telemetry Log Not created"), LEFT, i);
					btLog = false;
				}
				else
				{
					i += 12;

					myGLCD.print(P("Telemetry Logging Started: "), LEFT, i);
					myGLCD.print(bline, 210, i);
					btLog = true;
				}
			}

		else
		{
			i += 12;
			myGLCD.print(P("Telemetry Logging Off!"), LEFT, i);
			btLog = false;
		}
	}


	//Serial.println("");
    //Serial.println("Debug Port 0 Started @115200bps");
	Serial.begin(115200); //Debug USB Port
	//if(beLog) eLog.print(lts());
	if(beLog) eLog.println(P("Debug Port 0 Started @115200bps"));
	i += 12;
    myGLCD.print(P("Debug Port 0 Started @115200bps"), LEFT, i);
    
    Serial1.begin(57600); //Xbee port
    //Serial.println("Xbee Port 1 Started @ 57600bps");
	if(beLog) eLog.println(P("Xbee Port 1 Started @ 57600bps"));
    i += 12;
	myGLCD.print(P("Xbee Port 1 Started @ 57600bps"), LEFT, i);
    //Serial.println("Starting Xbee");
	if(beLog) eLog.println(P("Starting Xbee..."));
    i += 12;
	myGLCD.print(P("Starting Xbee..."), LEFT, i);
    delay(4000);
    Serial1.println("...");
    Serial2.begin(38400); //GPS
	i += 12;
    //Serial.println("GPS Port 2 Started @ 38400bps");
    if(beLog) eLog.println(P("GPS Port 2 Started @ 38400bps"));
	myGLCD.print(P("GPS Port 2 Started @ 38400bps"), LEFT, i);
	int fr;
	fr = EEPROM.read(0);
	i += 12;
	

	strcpy(bline, P("Settings byte: "));
	itoa(fr, cFloat, 10);
	strcat(bline, cFloat);
	myGLCD.print(bline, LEFT, i);

	bSPT = SPT();

	i += 12;
	if(bSPT) myGLCD.print(P("SPT is True"), LEFT, i);
	if(!bSPT) myGLCD.print(P("SPT is False"), LEFT, i);
	i += 12;
	myGLCD.print("Setting clock from GPS", LEFT, i);
	delay(3000);
    if(!bSPT) SetMenu(0, 0);
	//if(bSPT) Serial.begin(115200); //Debug USB Port

    pinMode(13, OUTPUT);
	SetFromGPS(); 
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Master Loop
/////////////////////////////////////////////////////////////////////////////////////////////

void loop()
{
  if(beLog) eLog.sync();
  if(btLog) tLog.sync();
  if(beLog) eLog.print(P("Loop Start: SetMenu("));
  if(beLog) eLog.print(CurrentMenu);
  if(beLog) eLog.println(P(")"));

  if(bSPT)
  {
      if (Serial1.available()) 
      {
        int inByte = Serial1.read();
        Serial.write(inByte); 
      }
  
  // read from port 0, send to port 1:
      if (Serial.available()) 
      {
        int inByte = Serial.read();
        Serial1.write(inByte); 
      }
  }
  else
  {
    pot += analogRead(A0);
    pot += analogRead(A0);
    pot += analogRead(A0);
    pot += analogRead(A0);
    pot += analogRead(A0);
  
    pot = pot/6;
  
	if(beLog)
		{
			strcpy(bline, P("FreeRam: "));
			itoa(freeRam(), cFloat, 10);
			strcat(bline, cFloat);
			eLog.println(bline);
		}


    bool newdata = false;
    if (feedgps())
     {
       newdata = true;
     }
   
    gcs_update();
    gps.f_get_position(&flat, &flon, &age); 
    if(!TimeSet) SetFromGPS();

	if(beLog)
	{
		lts();
		strcat(bline, P("GPS Position update:\n lat: "));
		dtostrf(flat, 4, 6, cFloat);
		strcat(bline, cFloat);
		strcat(bline, P(" Lon: "));
		dtostrf(flon, 4, 6, cFloat);
		strcat(bline, cFloat);
		strcat(bline, P(" Age: "));
		itoa(age, cFloat, 10);
		strcat(bline, cFloat);
		eLog.println(bline);
	}

	if(beLog) eLog.sync();
	if(btLog) tLog.sync();

    if (limitMeters > 0)
       {
         cmdCheckLimit();  //check if distence limit is imposed
       }

    if(Touched != 0) 
      {
        --Touched;
        myTouch.read();
      }
  
    if(beat != 0) 
      {
        digitalWrite(13, LOW);
        beat = 0;
      }
    else 
        {
         digitalWrite(13, HIGH);
        }
      
    if((myTouch.dataAvailable() == true) && Touched == 0)
      {
        myTouch.read();
        tx = myTouch.TP_X;
        ty = myTouch.TP_Y;
        vButton();
      }
    SetMenu(CurrentMenu, 1);
  }
  
}


