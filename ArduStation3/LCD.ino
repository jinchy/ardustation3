
void MainMenu()
{
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Main Menu"), CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 226, 319, 239); 
               
  
               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 20, 75, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("HUD"), 30, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Flight"), 97, 44);
               myGLCD.print(P("Map"), 105, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Follow"), 170, 44);
               myGLCD.print(P("Me"), 180, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Set"), 255, 44);
               myGLCD.print(P("Limits"), 245, 56);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Set"), 25, 115);
               myGLCD.print(P("Mode"), 20, 127);               
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 95, 150, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               //myGLCD.print("Start", 97, 44);
               //myGLCD.print("Feeds", 97, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               //myGLCD.print("Stop", 175, 44);
               //myGLCD.print("Feeds", 175, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 95, 305, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Setup"), 250, 126);
               //myGLCD.print("Menu", 250, 132);
               return;
}

void MainMenuR()
{
               mChange = true;
             
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
             
			   if(mChange)
               {
                 myGLCD.setFont(BigFont);
                 myGLCD.setColor(0,255,0);
                 myGLCD.setBackColor(0,0,128);
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print(P("    Stabilize    "), CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print(P("     Loiter     "), CENTER, 200);
                 if((baseMode & 89) == 81 && customMode == 10)  myGLCD.print(P("   OF Loiter    "), CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print(P("Return To Launch"), CENTER, 200);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print(P("    Alt Hold    "), CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print(P("      Auto      "), CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print(P("     Guided      "), CENTER, 200);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("    ARMED    "), CENTER, 175);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("    DISARMED    "), CENTER, 175);                 
                 }
               }
               myGLCD.setFont(SmallFont);
               return;
}

void Setup1()
{
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Ground Station Setup"), CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255,255,0);  

               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 20, 75, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Debug"), 20, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Start"), 97, 44);
               myGLCD.print(P("Feeds"), 97, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Stop"), 175, 44);
               myGLCD.print(P("Feeds"), 175, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
			   myGLCD.print(P("Tune"), 255, 44);
               myGLCD.print(P("Parm"), 255, 56);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("SPT"), 20, 125);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 95, 150, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("SD Card"), 92, 125);
               //myGLCD.print("Feeds", 97, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("GS Config"), 155, 125);
               //myGLCD.print("Feeds", 175, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 95, 305, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Main"), 250, 120);
               myGLCD.print(P("Menu"), 250, 132);
               return;

}

void Setup1R()
{
              return;
}

void Debug1()
{
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 0);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Ground Station Debug"), CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255,255,0);  
               return;
}

void Debug1R()
{
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 0);
               
               gps.f_get_position(&flat, &flon, &age);
               
               strcpy(bline, P("Drone Type: "));
               itoa(droneType, cFloat, 10);
			   strcat(bline, cFloat);
               myGLCD.print(bline, 5, 12);
             
               strcpy(bline, P("Autopilot: "));
               itoa(autoPilot, cFloat, 10);
			   strcat(bline, cFloat);
               myGLCD.print(bline, 5, 24);
               
               strcpy(bline, P("Rcd SysID: "));
			   itoa(received_sysid, cFloat, 10);
			   strcat(bline, cFloat);
               myGLCD.print(bline, 5, 36);
             
               strcpy(bline, P("Rcd CompID: "));
               itoa(received_compid, cFloat, 10);
			   strcat(bline, cFloat);
               myGLCD.print(bline, 5, 48);
               
               strcpy(bline, P("Pitch: "));
			   dtostrf(pitch, 10, 6, cFloat);
               strcat(bline, cFloat);
               myGLCD.print(bline, 5, 60);
             
               strcpy(bline, P("Yaw: "));
			   dtostrf(yaw, 10, 6, cFloat);
               strcat(bline, cFloat);             
               myGLCD.print(bline, 5, 72);
               
               strcpy(bline, "Roll: ");
			   dtostrf(roll, 10, 6, cFloat);
               strcat(bline,  cFloat); 
               myGLCD.print(bline, 5, 84);
              
