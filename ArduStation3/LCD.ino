
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
               myGLCD.print("Main Menu", CENTER, 1);
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
               myGLCD.print("HUD", 30, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Flight", 97, 44);
               myGLCD.print("Map", 105, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Follow", 170, 44);
               myGLCD.print("Me", 180, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Set", 255, 44);
               myGLCD.print("Limits", 245, 56);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Set", 25, 115);
               myGLCD.print("Mode", 20, 127);               
               
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
               myGLCD.print("Setup", 250, 126);
               //myGLCD.print("Menu", 250, 132);
               return;
}

void MainMenuR()
{
               mChange = true;
               //float flat;
               //float flon;
               //unsigned long age;
               char dLat[15];
               char dLon[15]; 
             
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               
               //gps.f_get_position(&flat, &flon, &age);
               
               //dtostrf(flat, 10, 6, dLat);
               //dtostrf(flon, 10, 6, dLon);
               //bline = "Lat: "; 
               //bline += dLat;
               //bline += "    Lon: ";  
               //bline += dLon;
               //bline += "    ";
               //myGLCD.print(bline, LEFT, 226);
               if(mChange)
               {
                 myGLCD.setFont(BigFont);
                 myGLCD.setColor(0,255,0);
                 myGLCD.setBackColor(0,0,128);
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print("    Stabilize    ", CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print("     Loiter     ", CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print("Return To Launch", CENTER, 200);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print("    Alt Hold    ", CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print("      Auto      ", CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print("     Guided      ", CENTER, 200);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("    ARMED    ", CENTER, 175);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("    DISARMED    ", CENTER, 175);                 
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
               myGLCD.print("Ground Station Setup", CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255,255,0);  

               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 20, 75, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Debug", 20, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Start", 97, 44);
               myGLCD.print("Feeds", 97, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Stop", 175, 44);
               myGLCD.print("Feeds", 175, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
			   myGLCD.print("Tune", 255, 44);
               myGLCD.print("Parm", 255, 56);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("SPT", 20, 125);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 95, 150, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Start", 97, 44);
               myGLCD.print("Feeds", 97, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Stop", 175, 44);
               myGLCD.print("Feeds", 175, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 95, 305, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Main", 250, 120);
               myGLCD.print("Menu", 250, 132);
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
               myGLCD.print("Ground Station Debug", CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255,255,0);  
               return;
}

void Debug1R()
{
               //float flat;
               //float flon;
               //unsigned long age;
               char dLon[15]; 
               
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 0);
               
               gps.f_get_position(&flat, &flon, &age);
               
               bline = "Drone Type: ";
               bline += droneType;
               myGLCD.print(bline, 5, 12);
             
               bline = "Autopilot: ";
               bline += autoPilot;
               myGLCD.print(bline, 5, 24);
               
               bline = "Rcd SysID: ";
               bline += received_sysid;
               myGLCD.print(bline, 5, 36);
             
               bline = "Rcd CompID: ";
               bline += received_compid;
               myGLCD.print(bline, 5, 48);
               
               dtostrf(pitch, 10, 6, cFloat);
               bline = "Pitch: ";
               bline += cFloat;
               //bline += pitch;
               myGLCD.print(bline, 5, 60);
             
               dtostrf(yaw, 10, 6, cFloat);
               bline = "Yaw: ";
               bline += cFloat;             
               myGLCD.print(bline, 5, 72);
               
               dtostrf(roll, 10, 6, cFloat);
               bline = "Roll: ";
               bline += cFloat; 
               myGLCD.print(bline, 5, 84);
              
//=============================================================
               
               dtostrf(latitude, 10, 6, cFloat);
               bline = "AP Lat: ";
               bline += cFloat;
               //bline += pitch;
               myGLCD.print(bline, 5, 96);
             
               dtostrf(longitude, 10, 6, cFloat);
               bline = "AP Lon: ";
               bline += cFloat;             
               myGLCD.print(bline, 5, 108);
               
               dtostrf(altitude, 10, 6, cFloat);
               bline = "Alt: ";
               bline += cFloat; 
               myGLCD.print(bline, 5, 120);
               
               //dtostrf(altitude, 10, 6, cFloat);
               bline = "GPS Fix: ";
               bline += gpsfix; 
               bline += "D";
               myGLCD.print(bline, 5, 132);
               
               dtostrf(calc_dist(latitude,longitude, flat, flon), 6, 4, cFloat);
               bline = "Dist To AP: ";
               bline += cFloat; 
               myGLCD.print(bline, 5, 144);
               
               dtostrf(flat, 10, 6, cFloat);
               bline = "My Lat: ";
               bline += cFloat;
               //bline += pitch;
               myGLCD.print(bline, 5, 156);
             
               dtostrf(flon, 10, 6, cFloat);
               bline = "My Lon: ";
               bline += cFloat;             
               myGLCD.print(bline, 5, 168);
               
               dtostrf(battery/1000, 6, 4, cFloat);
               bline = "Battery: ";
               bline += cFloat;             
               myGLCD.print(bline, 5, 180);
               
               dtostrf(current, 6, 4, cFloat);
               bline = "Current: ";
               bline += cFloat;             
               myGLCD.print(bline, 5, 192);
               
               dtostrf(ground_distance, 6, 4, cFloat);
               bline = "Ground Dist: ";
               bline += cFloat;             
               myGLCD.print(bline, 5, 204);
               
               //dtostrf(ground_distance, 6, 4, cFloat);
               bline = "Base Mode: ";
               bline += baseMode;
               bline += "  ";              
               myGLCD.print(bline, 158, 12);
               
               //dtostrf(ground_distance, 6, 4, cFloat);
               bline = "Custom Mode: ";
               bline += customMode;
               bline += "  ";             
               myGLCD.print(bline, 158, 24);
               
               bline = "Pot: ";
               bline += pot;
               bline += "  ";             
               myGLCD.print(bline, 158, 36);
               return;
}

void HUD()
{
               mChange = true;
               myGLCD.clrScr();
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               //myGLCD.fillRect(0, 0, 319, 239);
               //myGLCD.setColor(255, 0, 0);
               //myGLCD.fillRect(0, 0, 319, 13);
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
               if(yaw<1)
               {
                 dYaw = 360 + yaw;
               }
               else
               {
                 dYaw = yaw;
               }
               
               dtostrf(dYaw, 7, 2, cFloat);
               bline = "  ";
               bline += cFloat; 
               bline += "  ";  
               myGLCD.setFont(BigFont);               
               myGLCD.print(bline, CENTER, 1);
               
               dYaw = rBearing();
               dtostrf(dYaw, 7, 2, cFloat);
               bline = "  ";
               bline += cFloat; 
               bline += "  ";  
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
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print("    Stabilize    ", CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print("     Loiter     ", CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print("Return To Launch", CENTER, 200);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print("    Alt Hold    ", CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print("      Auto      ", CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print("     Guided      ", CENTER, 200);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("    ARMED    ", CENTER, 175);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("    DISARMED    ", CENTER, 175);                 
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
               myGLCD.print("-", 185, 120);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("+", 185, 46);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Ok", 255, 50);
               
               dtostrf(mapZoom, 4, 2, cFloat);
               bline = "Zoom:";
               bline += cFloat; 
               myGLCD.print(bline, 5, 90);
               
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0,255,0);
               myGLCD.setBackColor(0,0,128);
               
               if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print("    Stabilize    ", CENTER, 200);
               if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print("     Loiter     ", CENTER, 200);
               if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print("Return To Launch", CENTER, 200);
               if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print("    Alt Hold    ", CENTER, 200);
               if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print("      Auto      ", CENTER, 200);
               if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print("     Guided      ", CENTER, 200);

               if((baseMode & 193) == 193)
               {
                myGLCD.setFont(BigFont);
                myGLCD.setColor(255,0,0);
                myGLCD.setBackColor(0,0,128);
                myGLCD.print("    ARMED    ", CENTER, 175);
               }
               
               else
               {
                myGLCD.setFont(BigFont);
                myGLCD.setColor(0,255,0);
                myGLCD.setBackColor(0,0,128);
                myGLCD.print("    DISARMED    ", CENTER, 175);                 
               }
               myGLCD.setFont(SmallFont);
               return;
}

void FlightMapMR()
{               
               myGLCD.setFont(BigFont);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               dtostrf(mapZoom, 4, 2, cFloat);
               bline = "Zoom:";
               bline += cFloat; 
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
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print("Stabilize", RIGHT, 5);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print("  Loiter  ", RIGHT, 5);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print("  R T L   ", RIGHT, 5);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print(" Alt Hold ", RIGHT, 5);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print("  Auto   ", RIGHT, 5);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print(" Guided  ", RIGHT, 5);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("  ARMED  ", CENTER, 5);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("DISARMED", CENTER, 5);                 
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
               bline = "Zoom: ";
               bline += cFloat; 
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
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print("Stabilize", RIGHT, 5);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print("  Loiter  ", RIGHT, 5);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print("  R T L   ", RIGHT, 5);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print(" Alt Hold ", RIGHT, 5);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print("  Auto   ", RIGHT, 5);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print(" Guided  ", RIGHT, 5);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("  ARMED  ", CENTER, 5);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("DISARMED", CENTER, 5);                 
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
  return;
  
  /* 
  public void setGuidedModeWP(Locationwp gotohere)
        {
            if (gotohere.alt == 0 || gotohere.lat == 0 || gotohere.lng == 0)
                return;

            MainV2.giveComport = true;

            try
            {
                gotohere.id =(byte)MAV_CMD.WAYPOINT;

                MAV_MISSION_RESULT ans = MainV2.comPort.setWP(gotohere, 0, MAVLink.MAV_FRAME.GLOBAL_RELATIVE_ALT, (byte)2);

                if (ans != MAV_MISSION_RESULT.MAV_MISSION_ACCEPTED)
                    throw new Exception("Guided Mode Failed");
            }
            catch (Exception ex) { log.Error(ex); }

            MainV2.giveComport = false;
        } 
  */
  
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //                          Guided mode from APM
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /* 
            /// <summary>
        /// Save wp to eeprom
        /// </summary>
        /// <param name="loc">location struct</param>
        /// <param name="index">wp no</param>
        /// <param name="frame">global or relative</param>
        /// <param name="current">0 = no , 2 = guided mode</param>
        public MAV_MISSION_RESULT setWP(Locationwp loc, ushort index, MAV_FRAME frame, byte current)
        {
            MainV2.giveComport = true;
#if MAVLINK10
            mavlink_mission_item_t req = new mavlink_mission_item_t();
#else
            mavlink_waypoint_t req = new mavlink_waypoint_t();
#endif

            req.target_system = sysid;
            req.target_component = compid; // MAVLINK_MSG_ID_MISSION_ITEM

            req.command = loc.id;
            req.param1 = loc.p1;

            req.current = current;

            req.frame = (byte)frame;
            req.y = (float)(loc.lng);
            req.x = (float)(loc.lat);
            req.z = (float)(loc.alt);

            req.param1 = loc.p1;
            req.param2 = loc.p2;
            req.param3 = loc.p3;
            req.param4 = loc.p4;
            /*
            if (MainV2.cs.firmware == MainV2.Firmwares.ArduPlane)
            {
                switch (loc.id)
                {					// Switch to map APM command fields inot MAVLink command fields
                    case (byte)MAV_CMD.LOITER_TURNS:
                    case (byte)MAV_CMD.TAKEOFF:
                        req.param1 = loc.p1;
                        break;
                    case (byte)MAV_CMD.DO_SET_HOME:
                        req.param1 = loc.p1;
                        break;

                    case (byte)MAV_CMD.CONDITION_CHANGE_ALT:
                        req.param1 = loc.lat;
                        req.x = 0;
                        req.y = 0;
                        break;

                    case (byte)MAV_CMD.LOITER_TIME:
                        req.param1 = loc.p1 * 10;	// APM loiter time is in ten second increments
                        break;

                    case (byte)MAV_CMD.CONDITION_DELAY:
                    case (byte)MAV_CMD.CONDITION_DISTANCE:
                        req.param1 = loc.lat;
                        break;

                    case (byte)MAV_CMD.DO_JUMP:
                        req.param2 = loc.lat;
                        req.param1 = loc.p1;
                        break;

                    case (byte)MAV_CMD.DO_REPEAT_SERVO:
                        req.param4 = loc.lng;
                        goto case (byte)MAV_CMD.DO_CHANGE_SPEED;
                    case (byte)MAV_CMD.DO_REPEAT_RELAY:
                    case (byte)MAV_CMD.DO_CHANGE_SPEED:
                        req.param3 = loc.lat;
                        req.param2 = loc.alt;
                        req.param1 = loc.p1;
                        break;

                    case (byte)MAV_CMD.DO_SET_PARAMETER:
                    case (byte)MAV_CMD.DO_SET_RELAY:
                    case (byte)MAV_CMD.DO_SET_SERVO:
                        req.param2 = loc.alt;
                        req.param1 = loc.p1;
                        break;
                }
            }
            */
            /*
            req.seq = index;

            log.InfoFormat("setWP {6} frame {0} cmd {1} p1 {2} x {3} y {4} z {5}", req.frame, req.command, req.param1, req.x, req.y, req.z, index);

            // request
#if MAVLINK10
            generatePacket(MAVLINK_MSG_ID_MISSION_ITEM, req);
#else
            generatePacket(MAVLINK_MSG_ID_WAYPOINT, req);
#endif

            DateTime start = DateTime.Now;
            int retrys = 6;

            while (true)
            {
                if (!(start.AddMilliseconds(200) > DateTime.Now))
                {
                    if (retrys > 0)
                    {
                        log.Info("setWP Retry " + retrys);
#if MAVLINK10
            generatePacket(MAVLINK_MSG_ID_MISSION_ITEM, req);
#else
                        generatePacket(MAVLINK_MSG_ID_WAYPOINT, req);
#endif
                        start = DateTime.Now;
                        retrys--;
                        continue;
                    }
                    MainV2.giveComport = false;
                    throw new Exception("Timeout on read - setWP");
                }
                byte[] buffer = readPacket();
                if (buffer.Length > 5)
                {
#if MAVLINK10
                    if (buffer[5] == MAVLINK_MSG_ID_MISSION_ACK)
                    {
                        var ans = buffer.ByteArrayToStructure<mavlink_mission_ack_t>(6);
                        log.Info("set wp " + index + " ACK 47 : " + buffer[5] + " ans " + Enum.Parse(typeof(MAV_MISSION_RESULT), ans.type.ToString()));
                        return (MAV_MISSION_RESULT)ans.type;
                    }
                    else if (buffer[5] == MAVLINK_MSG_ID_MISSION_REQUEST)
                    {
                        var ans = buffer.ByteArrayToStructure<mavlink_mission_request_t>(6);
                        if (ans.seq == (index + 1))
                        {
                            log.Info("set wp doing " + index + " req " + ans.seq + " REQ 40 : " + buffer[5]);
                            MainV2.giveComport = false;

                            return MAV_MISSION_RESULT.MAV_MISSION_ACCEPTED;
                        }
                        else
                        {
                            log.InfoFormat("set wp fail doing " + index + " req " + ans.seq + " ACK 47 or REQ 40 : " + buffer[5] + " seq {0} ts {1} tc {2}", req.seq, req.target_system, req.target_component);
                            //break;
                        }
                    }
                    else
                    {
                        //Console.WriteLine(DateTime.Now + " PC setwp " + buffer[5]);
                    }
#else
                    if (buffer[5] == MAVLINK_MSG_ID_WAYPOINT_ACK)
                    { //mavlink_waypoint_request_t
                        log.Info("set wp " + index + " ACK 47 : " + buffer[5]);
                        break;
                    }
                    else if (buffer[5] == MAVLINK_MSG_ID_WAYPOINT_REQUEST)
                    {
                        mavlink_waypoint_request_t ans = buffer.ByteArrayToStructure<mavlink_waypoint_request_t>(6);

                        if (ans.seq == (index + 1))
                        {
                            log.Info("set wp doing " + index + " req " + ans.seq + " REQ 40 : " + buffer[5]);
                            MainV2.giveComport = false;
                            break;
                        }
                        else
                        {
                            log.InfoFormat("set wp fail doing " + index + " req " + ans.seq + " ACK 47 or REQ 40 : " + buffer[5] + " seq {0} ts {1} tc {2}", req.seq, req.target_system, req.target_component);
                            //break;
                        }
                    }
                    else
                    {
                        //Console.WriteLine(DateTime.Now + " PC setwp " + buffer[5]);
                    }
#endif
                }
            }

           // return MAV_MISSION_RESULT.MAV_MISSION_INVALID;
        }
*/
  
}    //End FollowMe

void FollowMeR()
{
  
  //mavlink_msg_request_data_stream_pack(127, 0, &msg, received_sysid, received_compid, MAV_DATA_STREAM_ALL, 5, MAV_DATA_STREAM_RAW_SENSORS_ACTIVE);
  //
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
               myGLCD.print("Set Mode", CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255,255,0);  

               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 20, 75, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Stab", 20, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Loiter", 95, 50);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Auto", 175, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("RTL", 252, 50);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Alt Hold", 10, 125);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 95, 150, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Guided", 97, 125);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Arm", 175, 125);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 95, 305, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Main", 250, 120);
               myGLCD.print("Menu", 250, 132);
               return;

}

void SetModeR()
{
               if(mChange)
               {
                 myGLCD.setFont(BigFont);
                 myGLCD.setColor(0,255,0);
                 myGLCD.setBackColor(0,0,128);
               
                 if((baseMode & 81) == 81 && customMode == 0)  myGLCD.print("    Stabilize    ", CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 5)  myGLCD.print("     Loiter     ", CENTER, 200);
                 if((baseMode & 89) == 89 && customMode == 6)  myGLCD.print("Return To Launch", CENTER, 200);
                 if((baseMode  & 81) == 81 && customMode == 2)  myGLCD.print("    Alt Hold    ", CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 3)  myGLCD.print("      Auto      ", CENTER, 200);
                 if((baseMode  & 89) == 89 && customMode == 4)  myGLCD.print("     Guided      ", CENTER, 200);

                 if((baseMode & 193) == 193)
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(255,0,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("    ARMED    ", CENTER, 175);
                 }
               
                 else
                 {
                  myGLCD.setFont(BigFont);
                  myGLCD.setColor(0,255,0);
                  myGLCD.setBackColor(0,0,128);
                  myGLCD.print("    DISARMED    ", CENTER, 175);                 
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
               //myGLCD.setFont(SmallFont);
               myGLCD.print("-", 120, 66);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(15, 40, 85, 110);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("+", 45, 66);
               //myGLCD.print("Feeds", 175, 56);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Ok", 255, 50);
               
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 128);
               bline = "Soft Limit:";
               bline += softLimitMeters; 
               myGLCD.print(bline, 15, 20);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(90, 140, 160, 210);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("-", 120, 166);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(15, 140, 85, 210);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("+", 45, 166);
               
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 128);
               bline = "Hard Limit:";
               bline += limitMeters; 
               myGLCD.print(bline, 15, 120);
               return;
}

void SetLimitR()
{               
               myGLCD.setFont(BigFont);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(0, 0, 128);
               
               bline = "Soft Limit:";
               bline += softLimitMeters; 
               if(softLimitMeters < 10) bline += " ";
               myGLCD.print(bline, 15, 20);
               
               bline = "Hard Limit:";
               bline += limitMeters; 
               if(limitMeters < 10) bline += " ";
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
      myGLCD.print("Index   Parameter       Value", LEFT, 0);
      
      myGLCD.setColor(0, 255, 0);
      myGLCD.fillRoundRect(285, 20, 319, 100);
      myGLCD.setColor(0, 0, 0);
      myGLCD.setBackColor(0, 255, 0);
      myGLCD.print("UP", 295, 55);
               
      myGLCD.setColor(0, 255, 0);
      myGLCD.fillRoundRect(285, 139, 319, 219);
      myGLCD.setColor(0, 0, 0);
      myGLCD.setBackColor(0, 255, 0);
      myGLCD.print("DN", 295, 174);
      
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
        myGLCD.print("                     ", 25, 110);
        for(int x = lsy; x < ley; x++)
        {
         value = EEPROM_readDouble(x*4);
         if(value > 65499.0) value = 65500.0;
         dtostrf(value, 4, 1, cFloat);
         bline = " ";
         bline += x;
         bline += "  ";
         myGLCD.print(bline, 0, (l+1)*12);
         
         bline = " ";
         bline += PName(x);
         bline += "     ";
         myGLCD.print(bline, 55, (l+1)*12);
         
         bline = " ";
         bline += cFloat;
         bline += "   ";
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
         bline = "Getting: ";
         bline += PName(pIndex);
         bline += "       ";
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
               myGLCD.print("Paremeter Main", CENTER, 1);
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.setColor(255,255,0);  

               /////////////////////////////////////////
               //              Row 1
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 20, 75, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Sensors", 15, 50);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 20, 150, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Modes", 96, 50);
               //myGLCD.print("Feeds", 97, 56);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 20, 225, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Stab", 167, 44);
			   myGLCD.print("Tune", 167, 56);
                
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 20, 305, 90);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Stab", 252, 38);
			   myGLCD.print("Rate", 252, 50);
               myGLCD.print("Tune", 252, 62);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(5, 95, 75, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Loiter", 15, 119);
               myGLCD.print("Tune", 20, 131);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(80, 95, 150, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Nav", 104, 119);
               myGLCD.print("Tune", 100, 131);
                              
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(155, 95, 225, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Alt", 175, 119);
               myGLCD.print("Tune", 175, 131);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(230, 95, 305, 165);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Browse", 245, 120);
               myGLCD.print("Params", 245, 132);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(117, 170, 187, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Main", 137, 185);
               myGLCD.print("Menu", 137, 197);
               
               myGLCD.setColor(0, 100, 0);
               myGLCD.fillRoundRect(5, 170, 112, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 100, 0);
               myGLCD.print("Down", 40, 198);
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
               myGLCD.print("       ", 15, 50);
               myGLCD.print("Sensors", 15, 50);
               
               myGLCD.print("     ", 96, 50);
               myGLCD.print("Modes", 96, 50);
                                  
               myGLCD.print("        ", 162, 50);
               myGLCD.print("Waypoint", 162, 50);
               
               myGLCD.print("    ", 252, 44);
               myGLCD.print("    ", 252, 56);
               myGLCD.print("Stab", 252, 44);
               myGLCD.print("Tune", 252, 56);
               
               
               /////////////////////////////////////////
               //              Row 2
               /////////////////////////////////////////
               myGLCD.print("      ", 15, 119);
               myGLCD.print("    ", 20, 131);
               myGLCD.print("Loiter", 15, 119);
               myGLCD.print("Tune", 20, 131);
                              
               myGLCD.print("   ", 104, 119);
               myGLCD.print("    ", 100, 131);
               myGLCD.print("Nav", 104, 119);
               myGLCD.print("Tune", 100, 131);
                              
               myGLCD.print("   ", 175, 125);
               myGLCD.print("Arm", 175, 125);
               
               myGLCD.print("    ", 250, 120);
               myGLCD.print("    ", 250, 132);
               myGLCD.print("Main", 250, 120);
               myGLCD.print("Menu", 250, 132);
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(117, 170, 187, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("Main", 137, 185);
               myGLCD.print("Menu", 137, 197);
               
               myGLCD.setColor(0, 100, 0);
               myGLCD.fillRoundRect(5, 170, 112, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 100, 0);
               myGLCD.print("Down", 40, 198);
               
               myGLCD.setColor(0, 100, 0);
               myGLCD.fillRoundRect(192, 170, 304, 233);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 100, 0);
               myGLCD.print("Up", 240, 198);
               return;
}

void ParamMainR()
{
return;  
}

void LoiterTune()
{   
	ThreeTune("Loiter", 128);
    return;
}

void LoiterTuneR()
{     
	ThreeTuneR(128);
	return;
}

void NavTune()
{     
	ThreeTune("Navigation", 136);
               return;
}

void NavTuneR()
{ 
	ThreeTuneR(136);
 return;
}

void StabTune()
{   
	ThreeTune("Stab Rate", 156);
	return;
}

void StabTuneR()
{              
	ThreeTuneR(156);
 return;
}

void StabRTune()
{
	ThreeTune("Stab Rate", 116);
}

void StabRTuneR()
{
	ThreeTuneR(116);
}

void AltTune()
{              
               myGLCD.clrScr();
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRect(0, 0, 319, 239);
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 0, 319, 13);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print("Tune Stabilisation", CENTER, 1);
               myGLCD.setFont(BigFont);
               myGLCD.setBackColor(0, 0, 128);
               
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRect(0, 24, 319, 44);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print("Roll", LEFT, 24);
               myGLCD.print ("Start", 110, 24);
               myGLCD.print ("New", 210, 24);
               
               myGLCD.setBackColor(0, 0, 128);
               myGLCD.print("   P:", LEFT, 44);
               myGLCD.print("   I:", LEFT, 64);
            // myGLCD.print("   D:", LEFT, 84);
               myGLCD.print("IMax:", LEFT, 84);
 
             //  myGLCD.setColor(255, 0, 0);
             //  myGLCD.fillRect(0, 124, 319, 144);
             //  myGLCD.setColor(255, 255, 255);
             //  myGLCD.setBackColor(255, 0, 0);
             //  myGLCD.print("Pitch", LEFT, 124);
               
             //  myGLCD.setBackColor(0, 0, 128);
             //  myGLCD.print("   P:", LEFT, 144);
             //  myGLCD.print("   I:", LEFT, 164);
             //  myGLCD.print("   D:", LEFT, 184);
             //  myGLCD.print("IMax:", LEFT, 204);

               int x;
               
               x = 165;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf(value, 4, 2, cFloat);
               bline = " ";
               bline += cFloat;
               bline += "  ";
               myGLCD.print(bline, 85, 44);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf(value, 4, 2, cFloat);
               bline = " ";
               bline += cFloat;
               bline += "  ";
               myGLCD.print(bline, 85, 64);
               
               x++;
               value = EEPROM_readDouble(x*4);
               if(value > 65499.0) value = 65500.0;
               dtostrf(value, 4, 2, cFloat);
               bline = " ";
               bline += cFloat;
               bline += "  ";
               myGLCD.print(bline, 85, 84);
               
               // x++;
              // value = EEPROM_readDouble(x*4);
              // if(value > 65499.0) value = 65500.0;
              // dtostrf((value/100), 4, 2, cFloat);
              // bline = " ";
              // bline += cFloat;
              // bline += "  ";
              // myGLCD.print(bline, 85, 104);
 
              // x++;
              // value = EEPROM_readDouble(x*4);
              // if(value > 65499.0) value = 65500.0;
              // dtostrf(value, 4, 2, cFloat);
              // bline = " ";
              // bline += cFloat;
              // bline += "  ";
              // myGLCD.print(bline, 85, 144);
               
              // x++;
              // value = EEPROM_readDouble(x*4);
              // if(value > 65499.0) value = 65500.0;
              // dtostrf(value, 4, 2, cFloat);
              // bline = " ";
              // bline += cFloat;
              // bline += "  ";
              // myGLCD.print(bline, 85, 164);
               
              // x++;
              // value = EEPROM_readDouble(x*4);
              // if(value > 65499.0) value = 65500.0;
              // dtostrf(value, 4, 2, cFloat);
              // bline = " ";
              // bline += cFloat;
              // bline += "  ";
              // myGLCD.print(bline, 85, 184);
               
              // x++;
              // value = EEPROM_readDouble(x*4);
              // if(value > 65499.0) value = 65500.0;
              // dtostrf((value/100), 4, 2, cFloat);
              // bline = " ";
              // bline += cFloat;
              // bline += "  ";
              // myGLCD.print(bline, 85, 204);
               
               myGLCD.setColor(0, 0, 128);
               myGLCD.fillRoundRect(280, 20, 319, 239);
               
               myGLCD.setFont(SmallFont);
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(285, 20, 319, 100);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("UP", 295, 55);
               
               myGLCD.setColor(255, 0, 0);
               myGLCD.fillRoundRect(285, 105, 319, 154);
               myGLCD.setColor(255, 255, 255);
               myGLCD.setBackColor(255, 0, 0);
               myGLCD.print("SND", 292, 123); 
               
               myGLCD.setColor(0, 255, 0);
               myGLCD.fillRoundRect(285, 159, 319, 239);
               myGLCD.setColor(0, 0, 0);
               myGLCD.setBackColor(0, 255, 0);
               myGLCD.print("DN", 295, 195);  
               
               tuneP = 0.0;
               tuneI = 0.0;
               tuneD = 0.0;
               tuneIMax = 0.0;
               ley = 0;
               return;
}

void AltTuneR()
{              
  int addr = 116;
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
                  //myGLCD.fillRect(179, (44 + (20 * (x+3))), 184, (64 + (20 * (x+3))));
                  break;
                }
                
              case 1:
                 {
                  myGLCD.setColor(0, 255, 0);
                  myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                  myGLCD.setColor(0, 0, 128);
                  myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                  myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                  //myGLCD.fillRect(179, (44 + (20 * (x+2))), 185, (64 + (20 * (x+2))));
                  break;
                 }
                 
              case 2:
                 {
                   myGLCD.setColor(0, 255, 0);
                   myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
                   myGLCD.setColor(0, 0, 128);
                   myGLCD.fillRect(179, (44 + (20 * (x-2))), 185, (64 + (20 * (x-2))));
                   myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
                   //myGLCD.fillRect(179, (44 + (20 * (x+1))), 185, (64 + (20 * (x+1))));
                   break; 
                 }
                 
              //case 3:
              //   {
              //     myGLCD.setColor(0, 255, 0);
              //     myGLCD.fillRect(179, (44 + (20 * x)), 184, (64 + (20 * x)));
              //     myGLCD.setColor(0, 0, 128);
              //     myGLCD.fillRect(179, (44 + (20 * (x-3))), 185, (64 + (20 * (x-3))));
              //     myGLCD.fillRect(179, (44 + (20 * (x-2))), 185, (64 + (20 * (x-2))));
              //     myGLCD.fillRect(179, (44 + (20 * (x-1))), 185, (64 + (20 * (x-1))));
              //    break;
              //   }
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
                 
              //case 2:
              //   {
              //     value = (tuneD + (((pot-512)/100.0)/2));
              //     break;
              //   }
                 
              case 2:
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
                
              //case 2:
              // {
              //   value = (tuneD - (((512-pot)/100.0)/2));
              //   if(value <0) value = 0.0;
              //   break;
              // }
               
              case 2:
               {
                 value = (tuneIMax - ((512-pot)/10.0));
                 if(value <0) value = 0.0;
                 break;
               }
            } 
        }     
    cmdSetParm((addr+x), value);
    //cmdSetParm((addr+x+4), value);
    
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
        for(int x; x < 2; x++)
        {
          value = EEPROM_readDouble((addr + x)*4);
          
          switch(x)
           {
            case 0:
             {
               tuneP = value;
               dtostrf(value, 4, 2, cFloat);
               bline = "tune P ";
               bline += cFloat;
               bline += "  ";
               Serial.println(bline);
               break;
             }
             
            case 1:
             {
               tuneI = value;
               dtostrf(value, 4, 2, cFloat);
               bline = "Tune I ";
               bline += cFloat;
               bline += "  ";
               Serial.println(bline);
               break;
             }
             
            //case 2:
            // {
            //   tuneD = value;
            //   dtostrf(value, 4, 2, cFloat);
            //   bline = "Tune D ";
            //   bline += cFloat;
            //   bline += "  ";
            //   Serial.println(bline);
            //   break;
            // }
             
            case 2:
             {
               tuneIMax = value;
               dtostrf(value, 4, 2, cFloat);
               bline = "Tune I Max ";
               bline += cFloat;
               bline += "  ";
               Serial.println(bline);
               break;
             }
           }
                   
           if(value > 65499.0) value = 65500.0;
           if(x != 3) dtostrf((value), 4, 2, cFloat);
           else dtostrf((value/100), 4, 2, cFloat);
           bline = " ";
           bline += cFloat;
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
           bline = " ";
           bline += cFloat;
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
           bline = " ";
           bline += cFloat;
           myGLCD.setFont(BigFont);
           myGLCD.setBackColor(0, 0, 128);
           myGLCD.setColor(255, 255, 255);
           myGLCD.print(bline, 185, (44 + (20 * x)));
        }
      }
  }
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
               myGLCD.print("Serial Passthrough", CENTER, 1);
               myGLCD.setFont(BigFont);
               myGLCD.setBackColor(0, 0, 128);
               SPT = true;
}

void SerialPassThruR()
{
   
}
  
