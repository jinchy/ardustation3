// Ardustation 2
//
// This code is highly alpha quality, be aware...
//
// This is was original created by psmitty for APM and AC2 based upon orginal Ardustation code
//
// Modified to add tilt/pan functionality by Heino Pull (heyno@heino.com) 7/23/2011
// Used readymaderc.com tilt.pan solution with HITEC-485 servos. http://www.readymaderc.com/store/index.php?main_page=product_info&cPath=19_7&products_id=96
// for development and testing. 
// RAM is really tight so I had to remove the PID modification for Ardupilot Mega.
// 
// 
// v2.0.03 Modified to add battery monitoring, and manual antenna control by Hai Tran (hai@itsecurity.net.au) 4 August 2011
// Cleaned up references to PIDS menu and replaced with Antenna Stop menu (ANTS)
// Manual antenna control menu item is called ANT_TEST in the code, and called Antenna Test in the main menu
// User should set tilt_pos_upper_limit and tilt_pos_lower_limit to stop the tilt from overshooting. Start with 0 and 180 and when in the antenna testing menu find out what the min and max should be for your setup and set those values in the code.

// v2.0.05 Added conversion factor for display meters vs feet
// Added JeffE's reformat of flight data display
// Removed one debug flight data display (Heino Pull) 8/11/2011

// Clean up code for easier code handling if needed to edit in future
// Tabs added Antenna / EEPROM / Flight_Data / MAV_Link / Params
// Added GPS Fix indicator
// Jeff E 8/12/2011

// v2.0.06 Increased the text label of the params from 10 chars to 12 chars by removing the 
// Trailing "<" that identifies the current selected param, also remove one blank char space
// this makes it easier to determine which param field is selected.

// v2.0.07 Changed displayed values on tab 1 of flight data - needed to double the bearing value - the actual value is wrt the servo angle from Arduino (0-180) need (0-360) - bearing back to home
// Change on tab 1 - dir to aircraft from home (pan position) needs svbearinghome to get right value. Tested both values on the readymaderc hardware.
// Heino Pull 8/13/2011

// v2.0.08 Fix metre/feet dist conv setting.  Default is now metric

// v2.0.09 Added detection of Fixed wing and Multicopter.  Now supports both APM and ACM.

// v2.0.10 Fixed Mavlink interface changes for library with ACM 2.0.47. Made the send Mavlink message more standard with recommended calling style.  Also reduced  local stack usage when sending message.
// Fixed parameter names for Arducopter. When droneType = 2 , parameter download/mod should work
// Arducopter does not report droneType=2, so auto detect of APM/ACM is broken for now. Need to request change on ACM software to set droneType=2 on Mavlink.
// Handles APM (droneType=1) or ACM (droneType=2). Arduplane parameters don't work right now - need to check parameter names. Antenna pointing works for both Arduplane and Arducopter

// Heino R. Pull (heyno@heino.com) 10/13/2011

// v2.0.11 Fixed autodetection of ArduPlane or Arducopter from Mavlink. Uses sysid and compid from the Mavlink heartbeat to determine whether ArduPlane or Arducopter parameters should be enabled.
// Fixed parameter names to match ArduPlane 2.24. Parameter download and edit works for ArduPlane and Arducopter.
// Fixed parameter name length issue that caused Ardustation to crash for long parameter names. 
// Fixed start and stop of Mavlink feed for ArduPlane.
// Antenna tracking tested for both Arducopter 2.0.48 and ArduPlane 2.24.
// Heino R. Pull (heyno@heino.com) 10/15/2011

// v2.0.12 Fixed ambiguous function overload for lcd.write (because of new libraries and Arduino 1.0)
// Updated displayed editable parameters for ACM 2.5.3 and APM 2.30
// Additional ACM parameters added for camera stab gains roll and pitch.
// Heino R. Pull (heyno@heino.com) 4/3/2012

// v2.0.13 Added missed parameter for Arducopter - stabilize_d, stabilize_d_schedule, acro_p,  axis_lock_p, axis_enable - total of 47 parameters
// Heino R. Pull (heyno@heino.com) 4/17/2012

// v2.0.14 Added more (oops) missing D parameters - rate roll d, rate pitch d, rate yaw d, loiter d, nav d, throttle rate d - total of 55 parameters
// Fixing parameter update problem due to truncated received Mavlink nessages (Xbee in xmit mode, and bytes dropped).  Added Mavlink parser reset when messages truncated by Xbee (too much 1 Hz traffic for xmit frame)
// Heino R. Pull (heyno@heino.com) 5/20/2012

// v2.0.15 Added Mavlink 1.0 support. Support for Mavlink 0.9 is also maintained. Default is Mavlink 1.0, comment out define below to restore Mavlink 0.9. Mavlink 1.0 changes to heartbeat, and gps raw message added. Different scaling for lat/lon and
// other parameters in the GPS raw message. Message parameter renames accomodated. Added wrong Mavlink detector - checks for wrong heartbeat format being received, if detected, stops running and indicates to change the #define MAVLINK10 state for
// the actual Mavlink format received. Also displays if it is compiled for Mavlink 1.0 or 0.9. 
// Heino R. Pull (heyno@heino.com) 6/5/2012

