
void SetMenu(int State, int Refresh)
{
  GoToMenu = State;
  if((CurrentMenu == GoToMenu) && Refresh == 0) return;   //We're on the menu that we want

    switch(State)
                {
                case 0: {
#ifdef DEBUG
//                           Serial.println("Main Menu");
#endif
                           if(Refresh == 0)
                                           {
                                            MainMenu();
                                            CurrentMenu = 0;
                                           }
                           if(Refresh == 1)
                                           {
                                            MainMenuR();
                                            CurrentMenu = 0;
                                           }
                           return;
                }
             
      case 1: {
#ifdef DEBUG
//               Serial.println("Setup Menu");
#endif                           
              if(Refresh == 0)
                                           {
                                            Setup1();
                                            CurrentMenu = 1;
                                           }
                           if(Refresh == 1)
                                           {
                                            Setup1R();
                                            CurrentMenu = 1;
                                           }
                           return;
               }
               
       case 2: {
#ifdef DEBUG
//               Serial.println("Setup Menu");
#endif                           
              if(Refresh == 0)
                                           {
                                            Debug1();
                                            CurrentMenu = 2;
                                           }
                           if(Refresh == 1)
                                           {
                                            Debug1R();
                                            CurrentMenu = 2;
                                           }
                           return;
               }
      
       case 3: {
#ifdef DEBUG
//                           Serial.println("HUD");
#endif
                           if(Refresh == 0)
                                           {
                                            HUD();
                                            CurrentMenu = 3;
                                           }
                           if(Refresh == 1)
                                           {
                                            HUDR();
                                            CurrentMenu = 3;
                                           }
                           return;
                }
        
        case 4: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            FlightMapM();
                                            CurrentMenu = 4;
                                           }
                           if(Refresh == 1)
                                           {
                                            FlightMapMR();
                                            CurrentMenu = 4;
                                           }
                           return;
                }

        case 5: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            FlightMap();
                                            CurrentMenu = 5;
                                           }
                           if(Refresh == 1)
                                           {
                                            FlightMapR();
                                            CurrentMenu = 5;
                                           }
                           return;
                }
        
        case 6: {
#ifdef DEBUG
//                           Serial.println("Follow Me");
#endif
                           if(Refresh == 0)
                                           {
                                            FollowMe();
                                            CurrentMenu = 6;
                                           }
                           if(Refresh == 1)
                                           {
                                            FollowMeR();
                                            CurrentMenu = 6;
                                           }
                           return;
                }
        
        case 7: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            SetMode();
                                            CurrentMenu = 7;
                                           }
                           if(Refresh == 1)
                                           {
                                            SetModeR();
                                            CurrentMenu = 7;
                                           }
                           return;
                }
        
        case 8: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            SetLimitM();
                                            CurrentMenu = 8;
                                           }
                           if(Refresh == 1)
                                           {
                                            SetLimitR();
                                            CurrentMenu = 8;
                                           }
                           return;
                }

        case 9: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            ParamMainP1();
                                            CurrentMenu = 9;
                                           }
                           if(Refresh == 1)
                                           {
                                            ParamMainR();
                                            CurrentMenu = 9;
                                           }
                           return;
                }

        case 10: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            ParamMainP2();
                                            CurrentMenu = 10;
                                           }
                           if(Refresh == 1)
                                           {
                                            ParamMainR();
                                            CurrentMenu = 10;
                                           }
                           return;
                }
 
       case 11: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            ParmM();
                                            CurrentMenu = 11;
                                           }
                           if(Refresh == 1)
                                           {
                                            ParmR();
                                            CurrentMenu = 11;
                                           }
                           return;
                }
                
       case 12: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            LoiterTune();
                                            CurrentMenu = 12;
                                           }
                           if(Refresh == 1)
                                           {
                                            LoiterTuneR();
                                            CurrentMenu = 12;
                                           }
                           return;
                }
                
       case 13: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            NavTune();
                                            CurrentMenu = 13;
                                           }
                           if(Refresh == 1)
                                           {
                                            NavTuneR();
                                            CurrentMenu = 13;
                                           }
                           return;
                }

       case 14: {
#ifdef DEBUG
//                           Serial.println("FlightMap");
#endif
                           if(Refresh == 0)
                                           {
                                            StabTune();
                                            CurrentMenu = 14;
                                           }
                           if(Refresh == 1)
                                           {
                                            StabTuneR();
                                            CurrentMenu = 14;
                                           }
                           return;
                }
                
         case 15: {
                           if(Refresh == 0)
                                           {
                                            SerialPassThru();
                                            CurrentMenu = 15;
                                           }
                           if(Refresh == 1)
                                           {
                                            SerialPassThruR();
                                            CurrentMenu = 15;
                                           }
                           return;
                }

      default: return;
  }
  
}

