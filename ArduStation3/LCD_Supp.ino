void ThreeTune(char hdg[12], int addr)
{              
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
			   strcpy(bline, hdg);
			   strcat(bline, P(" Stabilisation"));
               myGLCD.print(bline, CENTER, 1);
               myGLCD.setFont(BigFont);
               myGLCD.setBackColor(0, 0, 128);
               
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 24, 319, 44);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Roll"), LEFT, 24);
               myGLCD.print (P("Start"), 110, 24);
               myGLCD.print (P("New"), 210, 24);
               
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.print(P("   P:"), LEFT, 44);
               myGLCD.print(P("   I:"), LEFT, 64);
               myGLCD.print(P("   D:"), LEFT, 84);
               myGLCD.print(P("IMax:"), LEFT, 104);
 
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 124, 319, 144);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Pitch"), LEFT, 124);
               
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.print(P("   P:"), LEFT, 144);
               myGLCD.print(P("   I:"), LEFT, 164);
               myGLCD.print(P("   D:"), LEFT, 184);
               myGLCD.print(P("IMax:"), LEFT, 204);

               int x;
               
               x = addr;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               strcpy(bline, P(" "));
               dtostrf(value, 4, 2, cFloat);
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 44);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               strcpy(bline, P(" "));
               dtostrf(value, 4, 2, cFloat);
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 64);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               strcpy(bline, P(" "));
               dtostrf(value, 4, 2, cFloat);
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 84);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               strcpy(bline, P(" "));
               dtostrf((value/100), 4, 2, cFloat);
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 104);
 
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               strcpy(bline, P(" "));
               dtostrf(value, 4, 2, cFloat);
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 144);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P(" "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 164);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P(" "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 184);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf((value/100), 4, 2, cFloat);
               strcpy(bline, P(" "));
               strcat(bline, cFloat);
               strcpy(bline, P("  "));
               myGLCD.print(bline, 85, 204);
               
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRoundRect(280, 20, 319, 239);
               
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(285, 20, 319, 100);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("UP"), 295, 55);
               
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRoundRect(285, 105, 319, 154);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("SND"), 292, 123); 
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(285, 159, 319, 239);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("DN"), 295, 195);  
               
               tuneP = 0.0;
               tuneI = 0.0;
               tuneD = 0.0;
               tuneIMax = 0.0;
               ley = 0;
               return;
}

