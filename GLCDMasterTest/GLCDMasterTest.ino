// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.
#include <Wire.h>
#include <UTFT.h>

extern uint8_t SmallFont[];
extern uint8_t BigFont[];

int S1;
int S2;
int S3;
int S4;
int S5;
int S6;

unsigned char LSB;  // 1 byte
unsigned char MSB; // 1 byte

String bline;

UTFT myGLCD(ITDB32S,38,39,40,41);   // Remember to change the model parameter to suit your display module!


void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 0, 128);
  myGLCD.fillRect(0, 0, 319, 239);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(0, 0, 128);


}

void loop()
{
  String data;
  int SensorVal = 0;
  Wire.requestFrom(2, 32);    // request 6 bytes from slave device #2
  while(Wire.available())    // slave may send less than requested
  { 
    char c;
    c = Wire.read();
    if (isDigit(c)) 
    {
      data += (char)c; 
    }

    if (c == ',') 
    {
      // do something different for each value of currentColor:
      switch (SensorVal) 
      {
        case 0:    // 0 = red
          S1 = data.toInt();
          data = ""; 
          break;
      
        case 1:    // 1 = green:
          S1 = data.toInt();
          data = ""; 
          break;
 
        case 2:    // 1 = green:
          S2 = data.toInt();
          data = ""; 
          break;

        case 3:    // 1 = green:
          S3 = data.toInt();
          data = ""; 
          break;

        case 4:    // 1 = green:
          S4 = data.toInt();
          data = ""; 
          break;

        case 5:    // 1 = green:
          S5 = data.toInt();
          data = ""; 
          break;

        case 6:    // 1 = green:
          S6 = data.toInt();
          data = ""; 
          break;

      }
      SensorVal++;
    }
  }
//myGLCD.print(data, 0, 0);

 bline = "S1: ";
 bline += S1;
 bline += "    ";
 myGLCD.print(bline, 0, 12); 

 bline = "S2: ";
 bline += S2;
 bline += "    ";
 myGLCD.print(bline, 0, 24); 
 
 bline = "S3: ";
 bline += S3;
 bline += "    ";
 myGLCD.print(bline, 0, 36); 
 
 bline = "S4: ";
 bline += S4;
 bline += "    ";
 myGLCD.print(bline, 0, 48); 
 
 bline = "S5: ";
 bline += S5;
 bline += "    ";
 myGLCD.print(bline, 0, 60); 

 bline = "S6: ";
 bline += S6;
 bline += "    ";
 myGLCD.print(bline, 0, 72); 
}



/* 
     unsigned short somenumber;   // 2-bytes in MS Visual C++ 2010
      unsigned char LSB;  // 1 byte
      unsigned char MSB; // 1 byte

Code segment:

     // Obviously we can't send 320 to Arduino as a single byte since 1 byte can hold a maximum value of 255
     somenumber = 320;

     /* read least significant byte *
     LSB = somenumber & 0xff;

     /* read most significant byte *
     MSB = (somenumber >> 8) & 0xff;

    /* now we can send the two bytes MSB and LSB separately to Arduino's via serial 


=========== ARDUINO CODE FOR RECEIVING ===========


Declarations:

  unsigned char MSB = 0;  // 1 byte in Arduino
  unsigned char LSB = 0;  // 1 byte  in Arduino
  unsigned int MSBLSB = 0;  // 2 bytes in Arduino

Code segment:

   if (Serial.available() >= 2)
   {
     MSB = Serial.read();
     LSB = Serial.read();
     MSBLSB=word(MSB, LSB);
   }

  // Now MSBLSB = 320;
*/
