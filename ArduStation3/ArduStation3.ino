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
#include <AP_EEPROMB.h>
#include <EEPROM.h>
#include <SdFat.h>
#include <SdFatUtil.h>
const uint8_t chipSelect = 53;
const uint8_t spiSpeed = SPI_FULL_SPEED;

int i;
Sd2Card card;
SdFat sd;

SdFile eLog;
boolean beLog;

SdFile tLog;
boolean btLog;

SdFile file;
boolean bfile;

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

static bool feeds = false;
//boolean SPT = false;
TinyGPS gps;
float flat;
float flon;
unsigned long age;
static void gpsdump(TinyGPS &gps);
static bool feedgps();
unsigned long tx=0;
unsigned long ty=0;
//int cx, cy;
//float px, py;
//int ox, oy;
//int pIndexa = 0;
int pot;
float value;
boolean SDReady = false;
boolean pSend = false;
float tuneP;
float tuneI;
float tuneD;
float tuneIMax;
int CurrentMenu = 999;
int GoToMenu = 0;
int Touched;
int time_usec;
float flow_comp_m_x;
float flow_comp_m_y;
float ground_distance;
float flow_x;
float flow_y;
int sensor_id;
int quality;
int relative_alt;
unsigned int hdg;
int command;
int result;
int baseMode;
int customMode;
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
int droneType = 1;  // 0 = Not established, 1 = APM, 2 = ACM  - Normally read from Mavlink heartbeat, but ACM returns 0, not 2
int autoPilot = 3;  // This should be 3 for ArdupilotMeg
long timeLastByte = 0;
long maxByteTime = 0;

// Wrong Mavlink Version detector
byte wrongMavlinkState = 0; // Check incoming serial seperately from Mavlink library - in case we have wrong Mavlink source 
                           // State 0 means Mavlink header not yet detected
                           // if State = 5 we are receiving the wrong Mavlink format
byte packetStartByte = 0;  // first byte detected used to store which wrong Mavlink was detected 0x55 Mavlink 0.9, 0xFE Mavlink 1.0

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
String bline;

FastSerialPort0(Serial);
FastSerialPort1(Serial1);
FastSerialPort2(Serial2);

#define DEBUG
void setup()
{
// Setup the LCD
    myGLCD.InitLCD();
    myGLCD.clrScr();
    myGLCD.setFont(SmallFont);
    myGLCD.setColor(0, 0, 128);
    myGLCD.fillRect(0, 0, 319, 239);
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(0, 0, 319, 13);
    myGLCD.setColor(255, 255, 255);
    myGLCD.setBackColor(255, 0, 0);
    myGLCD.print("Jesse's Ardustation III", CENTER, 1);
    myGLCD.setBackColor(0, 0, 128);
    myGLCD.setColor(255,255,0);   
    myTouch.InitTouch(1);
    myTouch.setPrecision(PREC_LOW);
    i = 30;
	int logID;
	logID = GetLogID();
	char logName[12];

	beLog = false;
	btLog = false;
	bfile = false;
		
	if (!sd.begin(chipSelect, SPI_FULL_SPEED))
		{
			myGLCD.print("No SD Card Detected, logging disabled", LEFT, i);
			beLog = false;
			btLog = false;
			bfile = false;
		}
	else
		{
			i += 12;
			myGLCD.print("SD Card Detected", LEFT, i);

			bline = "ELog";
			bline += logID;
			bline += ".txt";
			bline.toCharArray(logName, 12);

			if (!eLog.open(logName, O_RDWR | O_CREAT | O_AT_END)) 
			{
				i += 12;
		 		myGLCD.print("Error Log Not created", LEFT, i);
				beLog = false;
			}
			else
			{
				i += 12;
				myGLCD.print("Error Logging Started: " + bline, LEFT, i);
				eLog.println();
				eLog.println("==============================================================");
				beLog = true;
			}

			bline = "tlog";
			bline += logID;
			bline += ".log";
			bline.toCharArray(logName, 12);

		/*if (!tLog.open(logName, O_RDWR | O_CREAT | O_AT_END)) 
			{
				i += 12;
				myGLCD.print("Telemetry Log Not created", LEFT, i);
				btLog = false;
			}
			else
			{
				i += 12;

				myGLCD.print("Telemetry Logging Started: " + bline, LEFT, i);
				btLog = true;
			}*/
		}

    Serial.begin(115200); //Debug USB Port

	Serial.println("");
    Serial.println("Debug Port 0 Started @115200bps");
	if(beLog) eLog.println("Debug Port 0 Started @115200bps");
	i += 12;
    myGLCD.print("Debug Port 0 Started @115200bps", LEFT, i);
    
    Serial1.begin(57600); //Xbee port
    Serial.println("Xbee Port 1 Started @ 57600bps");
	if(beLog) eLog.println("Xbee Port 1 Started @ 57600bps");
    i += 12;
	myGLCD.print("Xbee Port 1 Started @ 57600bps", LEFT, i);
    Serial.println("Starting Xbee");
	if(beLog) eLog.println("Xbee Port 1 Started @ 57600bps");
    i += 12;
	myGLCD.print("Starting Xbee...", LEFT, i);
    delay(4000);
    Serial1.println("...");
    Serial2.begin(38400); //GPS
	i += 12;
    Serial.println("GPS Port 2 Started @ 38400bps");
    if(beLog) eLog.println("GPS Port 2 Started @ 38400bps");
	myGLCD.print("GPS Port 2 Started @ 38400bps", LEFT, i);
    
    delay(3000);
    SetMenu(0, 0);
    pinMode(13, OUTPUT);
//	FactReset();
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Master Loop
/////////////////////////////////////////////////////////////////////////////////////////////

void loop()
{
  //beLogFlush();
  if(beLog) eLog.sync();
  if(btLog) tLog.sync();
  //Serial.println("Loop Start");
  if(beLog) eLog.print("Loop Start: SetMenu(");
  if(beLog) eLog.print(CurrentMenu);
  if(beLog) eLog.println(")");

  if(false)
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
      
      if((myTouch.dataAvailable() == true) && Touched == 0)
      {
        myTouch.read();
        tx = myTouch.TP_X;
        ty = myTouch.TP_Y;
        vButton();
      }
  }
  else
  {
  //
  //if((pot - analogRead(A0))>1) pot = analogRead(A0);
  //if((analogRead(A0) - pot)>1) pot = analogRead(A0);
    pot += analogRead(A0);
    pot += analogRead(A0);
    pot += analogRead(A0);
    pot += analogRead(A0);
    pot += analogRead(A0);
  
    pot = pot/6;
  
  //digitalWrite(13, HIGH);
    if(!feeds)
    {
#ifdef DEBUG
        Serial.print("Starting Feeds...");
#endif
        start_feeds();
        feeds = true;
#ifdef DEBUG
        Serial.println("Started");
#endif

    }
  
#ifdef DEBUG
//      Serial.println(freeRam());
#endif

    bool newdata = false;
    if (feedgps())
     {
       newdata = true;
       Serial2.flush();
     }
   
    gcs_update();
	if(btLog) tLog.sync();

    gps.f_get_position(&flat, &flon, &age); 
    
	if(beLog)
	{
		bline = "GPS Position update:\n lat: ";
		dtostrf(flat, 4, 2, cFloat);
		bline += cFloat;
		bline += " Lon: ";
		dtostrf(flon, 4, 2, cFloat);
		bline += cFloat;
		bline += " Age: ";
		bline += age;
		eLog.println(bline);
	}

	if(beLog) eLog.sync();
	
  
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