//=============================================================
               
               strcpy(bline, P("AP Lat: "));
			   dtostrf(latitude, 10, 6, cFloat);
               strcat(bline, cFloat);
               myGLCD.print(bline, 5, 96);
             
               strcpy(bline, P("AP Lon: "));
			   dtostrf(longitude, 10, 6, cFloat);
               strcat(bline, cFloat);             
               myGLCD.print(bline, 5, 108);
               
               strcpy(bline, P("Alt: "));
               dtostrf(altitude, 10, 6, cFloat);
               strcat(bline, cFloat); 
               myGLCD.print(bline, 5, 120);
               
               strcpy(bline, P("GPS Fix: "));
               itoa(gpsfix, cFloat, 10); 
			   strcat(bline, cFloat);
               strcat(bline, P("D"));
               myGLCD.print(bline, 5, 132);
               
               strcpy(bline, P("Dist To AP: "));
               dtostrf(calc_dist(latitude,longitude, flat, flon), 6, 4, cFloat);
               strcat(bline, cFloat); 
               myGLCD.print(bline, 5, 144);
               
               strcpy(bline, P("My Lat: "));
               dtostrf(flat, 10, 6, cFloat);
               strcat(bline, cFloat);
               myGLCD.print(bline, 5, 156);
             
               strcpy(bline, P("My Lon: "));
               dtostrf(flon, 10, 6, cFloat);
               strcat(bline, cFloat);             
               myGLCD.print(bline, 5, 168);
               
               strcpy(bline, P("Battery: "));
			   dtostrf(battery/1000, 6, 4, cFloat);
               strcat(bline, cFloat);             
               myGLCD.print(bline, 5, 180);
               
               strcpy(bline, P("Current: "));
			   dtostrf(current, 6, 4, cFloat);
               strcat(bline, cFloat);             
               myGLCD.print(bline, 5, 192);
               
               strcpy(bline, P("Ground Dist: "));
			   dtostrf(ground_distance, 6, 4, cFloat);
               strcat(bline, cFloat);             
               myGLCD.print(bline, 5, 204);
               
               strcpy(bline, P("Base Mode: "));
			   itoa(baseMode, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");              
               myGLCD.print(bline, 158, 12);
               
               strcpy(bline, P("Custom Mode: "));
               itoa(customMode, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 24);
               
               strcpy(bline, P("Pot: "));
               itoa(pot, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 36);

			   strcpy(bline, P("X acc: "));
               itoa(xacc, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 48);
			   
			   strcpy(bline, P("Y acc: "));
               itoa(yacc, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 60);
			   			   
			   strcpy(bline, P("Z acc: "));
               itoa(zacc, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 72);

			   strcpy(bline, P("X gyr: "));
               itoa(xgyro, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 84);
			   
			   strcpy(bline, P("Y gyr: "));
               itoa(ygyro, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 96);
			   
			   strcpy(bline, P("Y gyr: "));
               itoa(ygyro, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 108);
			   
			   strcpy(bline, P("Z gyr: "));
               itoa(zgyro, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 108);
			   
			   strcpy(bline, P("X mag: "));
               itoa(xmag, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 120);
			   
			   strcpy(bline, P("Y mag: "));
               itoa(ymag, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 132);
			   
			   strcpy(bline, P("Z mag: "));
               itoa(zmag, cFloat, 10);
			   strcat(bline, cFloat);
               strcat(bline, "  ");             
               myGLCD.print(bline, 158, 144);
               return;
}

void HUD()
{
               mChange = true;
               myGLCD.clrScr();
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               return;
}

void HUDR()
{
               int dpitch;
               int droll;
               int sy;
               int ey;
               int sx = 0;
               int ex = 319;
               float dYaw;

               dpitch = (239/2) + ((pitch/90)*239);
               
               droll = roll*2;
               
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 128);
			   
			   if(battery > 9) myGLCD.setColor(0, 255, 0);
			   else myGLCD.setColor(255, 0, 0);
               dtostrf(battery/1000, 5, 2, cFloat);
               strcpy(bline, cFloat); 
               strcat(bline, P(" "));  
               myGLCD.setFont(BigFont);               
               myGLCD.print(bline, LEFT, 1);
			   
               myGLCD.setColor(255, 255, 255);
			   dtostrf(current/100, 5, 2, cFloat);
               strcpy(bline, cFloat); 
               //strcat(bline, P(" "));  
               myGLCD.setFont(BigFont);               
               myGLCD.print(bline, LEFT, 20);

			   
               myGLCD.setColor(255, 255, 255);

			   if(yaw<1)
               {
                 dYaw = 360 + yaw;
               }
               else
               {
                 dYaw = yaw;
               }
               
               //strcpy(bline, P("  "));
               dtostrf(dYaw, 7, 2, cFloat);
               strcpy(bline, cFloat); 
               strcat(bline, P("  "));  
               myGLCD.setFont(BigFont);               
               myGLCD.print(bline, CENTER, 1);

               //strcpy(bline, P("  "));
			   dYaw = rBearing();
               dtostrf(dYaw, 7, 2, cFloat);
               strcpy(bline, cFloat); 
               strcat(bline, P("  "));  
               myGLCD.setFont(BigFont);               
               myGLCD.print(bline, CENTER, 20);
                                          
               sy = dpitch - droll;
               ey = dpitch + droll;
               
               if(sy <0) 
               {
                sx = (sy *-1);
                sy = 0; 
               }
               
               if(sy >239) 
               {
                sx = (sy - 239);
                sy = 239; 
               }
               
               if(ey <0) 
               {
                ex = (ey *-1);
                ey = 0; 
               }
               
               if(ey >239) 
               {
                ex = (ey - 239);
                ey = 239; 
               }
               
               myGLCD.setColor(0, 0, 128);
               myGLCD.drawLine(lsx, lsy, lex, ley);
              
               myGLCD.setColor(255, 255, 255);
               myGLCD.drawLine(sx, sy, ex, ey);
                              
               lsx = sx;
               lsy = sy;
               lex = ex;
               ley = ey;
               
               if(mChange)
               {
                 myGLCD.setFont(BigFont);
                 myGLCD.setColor(0,255,0);
                 myGLCD.setBackColor(0,0,128);
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print(P("    Stabilize    "), CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print(P("     Loiter     "), CENTER, 200);
                 if((baseMode & 89) == 81 && customMode == 10)  myGLCD.print(P("   OF Loiter    "), CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print(P("Return To Launch"), CENTER, 200);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print(P("    Alt Hold    "), CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print(P("      Auto      "), CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print(P("     Guided      "), CENTER, 200);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("    ARMED    "), CENTER, 175);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("    DISARMED    "), CENTER, 175);                 
                 }
               }
               return;
}

