// Test of simulatnaeous use of
//	MMA8452Q accelerometer
//	MAG3110 magnetometer as a compass
// Mon Jan 30 14:50:56 PST 2012 Kevin Karplus

// 3 Feb 2012 Kevin Karplus
//  Fixed calibration bug for meagnetometer (forgot to discard first read,
//    which was not RAW).
// 18 Feb 2012 Kevin Karplus
//  Fixed typo in pi (introducing degrees_per_radian macro)

/*
#include <wire.h>
// using I^2C interface, written by Kevin Karplus, rather than 
//	the standard Arduino Wire library.

//	Both the accelerometer and the magnetometer are 3.3v parts,
//	so only 4 wires are needed: 3.3v, GND, SDA, SCL
//Note:  SDA= analog pin 4	SCL=analog pin 5 on Arduino

#define degrees_per_radian  (180./3.14159265358979)

uint8_t mag_calibrate=1;	  // turn on during calibration
uint8_t print_heading_on=0;	// turn on to print out each heading

// minimum and maximum values seen during calibration time
int16_t mag_low_x, mag_high_x, mag_low_y, mag_high_y, mag_low_z, mag_high_z;

uint16_t mag_num_calib=0;  // number of readings when calibrating

// scale factors for heading
float mag_x_scale=1.853, mag_y_scale=1.91, mag_z_scale=100; 
// offsets for non-RAW mode
int16_t mag_x_offset=3720, mag_y_offset=-2557, mag_z_offset=-245;  


const uint8_t acc_scale = 2;	// Sets full-acc_scale range to +/-2, 4, or 8g. Used to calc real g values.

/* Set the output data rate below. Value should be between 0 and 7*/
/*
const uint8_t acc_data_rate = 0;  // 0=800Hz, 1=400, 2=200, 3=100, 4=50, 5=12.5, 6=6.25, 7=1.56

uint8_t print_pitch_on=0;     // turn on to print out each pitch
int16_t acc_x_offset=0, acc_y_offset=0, acc_z_offset=0;  // offsets in same range as readings on 2g setting



void print_help(void)
{    Serial.println(F("type c to calibrate, q to turn off printing, d to dump registers, ? for help"));
    Serial.println(F("  Magnetometer commands:"));
    Serial.println(F("    h to print headings, t for temperature, a to average 10 readings,"));
    Serial.println(F("  Accelerometer commands:"));
    Serial.println(F("    p to print pitch and roll, s for self-test"));
}



// This code tests using a magnetometer (Frescale MAG_3110) as a compass.
// The main thing that is needed is to figure out the offsets needed to center
// the x and y scales.

// The code assumes that the z-axis is straight up and doesn't affect
// the heading.  If some other axis is vertical, the code will need
// modification for tilt correction.

// The offset values from one run are	3720  -2550  -242
// The scaling factors are   1.835E-3 1.996E-3	21.277E-3  (The z-one is bogus, as axis not changed.)

// Another run had	  3721	-2563  -247
// with scaling		   1.835E-3  1.890E-3  15152E-3

// Even with OVERSAMPLE4, the noise seems to be about +- 2 degrees.


// I2C 7-bit address of the magnetometer
#define MAG_3110_I2C  0x0E

// registers on the magnetometer
#define MAG_3110_DR_STATUS 0x00

// add 1 for LSB
#define MAG_3110_OUT_X_MSB 0x01
#define MAG_3110_OUT_Y_MSB 0x03
#define MAG_3110_OUT_Z_MSB 0x05
#define MAG_3110_WHO_AM_I  0x07

// add 1 for LSB  // user offset
#define MAG_3110_OFF_X_MSB 0x09
#define MAG_3110_OFF_Y_MSB 0x0B
#define MAG_3110_OFF_Z_MSB 0x0D

// read for temp in degrees c (int_8)
#define MAG_3110_DIE_TEMP 0x0F

#define MAG_3110_CTRL_REG1 0x10
#define MAG_3110_CTRL_REG2 0x11


// what should WHO_AM_I return?
#define MAG_3110_WHO_AM_I_VALUE 0xC4


// Fields in registers
// CTRL_REG1: dr2,dr1,dr0  os1,os0  fr tm ac

// Sampling rate from 80Hz down to 0.625Hz
#define MAG_3110_SAMPLE80 0
#define MAG_3110_SAMPLE40 0x20 
#define MAG_3110_SAMPLE20 0x40 
#define MAG_3110_SAMPLE10 0x60 
#define MAG_3110_SAMPLE5 0x80 
#define MAG_3110_SAMPLE2_5 0xA0
#define MAG_3110_SAMPLE1_25 0xC0
#define MAG_3110_SAMPLE0_625 0xE0

// How many samples to average (lowers data rate)
#define MAG_3110_OVERSAMPLE1 0
#define MAG_3110_OVERSAMPLE2 0x08
#define MAG_3110_OVERSAMPLE3 0x10
#define MAG_3110_OVERSAMPLE4 0x18

// read only 1 byte per axis
#define MAG_3110_FASTREAD 0x04
// do one measurement (even if in standby mode)
#define MAG_3110_TRIGGER 0x02
// put in active mode
#define MAG_3110_ACTIVE 0x01  

// CTRL_REG2: AUTO_MRST_EN  _ RAW MAG_RST _ _ _ _ _
// reset sensor after each reading
#define MAG_3110_AUTO_MRST_EN 0x80
// don't subtract user offsets
#define MAG_3110_RAW 0x20 
// reset magnetic sensor after too-large field
#define MAG_3110_MAG_RST 0x10 

// DR_STATUS Register ZYXOW ZOW YOW XOW ZYXDR ZDR YDR XDR
#define MAG_3110_ZYXDR	0x08


#define mag_write_reg(r,v)   (i2cWriteRegister(MAG_3110_I2C,r,v))
#define mag_read_reg(r)      (i2cReadRegister(MAG_3110_I2C,r))




inline uint8_t mag_data_ready(void)
{   return mag_read_reg(MAG_3110_DR_STATUS) & MAG_3110_ZYXDR;
}

void mag_read_xyz(int16_t&x, int16_t&y, int16_t&z)
{
    while (!mag_data_ready()) {} // wait for new set of data
    
    static uint8_t data[6];
    i2cReadRegisters(MAG_3110_I2C, MAG_3110_OUT_X_MSB, 6, data);
    x = (data[0]<<8) + data[1];
    y = (data[2]<<8) + data[3];
    z = (data[4]<<8) + data[5];
}


void mag_set_offsets(void)
{  
    static uint8_t data[6];
     
    data[0]=mag_x_offset>>7;    data[1]=(mag_x_offset<<1)& 0xFF;
    data[2]=mag_y_offset>>7;    data[3]=(mag_y_offset<<1)& 0xFF;
    data[4]=mag_z_offset>>7;    data[5]=(mag_z_offset<<1)& 0xFF;
     
    i2cWriteRegisters(MAG_3110_I2C, MAG_3110_OFF_X_MSB, 6, data);
}


void start_mag_calibrate(void)
{
    mag_calibrate=1;
    Serial.println(F("Calibrating---change orientation in full circle.  Type 'r' to run"));
    mag_write_reg(MAG_3110_CTRL_REG2, mag_read_reg(MAG_3110_CTRL_REG2)| MAG_3110_RAW);
    mag_low_x=32767; mag_high_x= 0x8000;
    mag_low_y=32767; mag_high_y= 0x8000;
    mag_low_z=32767; mag_high_z= 0x8000;
    mag_x_scale=1; mag_y_scale=1; mag_z_scale=1;
    mag_num_calib=0;
    int x,y,z;
    mag_read_xyz(x,y,z);  // discard a read from magnetometer (not RAW)
}

void stop_mag_calibrate(void)
{    mag_calibrate=0;
     // set the offsets to the middle of the x,y,z range
     Serial.println(F("Calibration done:"));

     mag_x_offset = (mag_low_x+mag_high_x)/2;
     Serial.print(F(" mag_low_x="));Serial.print(mag_low_x);
     Serial.print(F(" mag_high_x="));Serial.print(mag_high_x);
     Serial.print(F(" x_off="));Serial.println(mag_x_offset);
     mag_x_scale = 1.0/(mag_high_x-mag_low_x);

     mag_y_offset = (mag_low_y+mag_high_y)/2;
     Serial.print(F(" mag_low_y="));Serial.print(mag_low_y);
     Serial.print(F(" mag_high_y="));Serial.print(mag_high_y);
     Serial.print(F(" y_off="));Serial.println(mag_y_offset);
     mag_y_scale = 1.0/(mag_high_y-mag_low_y);

     mag_z_offset = (mag_low_z+mag_high_z)/2;
     Serial.print(F(" mag_low_z="));Serial.print(mag_low_z);
     Serial.print(F(" mag_high_z="));Serial.print(mag_high_z);
     Serial.print(F(" z_off="));Serial.println(mag_z_offset);
     mag_z_scale = 1.0/(mag_high_z-mag_low_z);

     Serial.println();
     Serial.print(F("  mag_x_scale="));	 Serial.print(mag_x_scale*10000);
     Serial.print(F("E-4 mag_y_scale="));   Serial.print(mag_y_scale*10000);
     Serial.print(F("E-4 mag_z_scale="));   Serial.print(mag_z_scale*10000);
     Serial.println(F("E-4"));

     Serial.print(F("Number(readings)="));
     Serial.println(mag_num_calib);

     mag_set_offsets();
     // stop using raw mode
    mag_write_reg(MAG_3110_CTRL_REG2, mag_read_reg(MAG_3110_CTRL_REG2) &~ MAG_3110_RAW);
    int x,y,z;
    mag_read_xyz(x,y,z);  // discard a read from magnetometer (was RAW)
    print_help();
}


void print_heading(int16_t x, int16_t y, int16_t z)
{     Serial.print(degrees_per_radian * atan2(-y*mag_y_scale,x*mag_x_scale) );
        Serial.print(F(" degrees E of N"));
        Serial.print(F(" x=")); Serial.print(x);
        Serial.print(F(" y=")); Serial.print(y);
        Serial.print(F(" z=")); Serial.print(z);
        Serial.println();
}

byte mag_check_who_am_i(void)
{   uint8_t who = mag_read_reg(MAG_3110_WHO_AM_I);
    
    if (who!=MAG_3110_WHO_AM_I_VALUE)
    {   Serial.print(F("Hey, this isn't a MAG_3110, its WHO_AM_I is 0x"));
    	Serial.println(who,HEX);
	return 0;
    }
    return 1;
}

void mag_setup(void)
{    
    while(!mag_check_who_am_i()) 
    {	// loop forever on wrong device
	delay(50);
    } 
    
    mag_write_reg(MAG_3110_CTRL_REG2, MAG_3110_AUTO_MRST_EN);
    mag_write_reg(MAG_3110_CTRL_REG1, MAG_3110_SAMPLE80+MAG_3110_OVERSAMPLE1+MAG_3110_ACTIVE);

    
    
    mag_set_offsets();
}




// Settings for accelerometer

uint8_t MMA8452Q_ADDRESS = 0x1D;	
// Breakout board defaults to 1, set to 0x1C if SA0 jumper is set

// Some register names
#define MMA8452Q_STATUS		(0x00)
#define MMA8452Q_OUT_X_MSB	(0x01)
#define MMA8452Q_XYZ_DATA_CFG	(0x0E)
#define MMA8452Q_OFF_X	(0x2F)
#define MMA8452Q_OFF_Y	(0x30)
#define MMA8452Q_OFF_Z	(0x31)
#define MMA8452Q_CTRL_REG1	(0x2A)
#define MMA8452Q_CTRL_REG2	(0x2B)
#define MMA8452Q_CTRL_REG3	(0x2C)
#define MMA8452Q_CTRL_REG4	(0x2D)
#define MMA8452Q_CTRL_REG5	(0x2E)
#define MMA8452Q_WHO_AM_I	(0x0D)

#define MMA8452Q_WHO_AM_I_VALUE	(0x2A)

#define MMA8452Q_ZYXDR		(0x80)	// data ready status bit

// What is 1 g on this scale, as an int
#define ONE_G  (0x2000*acc_scale)


#define acc_write_reg(r,v)   (i2cWriteRegister(MMA8452Q_ADDRESS,r,v))
#define acc_read_reg(r)      (i2cReadRegister(MMA8452Q_ADDRESS,r))


// Sets the MMA8452 to standby mode, which is needed to change most registers.
void acc_standby(void)
{
  acc_write_reg(MMA8452Q_CTRL_REG1, acc_read_reg(MMA8452Q_CTRL_REG1) & ~(0x01));
}

// Sets the MMA8452 to active mode, which is needed to output data 
void acc_active(void)
{
  acc_write_reg(MMA8452Q_CTRL_REG1, acc_read_reg(MMA8452Q_CTRL_REG1) | 0x01);
}

boolean acc_data_ready(void)
{    return acc_read_reg(MMA8452Q_STATUS) & MMA8452Q_ZYXDR;
}


byte acc_check_who_am_i(void)
{   uint8_t who = acc_read_reg(MMA8452Q_WHO_AM_I);
    
    if (who!=MMA8452Q_WHO_AM_I_VALUE)
    {   Serial.print(F("Hey, this isn't a MMA8452Q, its WHO_AM_I is 0x"));
    	Serial.println(who,HEX);
	return 0;
    }
    return 1;
}


// Initialize the MMA8452 registers
//   See the many application notes for more info on setting
//   all of these registers:
//   http://www.freeacc_scale.com/webapp/sps/site/prod_summary.jsp?code=MMA8452Q
void acc_setup(uint8_t fsr, uint8_t acc_data_rate)
{
    while (! acc_check_who_am_i())
    {   MMA8452Q_ADDRESS ^=1 ;		// try the other SA0 jumper setting
    	delay(50);	
    }
  
  acc_standby();  // Must be in standby to change registers

  const uint8_t registers1_5[] = {
  	0x04,	//LNOISE
	0x02,	// HIGH-RESOLUTION
  	0x02, // Active-high push-pull interrupt line
	0x01, // DRDY interrupt enabled
	0x01};// DRDY on INT1
  	
  i2cWriteRegisters(MMA8452Q_ADDRESS,MMA8452Q_CTRL_REG1,(uint8_t)5, registers1_5);

  // Set up the full acc_scale range to 2, 4, or 8g. 
  switch(fsr)
  {   case 8:
	  acc_write_reg(MMA8452Q_CTRL_REG1, 0x0);   // turn off LNOISE
      	  // and fall through to set range
      case 2: case 4:
	  acc_write_reg(MMA8452Q_XYZ_DATA_CFG, fsr >> 2);
	  break;
      default:
	  acc_write_reg(MMA8452Q_XYZ_DATA_CFG, 0);  // default to 2g
  }

  
  // Set up the 3 data rate bits, from 0 to 7
  if (acc_data_rate <= 7)
  {   acc_write_reg(MMA8452Q_CTRL_REG1, 
  		(acc_read_reg(MMA8452Q_CTRL_REG1) & ~0x38) 
		  | (acc_data_rate << 3));
  }

  acc_active();  // Set to active to start reading
}

void acc_read_xyz(int16_t&x, int16_t&y, int16_t&z)
{
  while (!acc_data_ready()) {}
  static uint8_t data[6];
  i2cReadRegisters(MMA8452Q_ADDRESS, MMA8452Q_OUT_X_MSB, 6, data);
  x = (data[0]<<8) + data[1];
  y = (data[2]<<8) + data[3];
  z = (data[4]<<8) + data[5];
}

void acc_set_offsets(void)
{
   acc_write_reg( MMA8452Q_OFF_X, acc_x_offset>>5);
   acc_write_reg( MMA8452Q_OFF_Y, acc_y_offset>>5);
   acc_write_reg( MMA8452Q_OFF_Z, acc_z_offset>>5);
   Serial.println(F("offsets set"));
}

void print_pitch_and_roll(int16_t x, int16_t y, int16_t z)
{
      Serial.print(F("pitch="));
      Serial.print(degrees_per_radian * atan2(x,z) );
      Serial.print(F(" degrees roll="));
      Serial.print(degrees_per_radian * atan2(y,z) );
      Serial.print(F(" x=")); Serial.print(x/(float)ONE_G,3);
      Serial.print(F(" y=")); Serial.print(y/(float)ONE_G,3);
      Serial.print(F(" z=")); Serial.print(z/(float)ONE_G,3);
      Serial.println();
}

void acc_calibrate(void)
{  // assumes the z-axis is supposed to be up
   acc_read_xyz(acc_x_offset, acc_y_offset,acc_z_offset);
   acc_z_offset -= ONE_G;
   acc_set_offsets();
   Serial.print(F("Accelerometer calibration done:"));
   Serial.print(F(" x_off=")); Serial.print(acc_x_offset/(float)ONE_G,3);
   Serial.print(F(" g y_off=")); Serial.print(acc_y_offset/(float)ONE_G,3);
   Serial.print(F(" g z_off=")); Serial.print(acc_z_offset/(float)ONE_G,3);
   Serial.println(F(" g"));
}

void acc_self_test(void)
{
  int16_t x,y,z;
  int16_t x_test,y_test,z_test; 
  const uint8_t SELF_TEST = 0x80;
  acc_read_xyz(x,y,z);
  acc_standby();
  acc_write_reg(MMA8452Q_CTRL_REG2, acc_read_reg(MMA8452Q_CTRL_REG2)|SELF_TEST);  
  acc_active();

  acc_read_xyz(x_test,y_test,z_test);
  Serial.print(F("Test difference x="));
  Serial.print(x_test-x);
  Serial.print(F(" y="));
  Serial.print(y_test-y);
  Serial.print(F(" z="));
  Serial.println(z_test-z);
  acc_standby();
  acc_write_reg(MMA8452Q_CTRL_REG2, acc_read_reg(MMA8452Q_CTRL_REG2) & ~SELF_TEST);  
  acc_active();
}


void setup(void)
{
    Serial.begin(115200);

    i2cInit();
    i2cSetBitrate(40);  // try 40kHz
    
    mag_setup();
    acc_setup(acc_scale, acc_data_rate);

    // signal to laptop that communication can start
    Serial.println(F("Arduino ready"));  

    print_heading_on=0;
    print_pitch_on=0;
    mag_calibrate=0;
    print_help();

}

void loop(void)
{
    int mag_x,mag_y,mag_z;
    int8_t temperature;
    int acc_x, acc_y, acc_z;
    
    if (Serial.available())
    {   switch(Serial.read())
        {
	  case '?':
	      print_help();
	      break;
	  case 'c':
	    acc_calibrate();
	    start_mag_calibrate();
	    break;
	 case 'r':
	    stop_mag_calibrate();
	    break;
	 case 'h':
	    Serial.println(F("Printing heading"));
	    print_heading_on=1;
	    break;
        case 'p':
            Serial.println(F("Printing pitch and roll"));
            print_pitch_on=1;
	    break;
	 case 'q':
	    Serial.println(F("Quiet mode"));
	    print_heading_on=0;
            print_pitch_on=0;
	    break;
	 case 's':
	    acc_self_test();
	    break;
	 case 't':
	    temperature = mag_read_reg(MAG_3110_DIE_TEMP);
	    Serial.print(F("Temperature="));
	    Serial.print(temperature);
	    Serial.println(F(" degrees C"));
	    break;
	 case 'a':
	   Serial.print(F("Summing 10 compass readings: "));
	   {   int ax,ay,az;
               mag_x=0; mag_y=0; mag_z=0;
	       for(int i=1; i<10; i++)
	       {   mag_read_xyz(ax,ay,az);
		   mag_x+=ax; mag_y+=ay; mag_z+=az;
	       }
	   }
	   print_heading(mag_x,mag_y,mag_z);
	   break;
	 case 'd':
	   Serial.println(F("Dumping MAG3110 registers:"));
	   for(int i=0; i< 0x12; i++)
	   {   Serial.print(i,HEX);
	       Serial.print(F(": 0x"));
	       Serial.println(mag_read_reg(i),HEX);
	       delay(2);
	   }
	   Serial.println(F("Dumping MMA8452Q registers:"));
	   for(int i=0; i< 0x31; i++)
	   {   Serial.print(i,HEX);
	       Serial.print(F(": 0x"));
	       Serial.println(acc_read_reg(i),HEX);
	       delay(2);
	   }
	   break;
      }
    }

    if (mag_data_ready())
    {   mag_read_xyz(mag_x,mag_y,mag_z);

	if (mag_calibrate)
	{  // record the lowest and highest values during calibration
           mag_num_calib++;
	   if (mag_x<mag_low_x) mag_low_x=mag_x;
	   if (mag_x>mag_high_x) mag_high_x=mag_x;
	   if (mag_y<mag_low_y) mag_low_y=mag_y;
	   if (mag_y>mag_high_y) mag_high_y=mag_y;
	   if (mag_z<mag_low_z) mag_low_z=mag_z;
	   if (mag_z>mag_high_z) mag_high_z=mag_z;
	}
	if (print_heading_on) print_heading(mag_x,mag_y,mag_z);
    }
    
    if (acc_data_ready())
    {   acc_read_xyz(acc_x,acc_y,acc_z);
      	if (print_pitch_on)
	{   print_pitch_and_roll(acc_x,acc_y,acc_z);
	}
    }
}
*/