void ThreeTuneR(int addr)
{              
  //int addr = 116;
  if(pSend)
  {
    int x = ley;
          switch(x)
            {
              case 0: 
                {
                  myGLCD.setColor(0, 255, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 184, (64 + (20 * (x+1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+2))), 184, (64 + (20 * (x+2))));
                  myGLCD.fillRect(179, (44 + (20 * (x+3))), 184, (64 + (20 * (x+3))));
                  break;
                }
                
              case 1:
                 {
                  myGLCD.setColor(0, 255, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+2))), 185, (64 + (20 * (x+2))));
                  break;
                 }
                 
              case 2:
                 {
                   myGLCD.setColor(0, 255, 0);
                   myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                   myGLCD.setColor(0, 0, 128);
                   myGLCD.fillRect(179, (44 + (20 * (x-2))), 185, (64 + (20 * (x-2))));
                   myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                   myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                   break; 
                 }
                 
              case 3:
                 {
                   myGLCD.setColor(0, 255, 0);
                   myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                   myGLCD.setColor(0, 0, 128);
                   myGLCD.fillRect(179, (44 + (20 * (x-3))), 185, (64 + (20 * (x-3))));
                   myGLCD.fillRect(179, (44 + (20 * (x-2))), 185, (64 + (20 * (x-2))));
                   myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                  break;
                 }
            }
    if(pot > 512)
        {
           //int x = ley;
           switch(x)
            {
              case 0: 
                {
                  value = (tuneP + (((pot-512)/100.0)/2));
                  break;
                }
                
              case 1:
                 {
                   value = (tuneI + (((pot-512)/100.0)/2));
                   break;
                 }
                 
              case 2:
                 {
                   value = (tuneD + (((pot-512)/100.0)/2));
                   break;
                 }
                 
              case 3:
                 {
                   value = (tuneIMax + ((pot-512)/10.0));
                   break;
                 }
            }
        }
        if(pot < 512)
        {
           //int x = ley;
           switch(x)
            {
              case 0:
               {
                 value = (tuneP - (((512-pot)/100.0)/2));
                 if(value <0) value = 0.0;
                 break;
               }
               
              case 1: 
               {
                 value = (tuneI - (((512-pot)/100.0)/2));
                 if(value <0) value = 0.0;
                 break;
               }
                
              case 2:
               {
                 value = (tuneD - (((512-pot)/100.0)/2));
                 if(value <0) value = 0.0;
                 break;
               }
               
              case 3:
               {
                 value = (tuneIMax - ((512-pot)/10.0));
                 if(value <0) value = 0.0;
                 break;
               }
            } 
        }     
    cmdSetParm((addr+x), value);
    cmdSetParm((addr+x+4), value);
    
    tuneP = 0.0;
    tuneI = 0.0;
    tuneD = 0.0;
    tuneIMax = 0.0;
    pSend = false;
  }
  
  else
  {
    if((tuneP == 0.0) && (tuneI == 0.0) && (tuneD == 0.0) && (tuneIMax == 0.0))
      {
        for(int x; x < 4; x++)
        {
          value = EEPROM_readDouble((addr + x)*4);
          
          switch(x)
           {
            case 0:
             {
               tuneP = value;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P("tune P "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               if(beLog) eLog.println(bline);
               break;
             }
             
            case 1:
             {
               tuneI = value;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P("tune I "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               if(beLog) eLog.println(bline);
               break;
             }
             
            case 2:
             {
               tuneD = value;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P("tune D "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
			   if(beLog) eLog.println(bline);
               break;
             }
             
            case 3:
             {
               tuneIMax = value;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P("Tune I Max "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               if(beLog) eLog.println(bline);
               break;
             }
           }
                   
           if(value > 65499.0) value = 65500.0;
           if(x != 3) dtostrf((value), 4, 2, cFloat);
           else dtostrf((value/100), 4, 2, cFloat);
           strcpy(bline, " ");
           strcat(bline, cFloat);
           myGLCD.setFont(BigFont);
           myGLCD.setBackColor(0, 0, 128);
           myGLCD.setColor(255, 255, 255);
           myGLCD.print(bline, 185, (44 + (20 * x)));
        }
      }
      
    else
      {
          int x = ley;
          switch(x)
            {
              case 0: 
                {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 184, (64 + (20 * (x+1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+2))), 184, (64 + (20 * (x+2))));
                  myGLCD.fillRect(179, (44 + (20 * (x+3))), 184, (64 + (20 * (x+3))));
                  break;
                }
                
              case 1:
                 {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+2))), 185, (64 + (20 * (x+2))));
                  break;
                 }
                 
              case 2:
                 {
                   myGLCD.setColor(255, 0, 0);
                   myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                   myGLCD.setColor(0, 0, 128);
                   myGLCD.fillRect(179, (44 + (20 * (x-2))), 185, (64 + (20 * (x-2))));
                   myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                   myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                   break; 
                 }
                 
              case 3:
                 {
                   myGLCD.setColor(255, 0, 0);
                   myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                   myGLCD.setColor(0, 0, 128);
                   myGLCD.fillRect(179, (44 + (20 * (x-3))), 185, (64 + (20 * (x-3))));
                   myGLCD.fillRect(179, (44 + (20 * (x-2))), 185, (64 + (20 * (x-2))));
                   myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                  break;
                 }
            }
       if(pot > 512)
        {
           //int x = ley;
           switch(x)
            {
              case 0: 
                {
                  value = (tuneP + (((pot-512)/100.0)/2));
                  break;
                }
                
              case 1:
                 {
                   value = (tuneI + (((pot-512)/100.0)/2));
                   break;
                 }
                 
              case 2:
                 {
                   value = (tuneD + (((pot-512)/100.0)/2));
                   break;
                 }
                 
              case 3:
                 {
                   value = (tuneIMax + ((pot-512)/10.0));
                   break;
                 }
            } 
            
            
            
           if(value > 65499.0) value = 65500.0;
           if(x != 3) dtostrf((value), 4, 2, cFloat);
           else dtostrf((value/100), 4, 2, cFloat);
           strcpy(bline, P(" "));
           strcat(bline, cFloat);
           myGLCD.setFont(BigFont);
           myGLCD.setBackColor(0, 0, 128);
           myGLCD.setColor(255, 255, 255);
           myGLCD.print(bline, 185, (44 + (20 * x)));
        }
        if(pot < 512)
        {
           //int x = ley;
           switch(x)
            {
              case 0:
               {
                 value = (tuneP - (((512-pot)/100.0)/2));
                 if(value <0) value = 0.0;
                 break;
               }
               
              case 1: 
               {
                 value = (tuneI - (((512-pot)/100.0)/2));
                 if(value <0) value = 0.0;
                 break;
               }
                
              case 2:
               {
                 value = (tuneD - (((512-pot)/100.0)/2));
                 if(value <0) value = 0.0;
                 break;
               }
               
              case 3:
               {
                 value = (tuneIMax - ((512-pot)/10.0));
                 if(value <0) value = 0.0;
                 break;
               }
            } 
            
           if(value > 65499.0) value = 65500.0;
           if(x != 3) dtostrf((value), 4, 2, cFloat);
           else dtostrf((value/100), 4, 2, cFloat);
           strcpy(bline, P(" "));
           strcat(bline, cFloat);
           myGLCD.setFont(BigFont);
           myGLCD.setBackColor(0, 0, 128);
           myGLCD.setColor(255, 255, 255);
           myGLCD.print(bline, 185, (44 + (20 * x)));
        }
      }
  }
 return;
}