void FlightMapM()
{
               myGLCD.clrScr();
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               
               mapLastX = 0;
               mapLastY = 0;
                
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("-"), 185, 120);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("+"), 185, 46);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Ok"), 255, 50);
               


               strcpy(bline, P("Zoom:"));
			   dtostrf(mapZoom, 4, 2, cFloat);
               strcat(bline, cFloat); 
               myGLCD.print(bline, 5, 90);
               
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0,255,0);
               myGLCD.setBackColor(0,0,128);
               
               if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print(P("    Stabilize    "), CENTER, 200);
               if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print(P("     Loiter     "), CENTER, 200);
               if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print(P("Return To Launch"), CENTER, 200);
               if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print(P("    Alt Hold    "), CENTER, 200);
               if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print(P("      Auto      "), CENTER, 200);
               if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print(P("     Guided      "), CENTER, 200);

               if((baseMode & 193) == 193)
               {
                myGLCD.setFont(BigFont);
                myGLCD.setColor(255,0,0);
                myGLCD.setBackColor(0,0,128);
                myGLCD.print(P("    ARMED    "), CENTER, 175);
               }
               
               else
               {
                myGLCD.setFont(BigFont);
                myGLCD.setColor(0,255,0);
                myGLCD.setBackColor(0,0,128);
                myGLCD.print(P("    DISARMED    "), CENTER, 175);                 
               }
               myGLCD.setFont(SmallFont);
               return;
}

void FlightMapMR()
{               
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               strcpy(bline, P("Zoom:"));
               dtostrf(mapZoom, 4, 2, cFloat);
               strcat(bline, cFloat); 
               myGLCD.print(bline, 5, 90);
               return;

}

void FlightMap()
{
               myGLCD.clrScr();
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 255, 255);
               myGLCD.fillCircle((319/2), (239/2), 4);
               mapLastX = 0;
               mapLastY = 0;
               
               
                 myGLCD.setFont(SmallFont);
                 myGLCD.setColor(0,255,0);
                 myGLCD.setBackColor(0,0,128);
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print(P("Stabilize"), RIGHT, 5);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print(P("  Loiter  "), RIGHT, 5);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print(P("  R T L   "), RIGHT, 5);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print(P(" Alt Hold "), RIGHT, 5);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print(P("  Auto   "), RIGHT, 5);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print(P(" Guided  "), RIGHT, 5);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("  ARMED  "), CENTER, 5);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("DISARMED"), CENTER, 5);                 
                 }
               
               myGLCD.setFont(SmallFont);
               return;
}

void FlightMapR()
{
               int cx = 319/2;
               int cy = 239/2;
               int mapNewX;
               int mapNewY;
              
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 128);
               
               dtostrf(mapZoom, 4, 1, cFloat);
               strcpy(bline, P("Zoom: "));
               strcat(bline, cFloat); 
               myGLCD.print(bline, LEFT, 5);

               gps.f_get_position(&flat, &flon, &age);
               mapNewX = cx+((69.1*(flat-latitude))*(1000*mapZoom));
               mapNewY = cy+((69.1*(flon-longitude)*cos(flat/57.3))*(1000*mapZoom));
               if(mapNewX > 319) mapNewX = 319;
               if(mapNewY > 239) mapNewY = 239;
               if(mapNewX < 0) mapNewX = 0;
               if(mapNewY < 0) mapNewY = 0;
               
               if( mapLastX == 0 && mapLastY == 0)
               {
                mapLastX = cx;
                mapLastY = cy;
               }
               
               myGLCD.setColor(255, 255, 255);
               myGLCD.drawLine(mapLastX, mapLastY, mapNewX, mapNewY);
               mapLastX = mapNewX;
               mapLastY = mapNewY;
               
               if(mChange)
               {
                 myGLCD.setFont(SmallFont);
                 myGLCD.setColor(0,255,0);
                 myGLCD.setBackColor(0,0,128);
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print(P("Stabilize"), RIGHT, 5);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print(P("  Loiter  "), RIGHT, 5);
                 if((baseMode & 89) == 81 && customMode == 10)  myGLCD.print(P(" OF Loiter "), RIGHT, 5);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print(P("  R T L   "), RIGHT, 5);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print(P(" Alt Hold "), RIGHT, 5);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print(P("  Auto   "), RIGHT, 5);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print(P(" Guided  "), RIGHT, 5);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("  ARMED  "), CENTER, 5);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("DISARMED"), CENTER, 5);                 
                 }
               }
               myGLCD.setFont(SmallFont);               
               return;
}

