#define MAVLINK10
#define DEBUG_PARAM
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
//#include "parameter.h"
#include <Stream.h>
#include <stdint.h>
#include <AP_EEPROMB.h>
#include <EEPROM.h>


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
boolean SPT = false;
TinyGPS gps;
float flat;
float flon;
unsigned long age;
static void gpsdump(TinyGPS &gps);
static bool feedgps();
unsigned long tx=0;
unsigned long ty=0;
int cx, cy;
float px, py;
int ox, oy;
int pIndexa = 0;
int pot;
float value;

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
//unsigned long test;

int lsx;  //last pitch from HUD
int lsy;   //last roll from HUD
int lex;
int ley;
int mapLastX;
int mapLastY;
float mapZoom = 1.0;
char cFloat[15];
String bline;


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

FastSerialPort0(Serial);
FastSerialPort1(Serial1);
FastSerialPort2(Serial2);

#define DEBUG
void setup()
{
    randomSeed(analogRead(0));
  
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
   //myGLCD.print(, CENTER, 0);
   
     myTouch.InitTouch(1);
     myTouch.setPrecision(PREC_LOW);
    
    Serial.begin(115200); //Debug USB Port
#ifdef DEBUG // = true
    Serial.println("");
    Serial.println("Debug Port 0 Started @115200bps");
    myGLCD.print("Debug Port 0 Started @115200bps", LEFT, 30);
    
#endif 

    Serial1.begin(57600); //Xbee port
#ifdef DEBUG //= true
    Serial.println("Xbee Port 1 Started @ 57600bps");
    myGLCD.print("Xbee Port 1 Started @ 57600bps", LEFT, 42);
    Serial.println("Starting Xbee");
    myGLCD.print("Starting Xbee...", LEFT, 54);
    delay(4000);
    Serial1.println("...");
#endif

    Serial2.begin(38400); //GPS
#ifdef DEBUG //= true
    Serial.println("GPS Port 2 Started @ 38400bps");
    myGLCD.print("GPS Port 2 Started @ 38400bps", LEFT, 66);
    
#endif

    delay(3000);
    SetMenu(0, 0);
    pinMode(13, OUTPUT);
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Master Loop
/////////////////////////////////////////////////////////////////////////////////////////////

void loop()
{
  if(SPT)
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
      //cmdRequestParm();
      //delay(1000);
      //cmdRequestParm();
      //delay(1000);
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
    gps.f_get_position(&flat, &flon, &age); 
  
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