void TwoTune(char hdg[12], int addr)
{              
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
			   strcpy(bline, hdg);
			   strcat(bline, P(" Stabilisation"));
               myGLCD.print(bline, CENTER, 1);
               myGLCD.setFont(BigFont);
               myGLCD.setBackColor(0, 0, 128);
               
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 24, 319, 44);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               //myGLCD.print(hdg, LEFT, 24);
               myGLCD.print (P("Start"), 110, 24);
               myGLCD.print (P("New"), 210, 24);
               
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.print(P("   P:"), LEFT, 44);
               myGLCD.print(P("   I:"), LEFT, 64);
               myGLCD.print(P("IMax:"), LEFT, 84);

               int x;
               
               x = addr;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P(" "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 44);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P(" "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 64);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf((value/100), 4, 2, cFloat);
               strcpy(bline, P(" "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               myGLCD.print(bline, 85, 84);
 
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRoundRect(280, 20, 319, 239);
               
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(285, 20, 319, 100);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("UP"), 295, 55);
               
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRoundRect(285, 105, 319, 154);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("SND"), 292, 123); 
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(285, 159, 319, 239);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("DN"), 295, 195);  
               
               tuneP = 0.0;
               tuneI = 0.0;
               tuneD = 0.0;
               tuneIMax = 0.0;
               ley = 0;
               return;
}