void FollowMe()
{
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
  myGLCD.setColor(0, 0, 128);
  myGLCD.fillRect(0, 0, 319, 239);

  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 255, 255);
  
  return;
  
}    //End FollowMe

void FollowMeR()
{
  int i = 12;
  
  gps.f_get_position(&flat, &flon, &age); 
  cmdSetComeHere(15);
  strcpy(bline, P("Come To: "));
  dtostrf(flat, 10, 6, cFloat);
  strcat(bline, cFloat);
   
  strcat(bline, P(", "));
  dtostrf(flon, 10, 6, cFloat);
  strcat(bline, cFloat);

  strcat(bline, P(", "));
  dtostrf(15.0, 10, 6, cFloat);
  strcat(bline, cFloat);

  myGLCD.print(bline, LEFT, i);
  
  delay(10);
  return;
  
  
}
 
void SetMode()
{
               mChange = true;
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Set Mode"), CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255,255,0);  

               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 20, 75, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Stab"), 20, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Loiter"), 95, 50);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Auto"), 175, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("RTL"), 252, 50);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Alt Hold"), 10, 125);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 95, 150, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Guided"), 97, 125);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Arm"), 175, 125);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 95, 305, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Main"), 250, 120);
               myGLCD.print(P("Menu"), 250, 132);

			   /////////////////////////////////////////
               //              Dodgey Row 3
               ////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 167, 75, 237);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("OFLoiter"), 7, 195);
               return;

}

void SetModeR()
{
               if(mChange)
               {
                 myGLCD.setFont(BigFont);
                 myGLCD.setColor(0,255,0);
                 myGLCD.setBackColor(0,0,128);
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print(P("Stabilize"), CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print(P("  Loiter  "), CENTER, 200);
                 if((baseMode & 89) == 81 && customMode == 10)  myGLCD.print(P("OF Loiter"), CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print(P("    RTL   "), CENTER, 200);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print(P(" Alt Hold "), CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print(P("   Auto   "), CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print(P("  Guided  "), CENTER, 200);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("  ARMED  "), CENTER, 175);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print(P("DISARMED"), CENTER, 175);                 
                 }
               }
               myGLCD.setFont(SmallFont);
               return;
}

void SetLimitM()
{
               myGLCD.clrScr();
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);

               mapLastX = 0;
               mapLastY = 0;
                
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(90, 40, 160, 110);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("-"), 120, 66);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(15, 40, 85, 110);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("+"), 45, 66);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Ok"), 255, 50);
               
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 128);
               strcpy(bline, P("Soft Limit:"));
               itoa(softLimitMeters, cFloat, 10);
			   strcat(bline, cFloat); 
               myGLCD.print(bline, 15, 20);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(90, 140, 160, 210);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("-"), 120, 166);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(15, 140, 85, 210);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("+"), 45, 166);
               
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 128);
               strcpy(bline, P("Hard Limit:"));
               itoa(limitMeters, cFloat, 10); 
			   strcat(bline, cFloat);
               myGLCD.print(bline, 15, 120);
               return;
}

void SetLimitR()
{               
               myGLCD.setFont(BigFont);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 128);
               //String bline;

               strcpy(bline, P("Soft Limit:"));
               itoa(softLimitMeters, cFloat, 10); 
			   strcat(bline, cFloat);
               if(softLimitMeters < 10) strcat(bline, " ");
               myGLCD.print(bline, 15, 20);
               
               strcpy(bline, P("Hard Limit:"));
			   itoa(limitMeters, cFloat, 10);
               strcat(bline, cFloat); 
               if(limitMeters < 10) strcat(bline, " ");
               myGLCD.print(bline, 15, 120);

              return;
}

void ParmM()
{
      myGLCD.clrScr();
      myGLCD.setFont(SmallFont);
      myGLCD.setColor(0, 0, 128);
      myGLCD.fillRect(0, 0, 319, 239);
      lsy = 0;
      ley = 19;
      lsx = 0;
      lex = 0;
      
      myGLCD.setColor(255, 0, 0);
      myGLCD.fillRect(0, 0, 319, 12);
      myGLCD.setBackColor(255, 0, 0);
      myGLCD.setColor(255, 255, 255);
      myGLCD.print(P("Index   Parameter       Value"), LEFT, 0);
      
      myGLCD.setColor(0, 255, 0);
      myGLCD.fillRoundRect(285, 20, 319, 100);
      myGLCD.setColor(0, 0, 0);
      myGLCD.setBackColor(0, 255, 0);
      myGLCD.print(P("UP"), 295, 55);
               
      myGLCD.setColor(0, 255, 0);
      myGLCD.fillRoundRect(285, 139, 319, 219);
      myGLCD.setColor(0, 0, 0);
      myGLCD.setBackColor(0, 255, 0);
      myGLCD.print(P("DN"), 295, 174);
      
      cmdRequestParm();
      cmdRequestParm();
      return;
      
      /*
      for(int i = lsy; i < ley; i++)
      {
       dtostrf(EEPROM_readDouble(pIndex), 4, 1, cFloat);
       bline = " ";
       bline += pIndex;
       bline += ": ";
       bline += PName(pIndex);
       bline += ",";
       bline += cFloat;
       myGLCD.print(bline, LEFT, i*12);
      }
      */
}

