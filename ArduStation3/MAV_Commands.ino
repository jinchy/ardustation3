void cmdSetStab()
{
  mavlink_message_t msg;
  mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 81, 0);
  send_message(&msg); 
}

void cmdSetLoiter()
{
  mavlink_message_t msg;
  mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 89, 5);
  send_message(&msg); 
}

void cmdSetOFLoiter()
{
  mavlink_message_t msg;
  mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 81, 10);
  send_message(&msg); 
}

void cmdSetRTL()
{
  mavlink_message_t msg;
  mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 89, 6);
  send_message(&msg); 
}

void cmdSetAltHold()
{
  mavlink_message_t msg;
  mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 81, 2);
  send_message(&msg); 
}

void cmdSetAuto()
{
  mavlink_message_t msg;
  mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 89, 3);
  send_message(&msg); 
}

void cmdSetGuided()
{
  mavlink_message_t msg;
  mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 89, 4);
  send_message(&msg); 
}

void cmdSetArm()
{
  mavlink_message_t msg;
  if((baseMode & 193) == 193)
                 {
					 mavlink_msg_command_long_pack(127, 0, &msg, received_sysid, 250, MAV_CMD_COMPONENT_ARM_DISARM, 1,0,0,0,0,0,0,0);
                 }
               
                 else
                 {
					mavlink_msg_command_long_pack(127, 0, &msg, received_sysid, 250, MAV_CMD_COMPONENT_ARM_DISARM, 1,1,0,0,0,0,0,0);
                 }
  
  send_message(&msg); 
}

void cmdSetComeHere(int alt)
{
  //float flat;
  //float flon;
  //unsigned long age;
  
  //mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 128, 0);
  // mavlink_msg_mission_item_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,uint8_t target_system, uint8_t target_component, 
  //uint16_t seq, uint8_t frame, uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, float x, float y, float z)
  //mavlink_msg_rc_channels_override_pack(127, 0, &msg,received_sysid,received_compid, seq, frame,MAV_CMD_NAV_WAYPOINT, 1, 0, p1, p2, p3, p4, ); 
  //send_message(&msg);  
 
  //int32_t lat = _local_gps_lat + offs_lat;
  //int32_t lon = _local_gps_lon + _offs_lon;
  // int32_t alt = _local_gps_altitude + _offs_altitude;
  //int32_t alt = _offs_altitude; /* assume above ground. (ArduCopter bug.) */

  //float x = &flat; //(float) lat / (float) 1e7; /* lat, lon in deg * 10,000,000 */
  //float y = &flon; //(float) lon / (float) 1e7;
  
  mavlink_message_t msg;
  if(beLog) eLog.println(P("FollowMe: Sending guide waypoint packet"));
  gps.f_get_position(&flat, &flon, &age); 
  float z = (float) alt / (float) 100; /* alt in cm */
  
  if(beLog) eLog.println(P("FollowMe: guide x: %f y: %f z: %f\r\n"));
  //    x, y, z);

  mavlink_msg_mission_item_pack(
      received_sysid, /* uint8_t target_system */
      received_sysid, /* uint8_t target_component */
      &msg, /*  */
	  127, //Target system
	  0, //Target Componant
      0, /* uint16_t seq: always 0, unknown why. */
      MAV_FRAME_GLOBAL, /* uint8_t frame: arducopter uninterpreted */
      MAV_CMD_NAV_WAYPOINT, /* uint16_t command: arducopter specific */
      2, /* uint8_t current: 2 indicates guided mode waypoint */
      0, /* uint8_t autocontinue: always 0 */
      0, /* float param1 : hold time in seconds */
      5, /* float param2 : acceptance radius in meters */
      0, /* float param3 : pass through waypoint */
      0, /* float param4 : desired yaw angle at waypoint */
      flat, /* float x : lat degrees */
      flon, /* float y : lon degrees */
      z  /* float z : alt meters */
      );
	send_message(&msg); 
}

void cmdCheckLimit()
{
  gps.f_get_position(&flat, &flon, &age); 
  if(calc_dist(latitude,longitude, flat, flon)> limitMeters)
  {
     cmdSetRTL();
  }
}

void cmdRequestParm()
{  
    mavlink_message_t msg;  
    mavlink_msg_param_request_list_pack(127, 0, &msg, received_sysid, received_compid);
    send_message(&msg);  
}

void cmdSetParm(int Parm, float value)
{  
    //char PaName[16];
    //strcpy(PaName, PName(Parm));
    mavlink_message_t msg;  
    mavlink_msg_param_set_pack(127, 0, &msg, received_sysid, received_compid, PName(Parm), value, MAV_VAR_FLOAT);
    send_message(&msg);  
}
