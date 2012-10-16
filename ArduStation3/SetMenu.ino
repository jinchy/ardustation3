
void SetMenu(int State, int Refresh)
{
  GoToMenu = State;
  if((CurrentMenu == GoToMenu) && Refresh == 0) return;   //We're on the menu that we want
  if(beLog) eLog.print("SetMenu(");
  if(beLog) eLog.print(CurrentMenu);
  if(beLog) eLog.print(", ");
  if(beLog) eLog.print(Refresh);
  if(beLog) eLog.println(")");
                    
    switch(State)
                {
                case 0: {
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
                           break;
                }
             
      case 1: {
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
                           break;
               }
               
       case 2: {
                         
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
                           break;
               }
      
       case 3: {
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
                           break;
                }
        
        case 4: {
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
                           break;
                }

        case 5: {
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
                           break;
                }
        
        case 6: {
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
                           break;
                }
        
        case 7: {
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
                           break;
                }
        
        case 8: {
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
                           break;
                }

        case 9: {
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
                           break;
                }

        case 10: {
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
                           break;
                }
 
       case 11: {
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
                           break;
                }
                
       case 12: {
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
                           break;
                }
                
       case 13: {
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
                           break;
                }

       case 14: {
                           if(Refresh == 0)
                                           {
                                            StabRTune();
                                            CurrentMenu = 14;
                                           }
                           if(Refresh == 1)
                                           {
                                            StabRTuneR();
                                            CurrentMenu = 14;
                                           }
                           break;
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
                           break;
                }
		 case 16: {
                           if(Refresh == 0)
                                           {
                                            StabTune();
                                            CurrentMenu = 16;
                                           }
                           if(Refresh == 1)
                                           {
                                            StabTuneR();
                                            CurrentMenu = 16;
                                           }
                           break;
                }
		
		 case 17: {
                           if(Refresh == 0)
                                           {
                                            SDMaint();
                                            CurrentMenu = 17;
                                           }
                           if(Refresh == 1)
                                           {
                                            SDMaintR();
                                            CurrentMenu = 17;
                                           }
                           break;
                   }

	      case 18: {
					       if(Refresh == 0)
                                           {
                                            FormatSD();
                                            CurrentMenu = 18;
                                           }
                           if(Refresh == 1)
                                           {
                                            FormatSDR();
                                            CurrentMenu = 18;
                                           }
                           break;
                   }

		  case 19: {
					       if(Refresh == 0)
                                           {
                                            StopLoggingSD();
                                            CurrentMenu = 19;
                                           }
                           if(Refresh == 1)
                                           {
                                            StopLoggingSDR();
                                            CurrentMenu = 19;
                                           }
                           break;
                   }
		 
		  case 20: {
					       if(Refresh == 0)
                                           {
                                            GSConfig();
                                            CurrentMenu = 20;
                                           }
                           if(Refresh == 1)
                                           {
                                            GSConfigR();
                                            CurrentMenu = 20;
                                           }
                           break;
                   }
      default: return;
  }
  
}

