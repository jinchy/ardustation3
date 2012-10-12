
//------------------------------------------------------------------------------
// write cached block to the card
uint8_t writeCache(uint32_t lbn) {
  return card.writeBlock(lbn, cache.data);
}

//------------------------------------------------------------------------------
// initialize appropriate sizes for SD capacity
int initSizes() 
{
  if (cardCapacityMB <= 6) 
  {
	  return 1;
//    sdError("Card is too small.");
  } 
  
  else if (cardCapacityMB <= 16) 
  {
    sectorsPerCluster = 2;
  }
  
  else if (cardCapacityMB <= 32) 
  {
    sectorsPerCluster = 4;
  }
  
  else if (cardCapacityMB <= 64) 
  {
    sectorsPerCluster = 8;
  }
  
  else if (cardCapacityMB <= 128)
  {
    sectorsPerCluster = 16;
  }
  
  else if (cardCapacityMB <= 1024) 
  {
    sectorsPerCluster = 32;
  }
  
  else if (cardCapacityMB <= 32768)
  {
    sectorsPerCluster = 64;
  }

  else 
  {
    // SDXC cards
    sectorsPerCluster = 128;
  }

  sectorsPerTrack = cardCapacityMB <= 256 ? 32 : 63;

  if (cardCapacityMB <= 16) 
  {
    numberOfHeads = 2;
  }
  
  else if (cardCapacityMB <= 32) 
  {
    numberOfHeads = 4;
  }
  
  else if (cardCapacityMB <= 128) 
  {
    numberOfHeads = 8;
  }
  
  else if (cardCapacityMB <= 504) 
  {
    numberOfHeads = 16;
  }
  
  else if (cardCapacityMB <= 1008)
  {
    numberOfHeads = 32;
  }
  
  else if (cardCapacityMB <= 2016) 
  {
    numberOfHeads = 64;
  }
  
  else if (cardCapacityMB <= 4032) 
  {
    numberOfHeads = 128;
  }
  
  else 
  {
    numberOfHeads = 255;
  }
}

//------------------------------------------------------------------------------
// zero cache and optionally set the sector signature
void clearCache(uint8_t addSig) 
{
  memset(&cache, 0, sizeof(cache));
  if (addSig) 
  {
    cache.mbr.mbrSig0 = BOOTSIG0;
    cache.mbr.mbrSig1 = BOOTSIG1;
  }
}

//------------------------------------------------------------------------------
// zero FAT and root dir area on SD
int clearFatDir(uint32_t bgn, uint32_t count) 
{
  clearCache(false);
  
  if (!card.writeStart(bgn, count)) 
  {
	return 1;
    //sdError("Clear FAT/DIR writeStart failed");
  }

  for (uint32_t i = 0; i < count; i++) 
  {
	//if ((i & 0XFF) == 0) cout << '.';
    if (!card.writeData(cache.data)) 
	{
		return 2;
		//sdError("Clear FAT/DIR writeData failed");
    }
  }

  if (!card.writeStop()) 
  {
	  return 3;
	  //sdError("Clear FAT/DIR writeStop failed");
  }
  return 0;
}
//------------------------------------------------------------------------------
// return cylinder number for a logical block number
uint16_t lbnToCylinder(uint32_t lbn) {
  return lbn / (numberOfHeads * sectorsPerTrack);
}
//------------------------------------------------------------------------------
// return head number for a logical block number
uint8_t lbnToHead(uint32_t lbn) {
  return (lbn % (numberOfHeads * sectorsPerTrack)) / sectorsPerTrack;
}
//------------------------------------------------------------------------------
// return sector number for a logical block number
uint8_t lbnToSector(uint32_t lbn) {
  return (lbn % sectorsPerTrack) + 1;
}
//------------------------------------------------------------------------------
// format and write the Master Boot Record
int writeMbr() {
  clearCache(true);
  part_t* p = cache.mbr.part;
  p->boot = 0;
  uint16_t c = lbnToCylinder(relSector);
  if (c > 1023)
	  {
		  return 1;
		  //sdError("MBR CHS");
	  }
  p->beginCylinderHigh = c >> 8;
  p->beginCylinderLow = c & 0XFF;
  p->beginHead = lbnToHead(relSector);
  p->beginSector = lbnToSector(relSector);
  p->type = partType;
  uint32_t endLbn = relSector + partSize - 1;
  c = lbnToCylinder(endLbn);
  
  if (c <= 1023) 
	{
		p->endCylinderHigh = c >> 8;
		p->endCylinderLow = c & 0XFF;
		p->endHead = lbnToHead(endLbn);
		p->endSector = lbnToSector(endLbn);
	} 
  else 
	{
		// Too big flag, c = 1023, h = 254, s = 63
		p->endCylinderHigh = 3;
		p->endCylinderLow = 255;
		p->endHead = 254;
		p->endSector = 63;
	}

  p->firstSector = relSector;
  p->totalSectors = partSize;
  if (!writeCache(0)) 
	  {
		  return 2;
		  //sdError("write MBR");
	  }
}

