//#include <SoftwareSerial.h>
#include "Ultrasonic.h"
#include <Wire.h>

Ultrasonic us1(12,13);
Ultrasonic us2(10,11);
Ultrasonic us3(8,9);
Ultrasonic us4(6,7);
Ultrasonic us5(4,5);
Ultrasonic us6(2,3);
 
int lusd1;
long lusv1;

int lusd2;
unsigned long lusv2;

int lusd3;
unsigned long lusv3;

int lusd4;
unsigned long lusv4;

int lusd5;
unsigned long lusv5;

int lusd6;
unsigned long lusv6;

unsigned char LSB;  // 1 byte
unsigned char MSB; // 1 byte

String bline;
//SoftwareSerial mySerial(5,4);


// function that executes whenever data is requested by master
// this function is registered as an event, see setup()

void setup()
{
Serial.begin(115200);
Wire.begin(2);                // join i2c bus with address #2
Wire.onRequest(requestEvent); // register event
//Wire.onReceive(receiveEvent); // register event

}
 
void loop()
{
lusd1 = us1.Ranging(CM);
lusd2 = us2.Ranging(CM);
lusd3 = us3.Ranging(CM);
lusd4 = us4.Ranging(CM);
lusd5 = us5.Ranging(CM);
lusd6 = us6.Ranging(CM);
}

void requestEvent()
{
  String message;
  char buf[32];
  int id;
  message = "01,";
  message += lusd1;
  message += ",";
  message += lusd2;
  message += ",";
  message += lusd3;
  message += ",";
  message += lusd4;  
  message += ",";
  message += lusd5;
  message += ",";
  message += lusd6;
  //Serial.print(message.len);
  message.toCharArray(buf, 32);
  Wire.write(buf);
  Serial.println(buf);  
}