// If you edit this code please add comments and increment the version number.
// Current Version: 2.0.15
//
#define MAVLINK10  // Uncomment for MAVLINK 1.0, otherwise comment out for MAVLINK 0.9

#include <FastSerial.h>
#include <GCS_MAVLink.h>
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <AP_EEPROMB.h> 		// ArduPilot Mega RC Library


#include <Servo.h>
#include "parameter.h"
AP_EEPROMB ee;
#undef PROGMEM 
#define PROGMEM __attribute__(( section(".progmem.data") )) 

#undef PSTR 
#define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];})) 

#define SERIAL_BAUD 57600
//#define BUZZERON // is the buzzer on?
FastSerialPort0(Serial);

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

#define GET_PARAMS_TIMEOUT 200 //(20 seconds)

// store strings in flash memory
#define MAIN_MENU 0
#define START_FEEDS 1
#define STOP_FEEDS 2
#define ANTS 3
#define ANT_TEST 4
#define GET_PARAMS 5
#define EDIT_VIEW_PARAMS 6
#define FLIGHT_DATA 7
#define INIT_EEPROM 8
#define EDIT_PARAM 10
#define SAVE_PARAM 11

#define APM_PARAMS 37
#define ACM_PARAMS 51

#define DIST_CONV 1.0   // For distance display in meters choose 0.0, for feet 3.2808


LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8); //Initailizing lcd object (this is real C++).

void lcd_print_P(const char *string)
{
  char c;
  while( (c = pgm_read_byte(string++)) )
    lcd.LiquidCrystal::write(c);
}

#define toRad(x) (x*PI)/180.0
#define toDeg(x) (x*180.0)/PI

unsigned long hb_timer;
unsigned long timer;

#define SERVO_MAX 2600 //Range of servos pitch and roll
#define SERVO_MIN 400
#define TEST_PAN 0 //Test pan min and max (for calibration)
#define TEST_SOUTH 0 //test the south (just poing to south)
#define TEST_TILT 0 //test the tilt max and min (for calibration)
Servo Pan;
Servo Tilt;
// Servo Cal variables
int pan_pos = 90;
int tilt_pos = 90;
int chg_angle = 0;
//int original_pan_pos = 90;
//int original_tilt_pos = 90;
//int original_chg_angle = 0;
#define tilt_pos_upper_limit 140 // Upper tilt limit (antenna points to the sky)
#define tilt_pos_lower_limit 60 //  Lower tilt limit (anntenna points straight ahead)


float Latitude_Home=0;
float Longitud_Home=0;
int Altitude_Home = 0;
float Distance_Home=0;
float Distance3D_Home=0;
int Angle_Home=0;
int Constrain_Angle_Home = 0;
float Bearing_Home=0;
float SvBearingHome = 0;

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
int SensorHelth=5;
int SensorsPresent=5;
int SensorsEnabled=5;
int RemainingBat=5;

// menus etc
int menu=0;
int subMenu=0;
int currentOption=0;
int lastOption=0;
int timeOut=0;
int redraw=1;
int waitingAck=0;
parameter editParm;
int paramsRecv=0;
int beat=0;
int droneType = 1;  // 0 = Not established, 1 = APM, 2 = ACM  - Normally read from Mavlink heartbeat, but ACM returns 0, not 2
int autoPilot = 3;  // This should be 3 for ArdupilotMeg
uint8_t received_sysid=0;   ///< ID of heartbeat sender
uint8_t received_compid=0;  // component id of heartbeat sender
int TOTAL_PARAMS = 51;

// Saved time (in msecs) for the last message byte received while not in Mavlink idle
// 0 = in idle - no message in process
long timeLastByte = 0;
long maxByteTime = 0;

// Wrong Mavlink Version detector
byte wrongMavlinkState = 0; // Check incoming serial seperately from Mavlink library - in case we have wrong Mavlink source 
                           // State 0 means Mavlink header not yet detected
                           // if State = 5 we are receiving the wrong Mavlink format
byte packetStartByte = 0;  // first byte detected used to store which wrong Mavlink was detected 0x55 Mavlink 0.9, 0xFE Mavlink 1.0
    



byte heart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
};

/*byte fix2D[8] = {
  B01110,
  B01110,
  B00100,
  B11111,
  B11111,
  B00100,
  B01110,
  B01110,
};

byte fix3D[8] = {
  B11111,
  B11011,
  B11011,
  B10001,
  B10001,
  B11011,
  B11011,
  B11111,
}; */

void lcdPrintString(int stringId, const char *table[])
{
    char buffer[21];
    strcpy_P(buffer, (char*)pgm_read_word(&(table[stringId])));
    lcd.LiquidCrystal::print(buffer);
}

