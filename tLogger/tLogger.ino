/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 
 */
 
#include <SD.h>

File myFile;
int led = 13;  

void setup()
{
 // Open serial communications and wait for port to open:
  Serial1.begin(57600);
   while (!Serial) {
                    }
                
  //Serial.print("Initializing SD card...");
   pinMode(10, OUTPUT);
   pinMode(led, OUTPUT);
  if (!SD.begin(4)) {
    return;
  }
}

void loop()
{
        
        myFile = SD.open("xbee.tlog", FILE_WRITE);
	while (Serial1.available()) 
        {
    	  digitalWrite(led, HIGH);
          myFile.write(Serial1.read());
          digitalWrite(led, LOW);
        }
        myFile.close();
        
 }


