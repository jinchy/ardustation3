void date()
{
  RTC.getTime();

  if (RTC.day < 10)                    // correct date if necessary
  {
    strcpy(bline, P("0"));
	itoa(RTC.day, cFloat, 10);
    strcat(bline, cFloat);
  }

  else
  {
	itoa(RTC.day, cFloat, 10);
    strcpy(bline, cFloat);
  }
  
  strcat(bline, P("/"));

  if (RTC.month < 10)                   // correct month if necessary
  {
    strcat(bline, P("0"));
    itoa(RTC.month, cFloat, 10);
	strcat(bline, cFloat);
  }

  else
  {
	itoa(RTC.month, cFloat, 10);
	strcat(bline, cFloat);
  }

  strcat(bline, P("/"));
  itoa(RTC.year, cFloat, 10);
  strcat(bline, cFloat);
}

void lts()
{
	  RTC.getTime();

  if (RTC.day < 10)                    // correct date if necessary
  {
    strcpy(bline, P("0"));
	itoa(RTC.day, cFloat, 10);
    strcat(bline, cFloat);
  }

  else
  {
	itoa(RTC.day, cFloat, 10);
    strcpy(bline, cFloat);
  }
  
  strcat(bline, P("/"));

  if (RTC.month < 10)                   // correct month if necessary
  {
    strcat(bline, P("0"));
    itoa(RTC.month, cFloat, 10);
	strcat(bline, cFloat);
  }

  else
  {
	itoa(RTC.month, cFloat, 10);
	strcat(bline, cFloat);
  }

  strcat(bline, P("/"));
  itoa(RTC.year, cFloat, 10);
  strcat(bline, cFloat);

  strcat(bline, P("  "));
  itoa(RTC.hour, cFloat, 10);
  strcat(bline, cFloat);
  strcat(bline, P(":"));
  
  itoa(RTC.minute, cFloat, 10);
  strcat(bline, cFloat);
  strcat(bline, P(":"));
  
  itoa(RTC.second, cFloat, 10);
  strcat(bline, cFloat);
  strcat(bline, P("|    "));
}

void fts()
{
	  RTC.getTime();

  if (RTC.day < 10)                    // correct date if necessary
  {
    strcpy(bline, P("0"));
	itoa(RTC.day, cFloat, 10);
    strcat(bline, cFloat);
  }

  else
  {
	itoa(RTC.day, cFloat, 10);
    strcpy(bline, cFloat);
  }
  
  if (RTC.month < 10)                   // correct month if necessary
  {
    strcat(bline, P("0"));
    itoa(RTC.month, cFloat, 10);
	strcat(bline, cFloat);
  }

  else
  {
	itoa(RTC.month, cFloat, 10);
	strcat(bline, cFloat);
  }

  itoa(RTC.year, cFloat, 10);
  strcat(bline, cFloat);

  itoa(RTC.hour, cFloat, 10);
  strcat(bline, cFloat);
  
  itoa(RTC.minute, cFloat, 10);
  strcat(bline, cFloat);
  
  itoa(RTC.second, cFloat, 10);
  strcat(bline, cFloat);
}

void SetFromGPS()
{
	int year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned char hundredths;
	unsigned long age;
	
	if(beLog) eLog.println(P("Setting time from GPS"));

	if(feedgps())
	{
		gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
	
		itoa(year, cFloat, 10);
		strcpy(bline, P("Year: "));
		strcat(bline, cFloat);

		itoa(month, cFloat, 10);
		strcat(bline, P("   Month: "));
		strcat(bline, cFloat);

		itoa(day, cFloat, 10);
		strcat(bline, P("   Day: "));
		strcat(bline, cFloat);

		itoa(hour, cFloat, 10);
		strcat(bline, P("   Hour: "));
		strcat(bline, cFloat);

		itoa(minute, cFloat, 10);
		strcat(bline, P("   Minute: "));
		strcat(bline, cFloat);

		itoa(second, cFloat, 10);
		strcat(bline, P("   Second: "));
		strcat(bline, cFloat);
		Serial.println(bline);
		if(beLog) eLog.println(bline);
	
		if(day != 0)
		{
			RTC.stopClock();
			RTC.fillByYMD(year,month,day);
			RTC.fillByHMS(hour,minute,second);
			RTC.setTime();
			TimeIsSet = 0xaa55;
			RTC.setRAM(54, (uint8_t *)&TimeIsSet, sizeof(uint16_t));
			RTC.startClock();
			if(beLog) eLog.println(P("Time Set"));
			Serial.println(P("Time Set"));
			TimeSet = true;
		}
		else
		{
			if(beLog) eLog.println(P("Time not set; something funky with GPS time"));
			Serial.println(P("Time not set; something funky with GPS time"));
			TimeSet = false;
		}
	}
}

void dateTime(uint16_t* date, uint16_t* time) 
{	
  RTC.getTime();
  *date = FAT_DATE(RTC.year, RTC.month, RTC.day);
  *time = FAT_TIME(RTC.hour, RTC.minute, RTC.second);
}