void ParmR()
{
      int l = 0;
      myGLCD.setBackColor(0, 0, 128);
      myGLCD.setColor(255, 255, 255);
      myGLCD.setFont(SmallFont);
      if((pIndex >= 250) && ((lsx != lsy) || (lex != ley)) )
      {
        myGLCD.print(P("                     "), 25, 110);
        for(int x = lsy; x < ley; x++)
        {
         value = EEPROM_readDouble(x*4);
         if(value > 65499.0) value = 65500.0;

		 strcpy(bline, P(" "));
         itoa(x, cFloat, 10);
		 strcat(bline, cFloat);
         strcat(bline, "  ");
         myGLCD.print(bline, 0, (l+1)*12);
         
         strcpy(bline, P(" "));
         strcat(bline, PName(x));
         strcat(bline, "     ");
         myGLCD.print(bline, 55, (l+1)*12);
         
         strcpy(bline, P(" "));
         dtostrf(value, 4, 1, cFloat);
         strcat(bline, cFloat);
         strcat(bline, P("   "));
         myGLCD.print(bline, 190, (l+1)*12);
         l++;
         lex = ley;
         lsx = lsy;
        }
      }
      else
      {
        if(((lsx != lsy) || (lex != ley)))
        {
         myGLCD.setFont(SmallFont);
		 strcpy(bline, P("Getting: "));
         strcat(bline, PName(pIndex));
         strcat(bline, P("       "));
         myGLCD.print(bline, 25, 110);
        }
      }
      return;
}

void ParamMainP1()
{
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Paremeter Main"), CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255,255,0);  

               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 20, 75, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Sensors"), 15, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Modes"), 96, 50);
               //myGLCD.print("Feeds", 97, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Stab"), 167, 44);
			   myGLCD.print(P("Tune"), 167, 56);
                
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Stab"), 252, 38);
			   myGLCD.print(P("Rate"), 252, 50);
               myGLCD.print(P("Tune"), 252, 62);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Loiter"), 15, 119);
               myGLCD.print(P("Tune"), 20, 131);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 95, 150, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Nav"), 104, 119);
               myGLCD.print(P("Tune"), 100, 131);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Alt"), 175, 119);
               myGLCD.print(P("Tune"), 175, 131);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 95, 305, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Browse"), 245, 120);
               myGLCD.print(P("Params"), 245, 132);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(117, 170, 187, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Main"), 137, 185);
               myGLCD.print(P("Menu"), 137, 197);
               
               myGLCD.setColor(0, 100, 0);
               myGLCD.fillRoundRect(5, 170, 112, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 100, 0);
               myGLCD.print(P("Down"), 40, 198);
               //myGLCD.print("Menu", 10, 177);
               return;
}

