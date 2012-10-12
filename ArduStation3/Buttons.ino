void vButton()
{
  String TouchCo;

  TouchCo = "Touched X: "; 
  TouchCo += tx;
  TouchCo += " Y: ";
  TouchCo += ty;
  TouchCo += "      ";
  //myGLCD.setFont(SmallFont);
  eLog.println(TouchCo);

#ifdef DEBUG
//  if(CurrentMenu != 3)  myGLCD.print(TouchCo, LEFT, 214);
#endif
switch(CurrentMenu)
{
  case 0:
  {
    // 0 - Main Menu Buttons
      if(tx > 1704 && tx < 2711 && ty > 2880 && ty < 3643 && CurrentMenu == 0 && Touched == 0) 
        {
          SetMenu(1, 0);  //Setup Button - Main Menu
          Touched = 5;
          return;
        }
      
    if(tx > 527 && tx < 1554 && ty > 453 && ty < 1162 && CurrentMenu == 0 && Touched == 0) 
        {
          SetMenu(3, 0);  //HUD Button - Main Menu
          Touched = 5;
          return;
        }
      
     if(tx > 527 && tx < 1554 && ty > 1225 && ty < 1961 && CurrentMenu == 0 && Touched == 0) 
        {
          SetMenu(4, 0);  //Flight Map Button - Main Menu
          Touched = 5;
          return;
        }
     
    if(tx > 512 && tx < 1518 && ty > 2099 && ty < 2848 && CurrentMenu == 0 && Touched == 0) 
       { 
          SetMenu(6, 0);  //Follow Me Button - Main Menu
          Touched = 5;
          return;
       }

    if(tx > 580 && tx < 1539 && ty > 2918 && ty < 3690 && CurrentMenu == 0 && Touched == 0) 
       { 
          SetMenu(8, 0);  //Return to Main Menu from SetMode
          Touched = 5;
          return;
       }

    if(tx > 1666 && tx < 2688 && ty > 458 && ty < 1111 && CurrentMenu == 0 && Touched == 0) 
       {
          SetMenu(7, 0);  //Return to Main Menu from Setup
          Touched = 5;
          return;
       }
  }
 
 case 1:
 {
  // 1 - Setup Menu
    if(tx > 527 && tx < 1554 && ty > 453 && ty < 1162 && CurrentMenu == 1 && Touched == 0) 
        {
          SetMenu(2, 0);  //Debug Button - Main Menu
          Touched = 5;
          return;
        }

    if(tx > 580 && tx < 1539 && ty > 2918 && ty < 3690 && CurrentMenu == 1 && Touched == 0) 
        { 
          SetMenu(9, 0);  //tParm Menu
          Touched = 5;
          return;
        }
    
    if(tx > 1666 && tx < 2688 && ty > 458 && ty < 1111 && CurrentMenu == 1 && Touched == 0) 
        {
          //Loiter Tune
          SetMenu(15, 0);
          Touched = 5;
          return;
        }

	if(tx > 1740 && tx < 2688 && ty > 1232 && ty < 1996 && CurrentMenu == 1 && Touched == 0) 
        {
          //Loiter Tune
          SetMenu(17, 0);
          Touched = 5;
          return;
        }
    if(tx > 1704 && tx < 2711 && ty > 2880 && ty < 3643 && CurrentMenu == 1 && Touched == 0) 
        {
          SetMenu(0, 0);  //MainMenu
          Touched = 5;
          return;
        }
 }

 case 2:
  { 
    //2 - Debug1 Menu
    if(tx > 527 && tx < 3844 && ty > 453 && ty < 3843 && CurrentMenu == 2 && Touched == 0) 
       { 
          SetMenu(1, 0);  //Debug Button - Main Menu
          Touched = 5;
          return;
       }
  }
  
  case 3:
  {
    //3 - HUD Menu;
    if(tx > 527 && tx < 3844 && ty > 453 && ty < 3843 && CurrentMenu == 3 && Touched == 0) 
       { 
          SetMenu(0, 0);  //Return to Main Menu from HUD
          Touched = 5;
          return;
       }
  }
  
  case 4:
  {
   //4 - FlightMap Menu - Zoom
     if(tx > 513 && tx < 1527 && ty > 2099 && ty < 2803 && CurrentMenu == 4 && Touched == 0) 
       { 
          mapZoom += 0.1;
          SetMenu(4, 1);  //Debug Button - Main Menu
          Touched = 2;
          return;
       }
    
     if(tx > 1751 && tx < 2741 && ty > 2100 && ty < 2746 && CurrentMenu == 4 && Touched == 0) 
       { 
          mapZoom -= 0.1;
          SetMenu(4, 1);  //Debug Button - Main Menu
          Touched = 2;
          return;
       }
     
     if(tx > 589 && tx < 1500 && ty > 2850 && ty < 3547 && CurrentMenu == 4 && Touched == 0) 
       { 
          SetMenu(5, 0);  //Debug Button - Main Menu
          Touched = 5;
          return;
       }
  }
  
 case 5:
  {
    //5 - FlightMap Menu - Map
    if(tx > 527 && tx < 3844 && ty > 453 && ty < 3843 && CurrentMenu == 5 && Touched == 0) 
       { 
          SetMenu(0, 0);  //Return to Main Menu from Flight Map
          Touched = 5;
          return;
       }
  }
  
 case 6:
  {
    //6 - Follow Me       
     if(tx > 527 && tx < 3844 && ty > 453 && ty < 3843 && CurrentMenu == 6 && Touched == 0) 
       { 
          SetMenu(0, 0);  //Return to Main Menu from HUD
          Touched = 5;
          return;
       }
  }
  
  case 7:
  {
    //7 SetMode 
    if(tx > 1704 && tx < 2711 && ty > 2880 && ty < 3643 && CurrentMenu == 7 && Touched == 0) 
       { 
          SetMenu(0, 0);  //Return to Main Menu from SetMode
          Touched = 5;
          return;
       }
     
    if(tx > 527 && tx < 1554 && ty > 453 && ty < 1162 && CurrentMenu == 7 && Touched == 0) 
        {
          cmdSetStab();
          Touched = 5;
          return;
        }
      
    if(tx > 527 && tx < 1554 && ty > 1225 && ty < 1961 && CurrentMenu == 7 && Touched == 0) 
        {
          cmdSetLoiter();
          Touched = 5;
          return;
        }
     
    if(tx > 512 && tx < 1518 && ty > 2099 && ty < 2848 && CurrentMenu == 7 && Touched == 0) 
       { 
          cmdSetAuto();
          Touched = 5;
          return;
       }
     
    if(tx > 512 && tx < 1518 && ty > 2891 && ty < 3687 && CurrentMenu == 7 && Touched == 0) 
       { 
          cmdSetRTL();
          Touched = 5;
          return;
       }
  
    if(tx > 1666 && tx < 2688 && ty > 458 && ty < 1111 && CurrentMenu == 7 && Touched == 0) 
        {
          cmdSetAltHold();
          Touched = 5;
          return;
        }
  
    if(tx > 1666 && tx < 2688 && ty > 1237 && ty < 1975 && CurrentMenu == 7 && Touched == 0) 
        {
          cmdSetGuided();
          Touched = 5;
          return;
        }
   
     if(tx > 1666 && tx < 2688 && ty > 2074 && ty < 2426 && CurrentMenu == 7 && Touched == 0) 
        {
          cmdSetArm();
          Touched = 5;
          return;
        }
  }
  
  case 8:
  {
   //8 SetLimit Menu         
     if(tx > 844 && tx < 1852 && ty > 652 && ty < 1232 && CurrentMenu == 8 && Touched == 0) 
       { 
          softLimitMeters += 1;
          if(softLimitMeters > limitMeters) softLimitMeters = limitMeters;
          SetMenu(8, 1);  //Debug Button - Main Menu
          return;
       }
     
     if(tx > 844 && tx < 1852 && ty > 1339 && ty < 2066 && CurrentMenu == 8 && Touched == 0) 
       { 
          softLimitMeters -= 1;
          if(softLimitMeters > limitMeters) softLimitMeters = limitMeters;
          SetMenu(8, 1);  //Debug Button - Main Menu
          return;
       }
     
     if(tx > 2416 && tx < 3394 && ty > 476 && ty < 1221 && CurrentMenu == 8 && Touched == 0) 
       { 
          limitMeters += 1;
          SetMenu(8, 1);  //Debug Button - Main Menu
          return;
       }
     
     if(tx > 2420 && tx < 3389 && ty > 1353 && ty < 2039 && CurrentMenu == 8 && Touched == 0) 
       { 
          limitMeters -= 1;
          SetMenu(8, 1);  //Debug Button - Main Menu
          return;
       }
     
     if(tx > 547 && tx < 1548 && ty > 2905 && ty < 3793 && CurrentMenu == 8 && Touched == 0) 
       { 
          SetMenu(0, 0);  //Debug Button - Main Menu
          Touched = 5;
          return;
       }
  }
  
  case 9:
  {
  //9 Parameter Page 1
    if(tx > 1704 && tx < 2711 && ty > 2880 && ty < 3643 && CurrentMenu == 9 && Touched == 0) 
       { 
          SetMenu(11, 0);  //Browse Parameters
          Touched = 5;
          return;
       }
       
    if(tx > 527 && tx < 1554 && ty > 453 && ty < 1162 && CurrentMenu == 9 && Touched == 0) 
        {
          //Sensors
          //cmdSetStab();
          Touched = 5;
          return;
        }
        
    if(tx > 527 && tx < 1554 && ty > 1225 && ty < 1961 && CurrentMenu == 9 && Touched == 0) 
        {
          //Modes
          //cmdSetLoiter();
          Touched = 5;
          return;
        }
       
    if(tx > 512 && tx < 1518 && ty > 2099 && ty < 2848 && CurrentMenu == 9 && Touched == 0) 
       { 
          //Stab Tune
          SetMenu(16, 0);
          Touched = 5;
          return;
       }
       
    if(tx > 512 && tx < 1518 && ty > 2891 && ty < 3687 && CurrentMenu == 9 && Touched == 0) 
       { 
          //Stab Rate Tune
          SetMenu(14, 0);
          Touched = 5;
          return;
       }
    
    if(tx > 1666 && tx < 2688 && ty > 458 && ty < 1111 && CurrentMenu == 9 && Touched == 0) 
        {
          //Loiter Tune
          SetMenu(12, 0);
          Touched = 5;
          return;
        }
    
    if(tx > 1666 && tx < 2688 && ty > 1237 && ty < 1975 && CurrentMenu == 9 && Touched == 0) 
        {
          //Nav Tune
          //cmdSetGuided();
          SetMenu(13, 0);
          Touched = 5;
          return;
        }
     
     if(tx > 1666 && tx < 2688 && ty > 2074 && ty < 2426 && CurrentMenu == 9 && Touched == 0) 
        {
          //TBA - Arm
          //cmdSetArm();
          Touched = 5;
          return;
        }
  
     if(tx > 2930 && tx < 3779 && ty > 1648 && ty < 2324 && CurrentMenu == 9 && Touched == 0) 
        {
          //Main Menu
          SetMenu(1, 0); //back to setup
          Touched = 5;
          return;
        }
      
      if(tx > 2864 && tx < 3720 && ty > 520 && ty < 1497 && CurrentMenu == 9 && Touched == 0) 
        {
          //Down
          SetMenu(10, 0); //back to setup
          Touched = 5;
          return;
        }
  }
  
  case 10:
  {
    //10 Parameter Page 2
    if(tx > 1704 && tx < 2711 && ty > 2880 && ty < 3643 && CurrentMenu == 10 && Touched == 0) 
       { 
          //SetMenu(0, 0);  //Return to Main Menu from SetMode
          Touched = 5;
          return;
       }
       
    if(tx > 527 && tx < 1554 && ty > 453 && ty < 1162 && CurrentMenu == 10 && Touched == 0) 
        {
          //Sensors
          //cmdSetStab();
          Touched = 5;
          return;
        }
        
    if(tx > 527 && tx < 1554 && ty > 1225 && ty < 1961 && CurrentMenu == 10 && Touched == 0) 
        {
          //Modes
          //cmdSetLoiter();
          Touched = 5;
          return;
        }
       
    if(tx > 512 && tx < 1518 && ty > 2099 && ty < 2848 && CurrentMenu == 10 && Touched == 0) 
       { 
          //Waypoint
          //cmdSetAuto();
          Touched = 5;
          return;
       }
       
    if(tx > 512 && tx < 1518 && ty > 2891 && ty < 3687 && CurrentMenu == 10 && Touched == 0) 
       { 
          //Stab Tune
          //cmdSetRTL();
          Touched = 5;
          return;
       }
    
    if(tx > 1666 && tx < 2688 && ty > 458 && ty < 1111 && CurrentMenu == 10 && Touched == 0) 
        {
          //Loiter Tune
          //SetMenu(12, 0);
          Touched = 5;
          return;
        }
    
    if(tx > 1666 && tx < 2688 && ty > 1237 && ty < 1975 && CurrentMenu == 10 && Touched == 0) 
        {
          //Nav Tune
          //cmdSetGuided();
          Touched = 5;
          return;
        }
     
     if(tx > 1666 && tx < 2688 && ty > 2074 && ty < 2426 && CurrentMenu == 10 && Touched == 0) 
        {
          //TBA - Arm
          //cmdSetArm();
          Touched = 5;
          return;
        }
  
     if(tx > 2930 && tx < 3779 && ty > 1648 && ty < 2324 && CurrentMenu == 10 && Touched == 0) 
        {
          //Main Menu
          SetMenu(1, 0); //back to setup
          Touched = 5;
          return;
        }
      
      if(tx > 2864 && tx < 3720 && ty > 520 && ty < 1497 && CurrentMenu == 10 && Touched == 0) 
        {
          //Down
          SetMenu(10, 0); //back to setup
          Touched = 5;
          return;
        }
      
      
      if(tx > 2864 && tx < 3720 && ty > 2849 && ty < 3667 && CurrentMenu == 10 && Touched == 0) 
        {
          //Down
          SetMenu(9, 0); //back to setup
          Touched = 5;
          return;
        }
  }
  
  case 11:
  {
    //11 Browse Parameters         
    if(tx > 428 && tx < 3734 && ty > 336 && ty < 3368 && CurrentMenu == 11 && Touched == 0) 
       { 
          SetMenu(9, 0);  //Return to Back to Setup
          Touched = 5;
          return;
       }
       
    if(tx > 555 && tx < 1715 && ty > 3502 && ty < 3831 && CurrentMenu == 11 && Touched == 0) 
       { 
          if(lsy > 0)
          {
            ley -= 10;
            lsy -= 10;
            if(lsy < 1) lsy = 0;
          }
          //Touched = 5;
          SetMenu(11, 1);  //tParm Menu
          return;
       }
  
    if(tx > 2421 && tx < 3464 && ty > 3502 && ty < 3831 && CurrentMenu == 11 && Touched == 0) 
       { 
          if(ley < 251)
          {
            ley += 10;
            lsy += 10;
            if(ley >250) lsy = 250;
          }
          //Touched = 5;
          SetMenu(11, 1);  //tParm Menu
          return;
       }
  }
  
  case 12:
    {
      //12 Tune Loiter
    if(tx > 555 && tx < 1651 && ty > 3502 && ty < 3755 && CurrentMenu == 12 && Touched == 0) 
       {
          if(ley != 0) ley--;
          Touched = 5;
          SetMenu(12, 1);  //tParm Menu
          return;
       }
  
    if(tx > 2674 && tx < 3846 && ty > 3502 && ty < 3831 && CurrentMenu == 12 && Touched == 0) 
       { 
          ley++;
          if(ley > 4) ley = 4;
          Touched = 5;
          SetMenu(12, 1);  //tParm Menu
          return;
       }
    
    if(tx > 1873 && tx < 2523 && ty > 3487 && ty < 3747 && CurrentMenu == 12 && Touched == 0) 
       { 
          pSend = true;
          SetMenu(12, 1);  //tParm Menu
          return;
       }
       
    if(tx > 428 && tx < 3801 && ty > 368 && ty < 3397 && CurrentMenu == 12 && Touched == 0) 
       { 
          //pSend = true;
          SetMenu(9, 0);  //tParm Menu
          return;
       }
    }
  case 13:
    {
      //13 Tune Nav
    if(tx > 555 && tx < 1651 && ty > 3502 && ty < 3755 && CurrentMenu == 13 && Touched == 0) 
       {
          if(ley != 0) ley--;
          Touched = 5;
          SetMenu(13, 1);  //tParm Menu
          return;
       }
  
    if(tx > 2674 && tx < 3846 && ty > 3502 && ty < 3831 && CurrentMenu == 13 && Touched == 0) 
       { 
          ley++;
          if(ley > 4) ley = 4;
          Touched = 5;
          SetMenu(13, 1);  //tParm Menu
          return;
       }
    
    if(tx > 1873 && tx < 2523 && ty > 3487 && ty < 3747 && CurrentMenu == 13 && Touched == 0) 
       { 
          pSend = true;
          SetMenu(13, 1);  //tParm Menu
          return;
       }
       
    if(tx > 428 && tx < 3801 && ty > 368 && ty < 3397 && CurrentMenu == 13 && Touched == 0) 
       { 
          //pSend = true;
          SetMenu(9, 0);  //tParm Menu
          return;
       }
    }
    case 14:
    {
      //13 Tune Stab
    if(tx > 555 && tx < 1651 && ty > 3502 && ty < 3755 && CurrentMenu == 14 && Touched == 0) 
       {
          if(ley != 0) ley--;
          Touched = 5;
          SetMenu(14, 1);  //tParm Menu
          return;
       }
  
    if(tx > 2674 && tx < 3846 && ty > 3502 && ty < 3831 && CurrentMenu == 14 && Touched == 0) 
       { 
          ley++;
          if(ley > 4) ley = 4;
          Touched = 5;
          SetMenu(14, 1);  //tParm Menu
          return;
       }
    
    if(tx > 1873 && tx < 2523 && ty > 3487 && ty < 3747 && CurrentMenu == 14 && Touched == 0) 
       { 
          pSend = true;
          SetMenu(14, 1);  //tParm Menu
          return;
       }
       
    if(tx > 428 && tx < 3801 && ty > 368 && ty < 3397 && CurrentMenu == 14 && Touched == 0) 
       { 
          //pSend = true;
          SetMenu(9, 0);  //tParm Menu
          return;
       }
    }
   
   case 15:
    {
      //15 Tune Alt
    if(tx > 555 && tx < 1651 && ty > 3502 && ty < 3755 && CurrentMenu == 15 && Touched == 0) 
       {
          if(ley != 0) ley--;
          Touched = 5;
          SetMenu(14, 1);  //tParm Menu
          return;
       }
  
    if(tx > 2674 && tx < 3846 && ty > 3502 && ty < 3831 && CurrentMenu == 15 && Touched == 0) 
       { 
          ley++;
          if(ley > 4) ley = 4;
          Touched = 5;
          SetMenu(14, 1);  //tParm Menu
          return;
       }
    
    if(tx > 1873 && tx < 2523 && ty > 3487 && ty < 3747 && CurrentMenu == 15 && Touched == 0) 
       { 
          pSend = true;
          SetMenu(14, 1);  //tParm Menu
          return;
       }
       
    if(tx > 428 && tx < 3801 && ty > 368 && ty < 3397 && CurrentMenu == 15 && Touched == 0) 
       { 
          //pSend = true;
          SetMenu(9, 0);  //tParm Menu
          return;
       }
    }

	case 16:
    {
      //13 Tune Stab
    if(tx > 555 && tx < 1651 && ty > 3502 && ty < 3755 && CurrentMenu == 16 && Touched == 0) 
       {
          if(ley != 0) ley--;
          Touched = 5;
          SetMenu(16, 1);  //tParm Menu
          return;
       }
  
    if(tx > 2674 && tx < 3846 && ty > 3502 && ty < 3831 && CurrentMenu == 16 && Touched == 0) 
       { 
          ley++;
          if(ley > 4) ley = 4;
          Touched = 5;
          SetMenu(16, 1);  //tParm Menu
          return;
       }
    
    if(tx > 1873 && tx < 2523 && ty > 3487 && ty < 3747 && CurrentMenu == 16 && Touched == 0) 
       { 
          pSend = true;
          SetMenu(16, 1);  //tParm Menu
          return;
       }
       
    if(tx > 428 && tx < 3801 && ty > 368 && ty < 3397 && CurrentMenu == 16 && Touched == 0) 
       { 
          //pSend = true;
          SetMenu(9, 0);  //tParm Menu
          return;
       }
    }

	case 17:
	{
	 // 0 - Main Menu Buttons
		 
	 if(tx > 1704 && tx < 2711 && ty > 2880 && ty < 3643 && CurrentMenu == 17 && Touched == 0) 
        {
          SetMenu(1, 0);  //Setup Button - Main Menu
          Touched = 5;
          return;
        }
      
    if(tx > 527 && tx < 1554 && ty > 453 && ty < 1162 && CurrentMenu == 17 && Touched == 0) 
        {
          //SetMenu(3, 0);  //HUD Button - Main Menu
          Touched = 5;
          return;
        }
      
     if(tx > 527 && tx < 1554 && ty > 1225 && ty < 1961 && CurrentMenu == 17 && Touched == 0) 
        {
          SetMenu(19, 0);  //Flight Map Button - Main Menu
          Touched = 5;
          return;
        }
     
    if(tx > 512 && tx < 1518 && ty > 2099 && ty < 2848 && CurrentMenu == 17 && Touched == 0) 
       { 
          //SetMenu(6, 0);  //Follow Me Button - Main Menu
          Touched = 5;
          return;
       }

    if(tx > 580 && tx < 1539 && ty > 2918 && ty < 3690 && CurrentMenu == 17 && Touched == 0) 
       { 
          //SetMenu(8, 0);  //Return to Main Menu from SetMode
          Touched = 5;
          return;
       }

    if(tx > 1666 && tx < 2688 && ty > 458 && ty < 1111 && CurrentMenu == 17 && Touched == 0) 
       {
          SetMenu(18, 0);  //Format SD
          Touched = 5;
          return;
       }
	  }

case 18:
  {
    //6 - Follow Me       
     if(tx > 527 && tx < 3844 && ty > 453 && ty < 3843 && CurrentMenu == 18 && Touched == 0) 
       { 
          SetMenu(17, 0);  //Return to Main Menu from HUD
          Touched = 5;
          return;
       }
  }

case 19:
  {
    //6 - Follow Me       
     if(tx > 527 && tx < 3844 && ty > 453 && ty < 3843 && CurrentMenu == 19 && Touched == 0) 
       { 
          SetMenu(17, 0);  //Return to Main Menu from HUD
          Touched = 5;
          return;
       }
  }
  }
}