void TwoTuneR(int addr)
{              
  float tmin = 0.0;
  float tmax;
   if(pSend)
  {
    int x = ley;
          switch(x)
            {
              case 0: 
                {
                  myGLCD.setColor(0, 255, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 184, (64 + (20 * (x+1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+2))), 184, (64 + (20 * (x+2))));
                  myGLCD.fillRect(179, (44 + (20 * (x+3))), 184, (64 + (20 * (x+3))));
                  break;
                }
                
              case 1:
                 {
                  myGLCD.setColor(0, 255, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+2))), 185, (64 + (20 * (x+2))));
                  break;
                 }
                 
              case 2:
                 {
                   myGLCD.setColor(0, 255, 0);
                   myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                   myGLCD.setColor(0, 0, 128);
                   myGLCD.fillRect(179, (44 + (20 * (x-2))), 185, (64 + (20 * (x-2))));
                   myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                   myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                   break; 
                 }
                 
            }
    //if(pot > 512)
    //    {
           //int x = ley;
           switch(x)
            {
              case 0: 
                {
				  tmax = (EEPROM_readDouble((addr + x)*4)*2);
				  if(tmax < 1) tmax = 1.0;
                  value = ((tmin + (tmax - tmin))*(pot/1024.0));
                  break;
                }
                
              case 1:
                {
				  tmax = (EEPROM_readDouble((addr + x)*4)*2);
				  if(tmax < 1) tmax = 1.0;  
                  value = ((tmin + (tmax - tmin))*(pot/1024.0));
                  break;
                }
                    
              case 2:
                {
				  tmax = (EEPROM_readDouble((addr + x)*4)*2);
				  if(tmax < 1 ) tmax = 1.0;
                  value = ((tuneIMax*2)*(pot/1024.0));
                  break;
                }
            }
        
        //if(pot < 512)
        //{
        //   //int x = ley;
        //   switch(x)
        //    {
        //      case 0:
        //       {
        //         value = (tuneP - (((512-pot)/1000.0)/6));
        //         if(value <0) value = 0.0;
        //         break;
        //       }
        //       
        //      case 1: 
        //       {
        //         value = (tuneI - (((512-pot)/1000.0)/6));
        //         if(value <0) value = 0.0;
        //         break;
        //       }
        //        
        //      case 2:
        //       {
        //         value = (tuneIMax - ((512-pot)/100.0));
        //         if(value <0) value = 0.0;
        //         break;
        //       }
        //    } 
        //}     
    cmdSetParm((addr+x), value);
    cmdSetParm((addr+x+3), value);
    
    tuneP = 0.0;
    tuneI = 0.0;
    tuneD = 0.0;
    tuneIMax = 0.0;
    pSend = false;
  }
  
  else
  {
    if((tuneP == 0.0) && (tuneI == 0.0) && (tuneD == 0.0) && (tuneIMax == 0.0))
      {
        for(int x; x < 3; x++)
        {
          value = EEPROM_readDouble((addr + x)*4);
          
          switch(x)
           {
            case 0:
             {
               tuneP = value;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P("tune P "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               if(beLog) eLog.println(bline);
               break;
             }
             
            case 1:
             {
               tuneI = value;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P("Tune I "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               if(beLog) eLog.println(bline);
               break;
             }
             
            case 2:
             {
               tuneIMax = value;
               dtostrf(value, 4, 2, cFloat);
               strcpy(bline, P("Tune I Max "));
               strcat(bline, cFloat);
               strcat(bline, P("  "));
               if(beLog) eLog.println(bline);
               break;
             }
           }
                   
           if(value > 65499.0) value = 65500.0;
           if(x != 2) dtostrf((value), 4, 2, cFloat);
           else dtostrf((value/100), 4, 2, cFloat);
           strcpy(bline, " ");
           strcat(bline, cFloat);
           myGLCD.setFont(BigFont);
           myGLCD.setBackColor(0, 0, 128);
           myGLCD.setColor(255, 255, 255);
           myGLCD.print(bline, 185, (44 + (20 * x)));
        }
      }
      
    else
      {
          int x = ley;
		  if(x > 2) x = 2;
          switch(x)
            {
              case 0: 
                {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 184, (64 + (20 * (x+1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+2))), 184, (64 + (20 * (x+2))));
                  myGLCD.fillRect(179, (44 + (20 * (x+3))), 184, (64 + (20 * (x+3))));
                  break;
                }
                
              case 1:
                 {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+2))), 185, (64 + (20 * (x+2))));
                  break;
                 }
                 
              case 2:
                 {
                   myGLCD.setColor(255, 0, 0);
                   myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                   myGLCD.setColor(0, 0, 128);
                   myGLCD.fillRect(179, (44 + (20 * (x-3))), 185, (64 + (20 * (x-3))));
                   myGLCD.fillRect(179, (44 + (20 * (x-2))), 185, (64 + (20 * (x-2))));
                   myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                  break;
                 }
            }
       //if(pot > 512)
       // {
           //int x = ley;
           switch(x)
            {
				case 0: 
                {
                  
				  tmax = (EEPROM_readDouble((addr + x)*4)*2);
				  if(tmax < 1) tmax = 1.0;
				  value = ((tmin + (tmax - tmin))*(pot/1024.0));
                  break;
                }
                
              case 1:
                {  
				  tmax = (EEPROM_readDouble((addr + x)*4)*2);
				  if(tmax < 1) tmax = 1.0;
                  value = ((tmin + (tmax - tmin))*(pot/1024.0));
                  break;
                }
                 
              case 2:
                {
				  tmax = (EEPROM_readDouble((addr + x)*4)*2);
				  if(tmax < 1) tmax = 1.0;
				  value = ((tuneIMax*2)*(pot/1024.0));
                  break;
                }
            } 
            
            
            
           if(value > 65499.0) value = 65500.0;
           if(x != 2) dtostrf((value), 4, 2, cFloat);
           else dtostrf((value/100), 4, 2, cFloat);
           strcpy(bline, " ");
           strcat(bline, cFloat);
           myGLCD.setFont(BigFont);
           myGLCD.setBackColor(0, 0, 128);
           myGLCD.setColor(255, 255, 255);
           myGLCD.print(bline, 185, (44 + (20 * x)));
      //  }
      //  if(pot < 512)
      //  {
      //     //int x = ley;
      //     switch(x)
      //      {
      //        case 0:
      //         {
      //           value = (tuneP - (((512-pot)/100.0)/2));
      //           if(value <0) value = 0.0;
      //           break;
      //         }
      //         
      //        case 1: 
      //         {
      //           value = (tuneI - (((512-pot)/100.0)/2));
      //           if(value <0) value = 0.0;
      //           break;
      //         }
      //         
      //        case 2:
      //         {
      //           value = (tuneIMax - ((512-pot)/10.0));
      //           if(value <0) value = 0.0;
      //           break;
      //         }
      //      } 
      //      
      //     if(value > 65499.0) value = 65500.0;
      //     if(x != 3) dtostrf((value), 4, 2, cFloat);
      //     else dtostrf((value/100), 4, 2, cFloat);
      //     strcpy(bline, " ");
      //     strcat(bline, cFloat);
      //     myGLCD.setFont(BigFont);
      //     myGLCD.setBackColor(0, 0, 128);
      //     myGLCD.setColor(255, 255, 255);
      //     myGLCD.print(bline, 185, (44 + (20 * x)));
      //  }
      }
  }
 return;
}