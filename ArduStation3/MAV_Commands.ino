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
  mavlink_msg_command_long_pack(127, 0, &msg, received_sysid, 250, MAV_CMD_COMPONENT_ARM_DISARM, 1,1,0,0,0,0,0,0);
  send_message(&msg); 
}

void cmdSetComeHere(int alt)
{
  mavlink_message_t msg;
  //float flat;
  //float flon;
  //unsigned long age;
  
  //mavlink_msg_set_mode_pack(127, 0, &msg, received_sysid, 128, 0);
  // mavlink_msg_mission_item_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,uint8_t target_system, uint8_t target_component, 
  //uint16_t seq, uint8_t frame, uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, float x, float y, float z)
  gps.f_get_position(&flat, &flon, &age);
  //mavlink_msg_rc_channels_override_pack(127, 0, &msg,received_sysid,received_compid, seq, frame,MAV_CMD_NAV_WAYPOINT, 1, 0, p1, p2, p3, p4, ); 
  //send_message(&msg);  
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
    char PaName[16];
     PName(Parm).toCharArray(PaName, 16);
    //mav_array_memcpy(PaName, PName(Parm), sizeof(char)*16);
    mavlink_message_t msg;  
    mavlink_msg_param_set_pack(127, 0, &msg, received_sysid, received_compid, PaName, value, MAV_VAR_FLOAT);
    send_message(&msg);  
}
