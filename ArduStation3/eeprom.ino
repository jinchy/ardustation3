void EEPROM_writeDouble(int ee, double value)
{
	ee += 10; //reserve 10 addresses for internal settings
    byte* p = (byte*)(void*)&value;
    for (int i = 0; i < sizeof(value); i++)
        EEPROM.write(ee++, *p++);
}

double EEPROM_readDouble(int ee)
{
	ee += 10; //first 10 addresses reserved for internal settings
    double value = 0.0;
    byte* p = (byte*)(void*)&value;
    for (int i = 0; i < sizeof(value); i++)
        *p++ = EEPROM.read(ee++);
    return value;
}

int GetLogID()
{
	int id;
	id = EEPROM.read(1);
	id += 1;
	if(id > 254) id = 0;
	EEPROM.write(1, id);
	return id;
}

// 00000000b
// 1 bit 1: Factory reset
// 2 bit 2: Serial Pass Thru
// 4 bit 3:
// 8 bit 4:
// 16 bit 5:
// 32 bit 6:
// 64 bit 7:
// 128 bit 8:

bool SPT()
{
	int fr;
	fr = EEPROM.read(0);
	if((fr & 2) == 2)
	{
		EEPROM.write(0, (fr ^ 2));
		return true;
	}
	return false;
}

void SetSPT()
{
	int fr;
	fr = EEPROM.read(0);
	EEPROM.write(0, (fr | 2));
}

void FactReset()
{
	int fr;
	fr = EEPROM.read(0);
	if(fr & 1 != 0)
	{
		EEPROM.write(0, 1);
		EEPROM.write(1, 0);
	}
}

bool tLogging()
{
	int fr;
	fr = EEPROM.read(0);
	if((fr & 4) == 4)
	{
		return true;
	}
	return false;
}

void tLogging(bool on)
{
	int fr;
	fr = EEPROM.read(0);
	if(!on)
	{
		EEPROM.write(0, (fr ^ 4));
	}
	else
	{
		EEPROM.write(0, (fr | 4));
	}

}

bool eLogging()
{
	int fr;
	fr = EEPROM.read(0);
	if((fr & 4) == 4)
	{
		return true;
	}
	return false;
}

void eLogging(bool on)
{
	int fr;
	fr = EEPROM.read(0);
	if(!on)
	{
		EEPROM.write(0, (fr ^ 4));
	}
	else
	{
		EEPROM.write(0, (fr | 4));
	}
}