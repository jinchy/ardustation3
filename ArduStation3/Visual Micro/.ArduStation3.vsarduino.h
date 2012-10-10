//Board = Arduino Mega 2560 or Mega ADK
#define ARDUINO 101
#define __AVR_ATmega2560__
#define F_CPU 16000000L
#define __AVR__
#define __cplusplus
#define __attribute__(x)
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__
#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define prog_void
#define PGM_VOID_P int
#define NOINLINE __attribute__((noinline))

typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {}

//already defined in arduno.h
//already defined in arduno.h
void vButton();
float rBearing();
int freeRam();
static bool feedgps();
float calc_bearing(float flat1, float flon1, float flat2, float flon2);
float calc_dist(float flat1, float flon1, float flat2, float flon2);
float to_float_6(long value);
void MainMenu();
void MainMenuR();
void Setup1();
void Setup1R();
void Debug1();
void Debug1R();
void HUD();
void HUDR();
void FlightMapM();
void FlightMapMR();
void FlightMap();
void FlightMapR();
void FollowMe();
void FollowMeR();
void SetMode();
void SetModeR();
void SetLimitM();
void SetLimitR();
void ParmM();
void ParmR();
void ParamMainP1();
void ParamMainP2();
void ParamMainR();
void LoiterTune();
void LoiterTuneR();
void NavTune();
void NavTuneR();
void StabTune();
void StabTuneR();
void StabRTune();
void StabRTuneR();
void AltTune();
void AltTuneR();
void SerialPassThru();
void SerialPassThruR();
void ThreeTune(char hdg[12], int addr);
void ThreeTuneR(int addr);
void cmdSetStab();
void cmdSetLoiter();
void cmdSetRTL();
void cmdSetAltHold();
void cmdSetAuto();
void cmdSetGuided();
void cmdSetArm();
void cmdSetComeHere(int alt);
void cmdCheckLimit();
void cmdRequestParm();
void cmdSetParm(int Parm, float value);
void gcs_update();
void gcs_handleMessage(mavlink_message_t* msg);
void start_feeds();
void send_message(mavlink_message_t* msg);
String PName(int Index);
void SetMenu(int State, int Refresh);
void EEPROM_writeDouble(int ee, double value);
double EEPROM_readDouble(int ee);

#include "C:\Users\jesse\Documents\arduino-1.0.1\hardware\arduino\variants\mega\pins_arduino.h" 
#include "C:\Users\jesse\Documents\arduino-1.0.1\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\ArduStation3.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\Buttons.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\Functions.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\GPS.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\GPS_Math.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\LCD.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\LCD_Supp.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\MAV_Commands.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\Mavlink.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\Parameters.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\SetMenu.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\TouchCalibration.ino"
#include "C:\Users\jesse\Documents\Source\Ardustation3\ArduStation3\eeprom.ino"
