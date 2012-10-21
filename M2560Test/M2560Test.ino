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
//7907 after declaring gps;
//7479 after declaring fastSerial, before enabling Serial ports
//7479 after starting serial 0, 1, 2

Sd2Card card;
SdFat sd;

//SdFile eLog;
//boolean beLog;

//SdFile tLog;
//boolean btLog;

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


UTFT myGLCD(ITDB32S,38,39,40,41);   // Remember to change the model parameter to suit your display module!
ITDB02_Touch  myTouch(6,5,4,3,2);

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
//TinyGPS gps;
//char bline[128];
int i = 20;
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
int droneType = 1;  // 0 = Not established, 1 = APM, 2 = ACM  - Normally read from Mavlink heartbeat, but ACM returns 0, not 2
int autoPilot = 3;  // This should be 3 for ArdupilotMeg
long timeLastByte = 0;
long maxByteTime = 0;
char bline[96];

FastSerialPort0(Serial);
FastSerialPort1(Serial1);
FastSerialPort2(Serial2);


void setup()
{
	myGLCD.InitLCD();
    myGLCD.clrScr();
    myGLCD.setFont(SmallFont);
    myGLCD.setColor(0, 0, 128);
    myGLCD.fillRect(0, 0, 319, 239);
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(0, 0, 319, 13);
    myGLCD.setColor(255, 255, 255);
    myGLCD.setBackColor(255, 0, 0);
    myGLCD.print("Research Test1 Memory", CENTER, 1);
    myGLCD.setBackColor(0, 0, 128);
    myGLCD.setColor(255,255,0);   
    myTouch.InitTouch(1);
    myTouch.setPrecision(PREC_LOW);
	Serial.begin(57600);
	Serial1.begin(57600);
	Serial2.begin(57600);

//	static bool feeds = false;
//boolean bSPT = false;
//TinyGPS gps;
//float flat;
//float flon;
//unsigned long age;
//static void gpsdump(TinyGPS &gps);
//static bool feedgps();
//unsigned long tx=0;
//unsigned long ty=0;
//int pot;
//float value;
//boolean SDReady = false;
//boolean pSend = false;
//float tuneP;
//float tuneI;
//float tuneD;
//float tuneIMax;
//int CurrentMenu = 999;
//int GoToMenu = 0;
//uint8_t Touched;
//uint8_t time_usec;
//float flow_comp_m_x;
//float flow_comp_m_y;
//float ground_distance;
//float flow_x;
//float flow_y;
//uint8_t sensor_id;
//uint8_t quality;
//int relative_alt;
//unsigned int hdg;
boolean mChange = true;
limitMeters = 0;
softLimitMeters = 0;
pIndex = 100;
lsx = 100;  //la//st pitch from HUD
lsy = 100;   //last roll from HUD
lex = 100;
ley = 100;
mapLastX = 100;
mapLastY = 100;
mapZoom = 1.0;
strcpy(cFloat, "just Testing");
offset = 0;
// flight data
altitude=0;
pitch=0;
roll=0;
yaw=0;
longitude=0;
latitude=0;
velocity = 0;
numSats=0;
battery=0;
current=0;
currentSMode=0;
currentNMode=0;
gpsfix=0;
SensorHelth=0;
SensorsPresent=0;
SensorsEnabled=0;
RemainingBat=0;
waitingAck=0;
paramsRecv=0;
beat=0;
droneType = 1;  // 0 = Not established, 1 = APM, 2 = ACM  - Normally read from Mavlink heartbeat, but ACM returns 0, not 2
autoPilot = 3;  // This should be 3 for ArdupilotMeg
timeLastByte = 0;
maxByteTime = 0;
}

void loop()
{
	if(i > 200) i = 0;
	
	strcpy(bline, "FreeMem: ");
	int fm = freeRam();
	char fmc[12];
	itoa(fm, fmc, 10);
	strcat(bline, fmc);

	i+= 12;
	myGLCD.print(bline, LEFT, i);
	delay(1000);
	i+= 12;
	test(i);
	fm = freeRam();
	strcpy(bline, "FreeMem: ");
	itoa(fm, fmc, 10);
	strcat(bline, fmc);
	i+= 12;
	myGLCD.print(bline, LEFT, i);
	
	i+= 12;
	test1(i);
	fm = freeRam();
	strcpy(bline, "FreeMem: ");
	itoa(fm, fmc, 10);
	strcat(bline, fmc);
	i+= 12;
	myGLCD.print(bline, LEFT, i);

	i+= 12;
	test2(i);
	fm = freeRam();
	strcpy(bline, "FreeMem: ");
	itoa(fm, fmc, 10);
	strcat(bline, fmc);
	i+= 12;
	myGLCD.print(bline, LEFT, i);

	i+= 12;
	test3(i);
	fm = freeRam();
	strcpy(bline, "FreeMem: ");
	itoa(fm, fmc, 10);
	strcat(bline, fmc);
	i+= 12;
	myGLCD.print(bline, LEFT, i);
//	free(&bline);
}
