void gcs_handleMessage(mavlink_message_t* msg)
{
  //      current=packet.PwCons
  switch (msg->msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
    {
      mavlink_heartbeat_t packet;
      mavlink_msg_heartbeat_decode(msg, &packet);
      droneType = packet.type; // Don't pick up from the heartbeat now since there is some weirdness when the Planner is running
                                 // and ArduPlane is running (get packet with type = 1 and type =0 also - confused this logic) 
                                  
      autoPilot = packet.autopilot;
      if ((*msg).sysid != 0xff) // do not process mission planner heartbeats if we have two receiver xbees
      {
        received_sysid = (*msg).sysid; // save the sysid and compid of the received heartbeat for use in sending new messages
      
        received_compid = (*msg).compid;
      
#ifdef  MAVLINK10
        if (droneType == MAV_TYPE_FIXED_WING) {
#else // MAVLINK10
        if (droneType == MAV_FIXED_WING ) {
#endif // MAVLINK10

          TOTAL_PARAMS = 37;
          
#ifdef MAVLINK10
        } else if (droneType == MAV_TYPE_GENERIC) {
#else // MAVLINK10
        } else if (droneType == MAV_GENERIC) {
#endif // MAVLINK10

          TOTAL_PARAMS = 51;
        } else {
          TOTAL_PARAMS = 51;
        }
      }
      beat = 1;
      break;
    }


    
   case MAVLINK_MSG_ID_ATTITUDE:
    {
      // decode
      mavlink_attitude_t packet;
      mavlink_msg_attitude_decode(msg, &packet);
      pitch = toDeg(packet.pitch);
      yaw = toDeg(packet.yaw);
      roll = toDeg(packet.roll);
      break;
    }
#ifdef MAVLINK10
    case MAVLINK_MSG_ID_GPS_RAW_INT:
#else // MAVLINK10
    case MAVLINK_MSG_ID_GPS_RAW:
#endif // MAVLINK10

    {
      // decode

#ifdef MAVLINK10
      mavlink_gps_raw_int_t packet;
      mavlink_msg_gps_raw_int_decode(msg, &packet);
      velocity = packet.vel;
      latitude = packet.lat/1e7;
      longitude = packet.lon/1e7;
      altitude = packet.alt/1000.0;
#else // MAVLINK10
      mavlink_gps_raw_t packet;
      mavlink_msg_gps_raw_decode(msg, &packet); 
      velocity = packet.v; 
      latitude = packet.lat;
      longitude = packet.lon; 
      altitude = packet.alt;   
#endif // MAVLINK10
//      position_antenna();
      gpsfix = packet.fix_type;
      break;
    }
    case MAVLINK_MSG_ID_GPS_STATUS:
    {
      mavlink_gps_status_t packet;
      mavlink_msg_gps_status_decode(msg, &packet);        
      numSats = packet.satellites_visible;
      break;
    }
    case MAVLINK_MSG_ID_RAW_PRESSURE:
    {
      // decode
      mavlink_raw_pressure_t packet;
      mavlink_msg_raw_pressure_decode(msg, &packet);
      break;
    }
    case MAVLINK_MSG_ID_SYS_STATUS:
    {

      mavlink_sys_status_t packet;
      mavlink_msg_sys_status_decode(msg, &packet);
#ifdef MAVLINK10
      battery = packet.voltage_battery;
      current = packet.current_battery;
      RemainingBat = packet.battery_remaining;
      SensorHelth = packet.onboard_control_sensors_health;
      SensorsPresent = packet.onboard_control_sensors_present;
      SensorsEnabled = packet.onboard_control_sensors_enabled;
 
#else // MAVLINK10
      currentSMode = packet.mode;
      currentNMode = packet.nav_mode;
      battery = packet.vbat;
      
      
#endif // MAVLINK10
      break;
    }
    case MAVLINK_MSG_ID_PARAM_VALUE:
    {
      // decode
      mavlink_param_value_t packet;
      mavlink_msg_param_value_decode(msg, &packet);
      const char * key = (const char*) packet.param_id;
      int loc = find_param(key);

      if (loc != -1)
      {
        float value;
        parameter temp;
        //strcpy(temp.key, key);
        //temp.value = packet.param_value;
        value = packet.param_value;
        EEPROM_writeFloat((loc * sizeof(temp))+sizeof(temp.key), value);         
        //EEPROM_writeParameter((loc * sizeof(temp))+sizeof(temp.key), temp);         
        paramsRecv++;
      }
      if (waitingAck == 1)
      {        
        if (strcmp(key, editParm.key) == 0)
        {
          waitingAck = 0;
        }
      }
      //else
      //  timeOut = 100; // each time we get another parameter reset the timeout
      //redraw = 1;
      break;
    }
  }
}

void send_message(mavlink_message_t* msg)
{
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  
//  Serial.write(MAVLINK_STX);
//  Serial.write(msg->len);
//  Serial.write(msg->seq);
//  Serial.write(msg->sysid);
//  Serial.write(msg->compid);
//  Serial.write(msg->msgid);
  uint16_t len = mavlink_msg_to_send_buffer(buf, msg);
  for(uint16_t i = 0; i < len; i++)
  {
    Serial1.write(buf[i]);
  }
//  Serial.write(msg->ck_a);
//  Serial.write(msg->ck_b);
}

void gcs_update()
{
    // receive new packets
    mavlink_message_t msg;
    mavlink_status_t *status;

    // process received bytes
    while(Serial1.available())
    {
        uint8_t c = Serial1.read();
        // Have a byte - check if we are parsing, if we are there should not be a large time since last parsed byte
        // if there is too much time, we lost message bytes so abort the previous parse and start fresh on this new
        // message.
        status = mavlink_get_channel_status(0);
        if (status->parse_state != MAVLINK_PARSE_STATE_IDLE)
        {
           if (timeLastByte != 0)
             if ((millis() - timeLastByte) > maxByteTime)
               maxByteTime = millis()-timeLastByte;
           if ((millis() - timeLastByte) > 300)  // .3 seconds
           {
             timeLastByte = 0; // We're going back to idle since we're aborting
             status->parse_state = MAVLINK_PARSE_STATE_IDLE; // abort the parse - start fresh with the current received byte
           }
           else
              timeLastByte = millis(); // Update the time to that of the current byte
        }
       
        
        // Wrong Mavlink detector.  Separately parse messages with wrong packet start sign
        // Mavlink 1.0 expects first byte of 0xFE
        // Mavlink 0.9 expects first byte of 0x55

        // Look for 0x55 with right format - 0x55 0x03 0xignore 0xignore 0xignore 0x00    - Mavlink 0.9 heartbeat 
        // Look for 0xFE with right format - 0xFE 0x08 0xignore 0xignore 0xignore 0x00    - Mavlink 1.0 heartbeat
        switch (wrongMavlinkState)
        {
            case 0:
#ifdef MAVLINK10
               if (c== 0x55) {
#else // MAVLINK10
               if (c== 0xFE) {
#endif // MAVLINK10
                  packetStartByte = c;
                  wrongMavlinkState = 1;
               }
               break;
            
            case 1: 
#ifdef MAVLINK10
               if (c== 0x03)
#else // MAVLINK10
               if (c== 0x09)
#endif // MAVLINK10
                  wrongMavlinkState = 2;
               else 
               {
                  packetStartByte = 0;
                  wrongMavlinkState = 0;
               }
               break;
            case 2:
            case 3:
            case 4:
               wrongMavlinkState++;
               break;
               
            case 5:
               if (c == 0x00)
               {
                 wrongMavlinkState = 6;
               }
               else
               {
                  wrongMavlinkState = 0;
                  packetStartByte = 0;
               }
               break;
            }
        
                   
                 
        // Try to get a new message
        if(mavlink_parse_char(0, c, &msg, status)) gcs_handleMessage(&msg);
        // If time value is 0 we were in idle, check if not in idle and receiving message bytes
        if (timeLastByte == 0)
        {
          if (status->parse_state != MAVLINK_PARSE_STATE_IDLE) 
          {
            timeLastByte = millis(); // Save current time since start run - compared when receiving bytes
          } 
        }
    }
}

void start_feeds()
{
  Serial.println("Starting feeds!");
  mavlink_message_t msg;
  mavlink_msg_request_data_stream_pack(127, 0, &msg, received_sysid, received_compid, MAV_DATA_STREAM_RAW_SENSORS, MAV_DATA_STREAM_RAW_SENSORS_RATE, MAV_DATA_STREAM_RAW_SENSORS_ACTIVE);
  send_message(&msg);
  delay(10);
//  mavlink_message_t msg3;
  mavlink_msg_request_data_stream_pack(127, 0, &msg, received_sysid, received_compid, MAV_DATA_STREAM_EXTENDED_STATUS, MAV_DATA_STREAM_EXTENDED_STATUS_RATE, MAV_DATA_STREAM_EXTENDED_STATUS_ACTIVE);
  send_message(&msg);
  delay(10);
//  mavlink_message_t msg4;
  mavlink_msg_request_data_stream_pack(127, 0, &msg, received_sysid, received_compid, MAV_DATA_STREAM_RAW_CONTROLLER, MAV_DATA_STREAM_RAW_CONTROLLER_RATE, MAV_DATA_STREAM_RAW_CONTROLLER_ACTIVE);
  send_message(&msg);
  delay(10);
//  mavlink_message_t msg1;
  mavlink_msg_request_data_stream_pack(127, 0, &msg, received_sysid, received_compid, MAV_DATA_STREAM_POSITION, MAV_DATA_STREAM_POSITION_RATE, MAV_DATA_STREAM_POSITION_ACTIVE);
  send_message(&msg);
  delay(10);
//  mavlink_message_t msg5;
  mavlink_msg_request_data_stream_pack(127, 0, &msg, received_sysid, received_compid, MAV_DATA_STREAM_EXTRA1, MAV_DATA_STREAM_EXTRA1_RATE, MAV_DATA_STREAM_EXTRA1_ACTIVE);
  send_message(&msg);
  delay(460);
}

void stop_feeds()
{
  Serial.println("Stopping feeds!");
  mavlink_message_t msg1;
  mavlink_msg_request_data_stream_pack(127, 0, &msg1, received_sysid, received_compid, MAV_DATA_STREAM_ALL, 0, 0);
  send_message(&msg1);
  delay(500);
}
