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
	EEPROM.write(1, id);
	return id;
}

// 00000000b
// 2 bit 1: Factory reset
// 4 bit 2: Serial Pass Thru
// 8 bit 3:
// 16 bit 4:
// 32 bit 5:
// 64 bit 6:
// 128 bit 7:
// 256 bit 8:

bool SPT()
{
  return false;
}
void FactReset()
{
	int fr;
	fr = EEPROM.read(0);
	if(fr & 2 != 0)
	{
		EEPROM.write(0, 0);
		EEPROM.write(1, 0);
	}
}