//------------------------------------------------------------------------------
// generate serial number from card size and micros since boot
uint32_t volSerialNumber() {
  return (cardSizeBlocks << 8) + micros();
}

//------------------------------------------------------------------------------
// format the SD as FAT16

int makeFat16() {
  uint32_t nc;
  for (dataStart = 2 * BU16;; dataStart += BU16) {
    nc = (cardSizeBlocks - dataStart)/sectorsPerCluster;
    fatSize = (nc + 2 + 255)/256;
    uint32_t r = BU16 + 1 + 2 * fatSize + 32;
    if (dataStart < r) continue;
    relSector = dataStart - r + BU16;
    break;
  }
  
  // check valid cluster count for FAT16 volume
  if (nc < 4085 || nc >= 65525) 
	  {
		  return 1;
		  //sdError("Bad cluster count");
	  }

  reservedSectors = 1;
  fatStart = relSector + reservedSectors;
  partSize = nc * sectorsPerCluster + 2 * fatSize + reservedSectors + 32;

  if (partSize < 32680) 
	{
	 partType = 0X01;
	} 
  
  else if (partSize < 65536) 
	{
	 partType = 0X04;
	}
  
  else 
	{
     partType = 0X06;
	}

  // write MBR
  writeMbr();
  clearCache(true);
  fat_boot_t* pb = &cache.fbs;
  pb->jump[0] = 0XEB;
  pb->jump[1] = 0X00;
  pb->jump[2] = 0X90;
  
  for (uint8_t i = 0; i < sizeof(pb->oemId); i++) 
  {
    pb->oemId[i] = ' ';
  }

  pb->bytesPerSector = 512;
  pb->sectorsPerCluster = sectorsPerCluster;
  pb->reservedSectorCount = reservedSectors;
  pb->fatCount = 2;
  pb->rootDirEntryCount = 512;
  pb->mediaType = 0XF8;
  pb->sectorsPerFat16 = fatSize;
  pb->sectorsPerTrack = sectorsPerTrack;
  pb->headCount = numberOfHeads;
  pb->hidddenSectors = relSector;
  pb->totalSectors32 = partSize;
  pb->driveNumber = 0X80;
  pb->bootSignature = EXTENDED_BOOT_SIG;
  pb->volumeSerialNumber = volSerialNumber();
  memcpy(pb->volumeLabel, noName, sizeof(pb->volumeLabel));
  memcpy(pb->fileSystemType, fat16str, sizeof(pb->fileSystemType));
  // write partition boot sector
  
  if (!writeCache(relSector)) 
  {
     return 2;
	 //sdError("FAT16 write PBS failed");
  }

  // clear FAT and root directory
  clearFatDir(fatStart, dataStart - fatStart);
  clearCache(false);
  cache.fat16[0] = 0XFFF8;
  cache.fat16[1] = 0XFFFF;
  // write first block of FAT and backup for reserved clusters
  if (!writeCache(fatStart) || !writeCache(fatStart + fatSize))
  {
	return 3;
    //sdError("FAT16 reserve failed");
  }
}

//------------------------------------------------------------------------------
// format the SD as FAT32