void ParamMainP2()
{
               //myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setBackColor(0, 255, 0);
               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.print(P("       "), 15, 50);
               myGLCD.print(P("Sensors"), 15, 50);
               
               myGLCD.print(P("     "), 96, 50);
               myGLCD.print(P("Modes"), 96, 50);
                                  
               myGLCD.print(P("        "), 162, 50);
               myGLCD.print(P("Waypoint"), 162, 50);
               
               myGLCD.print(P("    "), 252, 44);
               myGLCD.print(P("    "), 252, 56);
               myGLCD.print(P("Stab"), 252, 44);
               myGLCD.print(P("Tune"), 252, 56);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.print(P("      "), 15, 119);
               myGLCD.print(P("    "), 20, 131);
               myGLCD.print(P("Loiter"), 15, 119);
               myGLCD.print(P("Tune"), 20, 131);
                              
               myGLCD.print(P("   "), 104, 119);
               myGLCD.print(P("    "), 100, 131);
               myGLCD.print(P("Nav"), 104, 119);
               myGLCD.print(P("Tune"), 100, 131);
                              
               myGLCD.print(P("   "), 175, 125);
               myGLCD.print(P("Arm"), 175, 125);
               
               myGLCD.print(P("    "), 250, 120);
               myGLCD.print(P("    "), 250, 132);
               myGLCD.print(P("Main"), 250, 120);
               myGLCD.print(P("Menu"), 250, 132);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(117, 170, 187, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Main"), 137, 185);
               myGLCD.print(P("Menu"), 137, 197);
               
               myGLCD.setColor(0, 100, 0);
               myGLCD.fillRoundRect(5, 170, 112, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 100, 0);
               myGLCD.print(P("Down"), 40, 198);
               
               myGLCD.setColor(0, 100, 0);
               myGLCD.fillRoundRect(192, 170, 304, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 100, 0);
               myGLCD.print(P("Up"), 240, 198);
               return;
}

void ParamMainR()
{
return;  
}

void LoiterTune()
{   
	ThreeTune(P("Loiter"), 128);
    return;
}

void LoiterTuneR()
{     
	ThreeTuneR(128);
	return;
}

void NavTune()
{     
	ThreeTune(P("Navigation"), 136);
               return;
}

void NavTuneR()
{ 
	ThreeTuneR(136);
 return;
}

void StabTune()
{   
	TwoTune(P("Stab Rate"), 156);
	return;
}

void StabTuneR()
{              
	TwoTuneR(156);
 return;
}

void StabRTune()
{
	ThreeTune(P("Stab Rate"), 116);
}

void StabRTuneR()
{
	ThreeTuneR(116);
}

void AltTune()
{              
 TwoTune(P("Altitude"), 116);
}

void AltTuneR()
{              
 TwoTuneR(116);
 return;
}

void SerialPassThru()
{
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Serial Passthrough"), CENTER, 1);
			   myGLCD.print(P("Plug Ground Station into serial now"), CENTER, 24);
               myGLCD.setFont(BigFont);
               myGLCD.setBackColor(0, 0, 128);
               SetSPT();
}

void SerialPassThruR()
{
   
}
  
void SDMaint()
{
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("SD Card Menu"), CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 226, 319, 239); 
               
  
               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 20, 75, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Show"), 25, 44);
               myGLCD.print(P("Contents"), 10, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Stop"), 105, 44);
               myGLCD.print(P("Logging"), 93, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               //myGLCD.print("Follow", 170, 44);
               //myGLCD.print("Me", 180, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               //myGLCD.print("Set", 255, 44);
               //myGLCD.print("Limits", 245, 56);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Format"), 20, 125);
               //myGLCD.print("Mode", 20, 127);               
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 95, 150, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               //myGLCD.print("Start", 97, 44);
               //myGLCD.print("Feeds", 97, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 95, 305, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print(P("Setup"), 247, 119);
               myGLCD.print(P("Menu"), 250, 132);
			   if(beLog) eLog.println(P("SDMaint End"));
               return;
}

void SDMaintR()
{
			   if(beLog) eLog.println(P("SD Maint R"));
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.setFont(SmallFont);
               return;
}

void FormatSD()
{
			   myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 0);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print(P("Formatting SD Card"), CENTER, 1);
               myGLCD.setBackColor(0, 0, 0);
               myGLCD.setColor(255,255,255);  
			   SDReady = false;
               return;
}

void FormatSDR()
{
	if(!SDReady)
	{
		if (!card.init(spiSpeed, chipSelect)) 
		{
			myGLCD.print("\nSD initialization failure!", CENTER, 24);
			myGLCD.print("Is the SD card inserted correctly?", CENTER, 36);
			myGLCD.print("Is chip select correct at the top of this sketch?", CENTER, 48);
			return;
			//sdError("card.init failed");
		}

		cardSizeBlocks = card.cardSize();
  
		if (cardSizeBlocks == 0) 
		{
			myGLCD.print("CardSize Error", CENTER, 24);
			return;
		}
  
		cardCapacityMB = (cardSizeBlocks + 2047)/2048;

		strcpy(bline, "Card Size: ");
		itoa(cardCapacityMB, cFloat, 10);
		strcat(bline, cFloat);
		strcat(bline, " MB"); //, (MB = 1,048,576 bytes)";
		myGLCD.print(bline, LEFT, 24);		
		myGLCD.print("Erasing Card", LEFT, 36);
		eraseCard();
		myGLCD.print("Formatting Card", LEFT, 48);
		formatCard();
		myGLCD.print("Done...", LEFT, 60);
		myGLCD.print("Touch screen to continue...", LEFT, 72);
		delay(3000);
		SDReady = true;
	}
}

void ShowContents()
{

}

void ShowContentsR()
{

}

void StopLoggingSD()
{
		myGLCD.clrScr();
		myGLCD.setFont(SmallFont);
		myGLCD.setColor(0, 0, 0);
		myGLCD.fillRect(0, 0, 319, 239);
		myGLCD.setColor(255, 0, 0);
		myGLCD.fillRect(0, 0, 319, 13);
		myGLCD.setColor(255, 255, 255);
		myGLCD.setBackColor(255, 0, 0);
		myGLCD.print(P("Stopping Logging"), CENTER, 1);
		myGLCD.setBackColor(0, 0, 0);
		myGLCD.setColor(255,255,255); 
		int i = 20;

		if(beLog)
		{
			myGLCD.print(P("Stopping Error Log"), LEFT, i);
			eLog.println(P("Logging stopped at request of user"));
			eLog.close();
		}

		if(btLog)
		{
			i += 12;
			myGLCD.print(P("Stopping Telemetry Log"), LEFT, i);
			tLog.close();
		}
		
		/*if(bfile)
		{
			i += 12;
			myGLCD.print("Closing Open File", LEFT, i);
			file.close();
		}
		*/
		beLog = false;
		btLog = false;
		//bfile = false;

		i += 12;
	    myGLCD.print(P("All Files Closed"), LEFT, i);

		i += 12;
		myGLCD.print(P("Card may be ejected when ready"), LEFT, i);

		i += 24;
		myGLCD.print(P("Touch screen to continue"), LEFT, i);
}

void StopLoggingSDR()
{

}

void GSConfig()
{
		myGLCD.clrScr();
		myGLCD.setFont(SmallFont);
		myGLCD.setColor(0, 0, 128);
		myGLCD.fillRect(0, 0, 319, 239);
		myGLCD.setColor(255, 0, 0);
		myGLCD.fillRect(0, 0, 319, 13);
		myGLCD.setColor(255, 255, 255);
		myGLCD.setBackColor(255, 0, 0);
		myGLCD.print(P("GroundStation Config"), CENTER, 1);
		myGLCD.setBackColor(0, 0, 128);
		myGLCD.setColor(255,255,255); 
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
		myGLCD.print(P("OK"), 295, 123); 
               
		myGLCD.setColor(0, 255, 0);
		myGLCD.fillRoundRect(285, 159, 319, 239);
		myGLCD.setColor(0, 0, 0);
		myGLCD.setBackColor(0, 255, 0);
		myGLCD.print(P("DN"), 295, 195);  
		myGLCD.setBackColor(0, 0, 128);
		myGLCD.setColor(255,255,255); 
		ley = 0;
		int i = 20;
		int fr;
		fr = EEPROM.read(0);
		
		if(beLog) eLog.print("Settings Byte: ");
		itoa(fr, cFloat, 10);
		if(beLog) eLog.print(cFloat);
		Serial.print("Settings Byte: ");
		Serial.print(cFloat);
		
		myGLCD.setFont(SmallFont);

		myGLCD.print(P("       Factory Reset: "), LEFT, i);
		if((fr & 1) == 1)
		{
			myGLCD.print(P("ON"), 220, i);
		}
		else
		{
			myGLCD.print(P("OFF"), 220, i);
		}
		i += 18;

		myGLCD.print(P(" Serial Pass Through: "), LEFT, i);
		if((fr & 2) == 2)
		{
			myGLCD.print(P("ON"), 220, i);
		}
		else
		{
			myGLCD.print(P("OFF"), 220, i);
		}
		i += 18;

		myGLCD.print(P("           Error Log: "), LEFT, i);
		if((fr & 4) == 4)
		{
			myGLCD.print(P("ON"), 220, i);
		}
		else
		{
			myGLCD.print(P("OFF"), 220, i);
		}
		i += 18;
		
		myGLCD.print(P("       Telemetry Log: "), LEFT, i);
		if((fr & 8) == 8)
		{
			myGLCD.print(P("ON"), 220, i);
		}
		else
		{
			myGLCD.print(P("OFF"), 220, i);
		}
		i += 18;

		myGLCD.print(P("Telemetry Log Format: "), LEFT, i);
		if((fr & 16) == 16)
		{
			myGLCD.print(P("BIN"), 220, i);
		}
		else
		{
			myGLCD.print(P("CSV"), 220, i);
		}
		i += 18;

		if((fr & 32) ==32)
		{
			//something something
		}

		if((fr & 64) == 64)
		{
			//something something
		}

		if((fr & 128) == 128)
		{
			//something something
		}
}

void GSConfigR()
{
	int x = ley;
	int fr;
	fr = EEPROM.read(0);
	if(pSend)
	{
		myGLCD.setColor(255, 255, 255);
		switch(x)
            {
              case 0: 
                {
					if((fr & 1) == 1)
					{
						EEPROM.write(0, (fr ^ 1));
						myGLCD.print(P("OFF"), 220, (20+(x*18)));
					}
					else
					{
						EEPROM.write(0, (fr | 1));
						myGLCD.print(P("ON "), 220, (20+(x*18)));
					}
					pSend = false;
					break;
                }
                
              case 1:
                 {
					if((fr & 2) == 2)
					{
						EEPROM.write(0, (fr ^ 2));
						myGLCD.print(P("OFF"), 220, (20+(x*18)));
					}
					else
					{
						EEPROM.write(0, (fr | 2));
						myGLCD.print(P("ON "), 220, (20+(x*18)));
					}
					pSend = false;
					break;
                 }
                 
              case 2:
                 {
					if((fr & 4) == 4)
					{
						EEPROM.write(0, (fr ^ 4));
						myGLCD.print(P("OFF"), 220, (20+(x*18)));
					}
					else
					{
						EEPROM.write(0, (fr | 4));
						myGLCD.print(P("ON "), 220, (20+(x*18)));
					}
					pSend = false;
					break; 
                 }
                 
              case 3:
                 {
					if((fr & 8) == 8)
					{
						EEPROM.write(0, (fr ^ 8));
						myGLCD.print(P("OFF"), 220, (20+(x*18)));
					}
					else
					{
						EEPROM.write(0, (fr | 8));
						myGLCD.print(P("ON "), 220, (20+(x*18)));
					}
					pSend = false;
					break;
                 }

			  case 4:
                 {
					if((fr & 16) == 16)
					{
						EEPROM.write(0, (fr ^ 16));
						myGLCD.print(P("CSV"), 220, (20+(x*18)));
					}
					else
					{
						EEPROM.write(0, (fr | 16));
						myGLCD.print(P("BIN"), 220, (20+(x*18)));
					}
					pSend = false;
	                break;
                 }

			 case 5:
                 {
					if((fr & 32) == 32)
					{
						EEPROM.write(0, (fr ^ 32));
						myGLCD.print(P("CSV"), 220, (20+(x*18)));
					}
					else
					{
						EEPROM.write(0, (fr | 32));
						myGLCD.print(P("BIN"), 220, (20+(x*18)));
					}
					pSend = false;
                    break;
                 }
            }
	}
	else
	{
	      switch(x)
            {
              case 0: 
                {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (20 + (18 * x)), 184, (32 + (18 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (20 + (18 * (x+1))), 184, (32 + (18 * (x+1))));
                  myGLCD.fillRect(179, (20 + (18 * (x+2))), 184, (32 + (18 * (x+2))));
                  myGLCD.fillRect(179, (20 + (18 * (x+3))), 184, (32 + (18 * (x+3))));
                  myGLCD.fillRect(179, (20 + (18 * (x+4))), 184, (32 + (18 * (x+4))));
                  myGLCD.fillRect(179, (20 + (18 * (x+5))), 184, (32 + (18 * (x+5))));
                  break;
                }
                
              case 1:
                 {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (20 + (18 * x)), 184, (32 + (18 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (20 + (18 * (x-1))), 184, (32 + (18 * (x-1))));
                  myGLCD.fillRect(179, (20 + (18 * (x+1))), 184, (32 + (18 * (x+1))));
                  myGLCD.fillRect(179, (20 + (18 * (x+2))), 184, (32 + (18 * (x+2))));
                  myGLCD.fillRect(179, (20 + (18 * (x+3))), 184, (32 + (18 * (x+3))));
                  myGLCD.fillRect(179, (20 + (18 * (x+4))), 184, (32 + (18 * (x+4))));
                  break;
                 }
                 
              case 2:
                 {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (20 + (18 * x)), 184, (32 + (18 * x)));
                  myGLCD.setColor(0, 0, 128); 
                  myGLCD.fillRect(179, (20 + (18 * (x-2))), 184, (32 + (18 * (x-2))));
                  myGLCD.fillRect(179, (20 + (18 * (x-1))), 184, (32 + (18 * (x-1))));
                  myGLCD.fillRect(179, (20 + (18 * (x+1))), 184, (32 + (18 * (x+1))));
                  myGLCD.fillRect(179, (20 + (18 * (x+2))), 184, (32 + (18 * (x+2))));
                  myGLCD.fillRect(179, (20 + (18 * (x+3))), 184, (32 + (18 * (x+3))));
                  break; 
                 }
                 
              case 3:
                 {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (20 + (18 * x)), 184, (32 + (18 * x)));
                  myGLCD.setColor(0, 0, 128);				   
                  myGLCD.fillRect(179, (20 + (18 * (x-3))), 184, (32 + (18 * (x-3))));
                  myGLCD.fillRect(179, (20 + (18 * (x-2))), 184, (32 + (18 * (x-2))));
                  myGLCD.fillRect(179, (20 + (18 * (x-1))), 184, (32 + (18 * (x-1))));
                  myGLCD.fillRect(179, (20 + (18 * (x+1))), 184, (32 + (18 * (x+1))));
                  myGLCD.fillRect(179, (20 + (18 * (x+2))), 184, (32 + (18 * (x+2))));
                  break;
                 }

			  case 4:
                 {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (20 + (18 * x)), 184, (32 + (18 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (20 + (18 * (x-4))), 184, (32 + (18 * (x-4))));
                  myGLCD.fillRect(179, (20 + (18 * (x-3))), 184, (32 + (18 * (x-3))));
                  myGLCD.fillRect(179, (20 + (18 * (x-2))), 184, (32 + (18 * (x-2))));
                  myGLCD.fillRect(179, (20 + (18 * (x-1))), 184, (32 + (18 * (x-1))));
                  myGLCD.fillRect(179, (20 + (18 * (x+1))), 184, (32 + (18 * (x+1))));
                  break;
                 }

			 case 5:
                 {
                  myGLCD.setColor(255, 0, 0);
                  myGLCD.fillRect(179, (20 + (18 * x)), 184, (32 + (18 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (20 + (18 * (x-5))), 184, (32 + (18 * (x-5))));
                  myGLCD.fillRect(179, (20 + (18 * (x-4))), 184, (32 + (18 * (x-4))));
                  myGLCD.fillRect(179, (20 + (18 * (x-3))), 184, (32 + (18 * (x-3))));
                  myGLCD.fillRect(179, (20 + (18 * (x-2))), 184, (32 + (18 * (x-2))));
                  myGLCD.fillRect(179, (20 + (18 * (x-1))), 184, (32 + (18 * (x-1))));
                  break;
                 }
            }
	}
}