void setup()
{
  Serial.begin(SERIAL_BAUD);
  lcd.createChar(0, heart);
//  lcd.createChar(1, fix2D);
//  lcd.createChar(2, fix3D);
  //Servo Calibration!!!!
  Pan.attach(9,609,2255);//PAN Servos  //These numbers seem to work well for the HITEC-485 servos 
  Tilt.attach(10,591,2235);//Tilt Elevator
  
  Pan.write(pan_pos);
  Tilt.write(tilt_pos);

    
  delay(4000);
  
  lcd.begin(20, 4);
  pinMode(14,OUTPUT); //Pin mode as output to control buzzer (analog0)
  pinMode(11,OUTPUT);
  lcd.clear();
  lcd_print_P(PSTR("   ArduStation 2"));
  lcd.setCursor(0, 1);
#ifdef MAVLINK10
 lcd_print_P(PSTR("  with MAVLink 1.0"));
#else // MAVLINK10
 lcd_print_P(PSTR("  with MAVLink 0.9"));
#endif // MAVLINK10
  lcd.setCursor(0, 2);
  lcd_print_P(PSTR("       and"));
  lcd.setCursor(0,3);
  lcd_print_P(PSTR(" Antenna Tracking "));
  delay(2000);
  if (EEPROM_readRevision() != 0)
  {
    init_EEPROM();
    EEPROM_writeRevision();
  } 
  RestoreHomePosition(); 
  lcd.clear();
  lcd_print_P(PSTR("Starting xbee..."));
  Serial.println("...");
  delay(2000);
}

void loop()
{
  // If we detect the wrong Mavlink - display the wrong version and don't process the menu
  if (wrongMavlinkState==6)
  {
    lcd.clear();
    lcd_print_P(PSTR("Wrong Mavlink"));
    lcd.setCursor(0,1);
    lcd_print_P(PSTR("Recompile with"));
    lcd.setCursor(0,2);
#ifdef MAVLINK10
    lcd_print_P(PSTR("Mavlink 0.9"));
#else // MAVLINK10
    lcd_print_P(PSTR("Mavlink 1.0"));
#endif // MAVLINK10
    lcd.setCursor(0,3);
    lcd.print(packetStartByte);
    while (1)
    {
    }
  }
  else
  {
    
        switch (menu)
        {
          case MAIN_MENU: // main menu
          {
            if (redraw == 1)
              main_menu();
            break;
          }
          case START_FEEDS: // start feeds
          {
            start_feeds();
            break;
          }
          case STOP_FEEDS: // stop feeds
          {
            stop_feeds();
            break;
          }  
          case ANTS: // ANTS  - replaced PIDS adjustment with set servo hard stop menu
          {
            if (redraw == 1)
              SetServoHardStop();
            break;
          }
          case ANT_TEST: //Antenna Test
          {
            if (redraw == 1)
              SetAntennaPosition();
            break;
          }
          case GET_PARAMS: // get params
          {
            get_params();
            //EEPROM_writeParamCount(totalParams);
            break;
          }
          case EDIT_VIEW_PARAMS: // view/edit params
          {
            if (redraw == 1)
              list_params();
            break; 
          }
          case FLIGHT_DATA: // flight data
          {
            flight_data();
            break;
          }    
          case INIT_EEPROM: // init eeprom
          {
            init_EEPROM();
            break;
          }
          case 10:
          {
            if (redraw == 1)
              edit_params();
            break;
          }
          case 11:
          {
            save_param();
            break; 
          }
        }
        if (millis() - hb_timer > 500)
        {
          hb_timer = millis();
      //    lcd.setCursor(0,3); // Diagnostic for Mavlink parser reset code
      //    lcd.print(maxByteTime);
          lcd.setCursor(19,3);
          if (beat == 1)
          {
            beat = 0;
            lcd.LiquidCrystal::write((uint8_t)0);
          }
          else
            lcd.print(" ");
        }
        gcs_update();
        Check_Buttons(4);
     
  }
}

void lcd_debug(char* msg)
{
  lcd.setCursor(0,0);
  lcd.print(msg);
}
void main_menu() // menu 0
{
  lcd.clear();
  if (currentOption < 4)
  {
    lcd.setCursor(2,0);
    lcd_print_P(PSTR("Start Feeds"));
    lcd.setCursor(2,1);
    lcd_print_P(PSTR("Stop Feeds"));
    lcd.setCursor(2,2);
    lcd_print_P(PSTR("Antenna Stop"));
    lcd.setCursor(2,3);
    lcd_print_P(PSTR("Antenna Test"));
    lcd.setCursor(18,3);
//    lcd.LiquidCrystal::write(1);
  }
  if (currentOption > 3 && currentOption < 8)
  {
    lcd.setCursor(18,0);
 //   lcd.LiquidCrystal::write(2);
    lcd.setCursor(2,0);
    lcd_print_P(PSTR("Get Params"));
    lcd.setCursor(2,1);
    lcd_print_P(PSTR("Edit/View Params"));
    lcd.setCursor(2,2);
    lcd_print_P(PSTR("Flight Data"));
    lcd.setCursor(2,3);
    lcd_print_P(PSTR("Init EEPROM"));
  }
  lcd.setCursor(0,currentOption%4);
  lcd.print(">>");
  redraw = 0;  
}

int availableMemory() {
  int size = 2048;
  byte *buf;

  while ((buf = (byte *) malloc(--size)) == NULL)
    ;

  free(buf);

  return size;
}