int makeFat32() 
{
  uint32_t nc;
  relSector = BU32;
  for (dataStart = 2 * BU32;; dataStart += BU32) 
  {
    nc = (cardSizeBlocks - dataStart)/sectorsPerCluster;
    fatSize = (nc + 2 + 127)/128;
    uint32_t r = relSector + 9 + 2 * fatSize;
    if (dataStart >= r) break;
  }

  // error if too few clusters in FAT32 volume
  if (nc < 65525) 
	  {
		  return 1;
		  //sdError("Bad cluster count");
	  }
  reservedSectors = dataStart - relSector - 2 * fatSize;
  fatStart = relSector + reservedSectors;
  partSize = nc * sectorsPerCluster + dataStart - relSector;
  // type depends on address of end sector
  // max CHS has lbn = 16450560 = 1024*255*63
  if ((relSector + partSize) <= 16450560) 
  {
    // FAT32
    partType = 0X0B;
  } else {
    // FAT32 with INT 13
    partType = 0X0C;
  }
  
  writeMbr();
  clearCache(true);

  fat32_boot_t* pb = &cache.fbs32;
  pb->jump[0] = 0XEB;
  pb->jump[1] = 0X00;
  pb->jump[2] = 0X90;
  
  for (uint8_t i = 0; i < sizeof(pb->oemId); i++) 
  {
    pb->oemId[i] = ' ';
  }
  
  pb->bytesPerSector = 512;
  pb->sectorsPerCluster = sectorsPerCluster;
  pb->reservedSectorCount = reservedSectors;
  pb->fatCount = 2;
  pb->mediaType = 0XF8;
  pb->sectorsPerTrack = sectorsPerTrack;
  pb->headCount = numberOfHeads;
  pb->hidddenSectors = relSector;
  pb->totalSectors32 = partSize;
  pb->sectorsPerFat32 = fatSize;
  pb->fat32RootCluster = 2;
  pb->fat32FSInfo = 1;
  pb->fat32BackBootBlock = 6;
  pb->driveNumber = 0X80;
  pb->bootSignature = EXTENDED_BOOT_SIG;
  pb->volumeSerialNumber = volSerialNumber();
  memcpy(pb->volumeLabel, noName, sizeof(pb->volumeLabel));
  memcpy(pb->fileSystemType, fat32str, sizeof(pb->fileSystemType));
  // write partition boot sector and backup
  
  if (!writeCache(relSector) || !writeCache(relSector + 6)) 
  {
	  return 2;
	  //sdError("FAT32 write PBS failed");
  }
  clearCache(true);
  // write extra boot area and backup
  
  if (!writeCache(relSector + 2) || !writeCache(relSector + 8))
  {
    return 3;
	//sdError("FAT32 PBS ext failed");
  }

  fat32_fsinfo_t* pf = &cache.fsinfo;
  pf->leadSignature = FSINFO_LEAD_SIG;
  pf->structSignature = FSINFO_STRUCT_SIG;
  pf->freeCount = 0XFFFFFFFF;
  pf->nextFree = 0XFFFFFFFF;
  // write FSINFO sector and backup
  
  if (!writeCache(relSector + 1)|| !writeCache(relSector + 7)) 
  {
	  return 4;
	  //sdError("FAT32 FSINFO failed");
  }

  clearFatDir(fatStart, 2 * fatSize + sectorsPerCluster);
  clearCache(false);
  cache.fat32[0] = 0x0FFFFFF8;
  cache.fat32[1] = 0x0FFFFFFF;
  cache.fat32[2] = 0x0FFFFFFF;
  // write first block of FAT and backup for reserved clusters
  
  if (!writeCache(fatStart)|| !writeCache(fatStart + fatSize)) 
  {
      return 5;
	  //sdError("FAT32 reserve failed");
  }
  return 0;
}

//------------------------------------------------------------------------------
// flash erase all data
uint32_t const ERASE_SIZE = 262144L;

int eraseCard() {
  //cout << endl << pstr("Erasing\n");
  uint32_t firstBlock = 0;
  uint32_t lastBlock;
  uint16_t n = 0;

  do 
  {
    lastBlock = firstBlock + ERASE_SIZE - 1;
    if (lastBlock >= cardSizeBlocks) lastBlock = cardSizeBlocks - 1;

	if (!card.erase(firstBlock, lastBlock)) 
		{
			return 1;
			//sdError("erase failed");
		}
    //cout << '.';
    //if ((n++)%32 == 31) cout << endl;
    firstBlock += ERASE_SIZE;
  }
  while (firstBlock < cardSizeBlocks);
  //cout << endl;

  if (!card.readBlock(0, cache.data))
	  {
		  return 2;
		  //sdError("readBlock");
	  }

  //cout << hex << showbase << setfill('0') << internal;
  //cout << pstr("All data set to ") << setw(4) << int(cache.data[0]) << endl;
  //cout << dec << noshowbase << setfill(' ') << right;
  //cout << pstr("Erase done\n");
}
//------------------------------------------------------------------------------
int formatCard() 
{
//  cout << endl;
//  cout << pstr("Formatting\n");
  initSizes();
  if (card.type() != SD_CARD_TYPE_SDHC) 
  {
    //cout << pstr("FAT16\n");
    return makeFat16();
  } 
  else 
  {
    //cout << pstr("FAT32\n");
    return makeFat32();
  }
  //cout << pstr("Format done\n");
}

void beLogFlush()
{
	if(beLog) eLog.close();
	beLog = false;

	if (!sd.begin(chipSelect, SPI_FULL_SPEED))
			{
				beLog = false;
				btLog = false;
				bfile = false;
			}
		else
			{
				if (!eLog.open("ErrorLog.txt", O_RDWR | O_CREAT | O_AT_END)) 
				{
				}
				else
				{
					eLog.println();
					eLog.println("==============================================================");
					beLog = true;
				}
			}
}
