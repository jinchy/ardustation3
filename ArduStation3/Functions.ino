float rBearing()
{

  float dYaw;
  
  unsigned long age;
  
  gps.f_get_position(&flat, &flon, &age); 
  
  if(yaw<1)
  {
    dYaw = 360 + yaw;
  }
  
  else
  {
   dYaw = yaw;
  }
  
  return dYaw-calc_bearing(latitude, longitude, flat, flon);
}

int freeRam()
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

