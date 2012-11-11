
static bool feedgps()
{
  while (Serial2.available())
  {
    if (gps.encode(Serial2.read()))
      return true;
  }
  Serial2.flush();
  return false;
}
