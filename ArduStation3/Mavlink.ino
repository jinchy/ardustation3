void gcs_update()
{
    // receive new packets
    mavlink_message_t msg;
    mavlink_status_t *status;
    
#ifdef DEBUG_MAV
    Serial.println("GCS Update");    
#endif	
    // process received bytes
    while(Serial1.available())
    {
        uint8_t c = Serial1.read();
		tLog.write(c);
#ifdef DEBUG_MAV
//        Serial.print(".");    
#endif	
        // Have a byte - check if we are parsing, if we are there should not be a large time since last parsed byte
        // if there is too much time, we lost message bytes so abort the previous parse and start fresh on this new
        // message.
        status = mavlink_get_channel_status(0);
        if (status->parse_state != MAVLINK_PARSE_STATE_IDLE)
        {
#ifdef DEBUG_MAV
         // Serial.print("NI");    
#endif	
           if (timeLastByte != 0)
             if ((millis() - timeLastByte) > maxByteTime)
               maxByteTime = millis()-timeLastByte;
           if ((millis() - timeLastByte) > 300)  // .3 seconds
           {
#ifdef DEBUG_MAV
          Serial.print("A");    
#endif	
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
               if (c== 0x55) {
                  packetStartByte = c;
                  wrongMavlinkState = 1;
#ifdef DEBUG_MAV
                  Serial.print("WS1");    
#endif	
               }
               break;
            
            case 1: 
               if (c== 0x03)
               {
                  wrongMavlinkState = 2;
#ifdef DEBUG_MAV
                  Serial.print("WS2");    
#endif
               }
               
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
#ifdef DEBUG_MAV
                  Serial.print("WS6");    
#endif
               }
               else
               {
                  wrongMavlinkState = 0;
                  packetStartByte = 0;
               }
               break;
            }

#ifdef DEBUG_MAV
                  //Serial.print("Try ");    
                  //Serial.write();
#endif        
                   
        // gcs_handleMessage(&msgx);        
        // Try to get a new message
        if(mavlink_parse_char(0, c, &msg, status)) 
        {
#ifdef DEBUG_MAV
                  Serial.println("Handle Message");    
#endif
         gcs_handleMessage(&msg);
        }
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

void gcs_handleMessage(mavlink_message_t* msg)
{
  switch (msg->msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
    {
#ifdef DEBUG_MAV
    Serial.println("Heartbeat");    
#endif	
      mavlink_heartbeat_t packet;
      mavlink_msg_heartbeat_decode(msg, &packet);
      droneType = packet.type; // Don't pick up from the heartbeat now since there is some weirdness when the Planner is running
                                 // and ArduPlane is running (get packet with type = 1 and type =0 also - confused this logic) 
                                  
      autoPilot = packet.autopilot;
      if(packet.base_mode != 0) 
      {
        if(baseMode == packet.base_mode)
        {
          mChange = false;
        }
        else
        {
          baseMode = packet.base_mode;
          mChange = true;
        }
      }
      
      if(packet.base_mode != 0) 
      {
        if(customMode == packet.custom_mode)
        {
          mChange = mChange | false;
        }
        else
        {
          customMode = packet.custom_mode;
          mChange = true;
        }
      }
      
      if ((*msg).sysid != 0xff) // do not process mission planner heartbeats if we have two receiver xbees
      {
        received_sysid = (*msg).sysid; // save the sysid and compid of the received heartbeat for use in sending new messages      
        received_compid = (*msg).compid;
      
      beat = 1;
      break;
      }


    
    case MAVLINK_MSG_ID_COMMAND_ACK:
    {
      mavlink_command_ack_t packet;
      mavlink_msg_command_ack_decode(msg, &packet);

      command = packet.command;
      result = packet.result;

      
#ifdef DEBUG
    bline = "ACK Command: ";
    bline += command;
    bline += "   Result: ";
    bline += result;
    Serial.println(bline);    
#endif	

 
      break;
    }


   case MAVLINK_MSG_ID_ATTITUDE:
    {
#ifdef DEBUG_MAV
    Serial.println("Attitude");    
#endif	
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
//      velocity = packet.vel;
      latitude = packet.lat/1e7;
      longitude = packet.lon/1e7;
      altitude = packet.alt/1000.0;
#endif // MAVLINK10
//      position_antenna();
      gpsfix = packet.fix_type;
      break;
    }
    
    case MAVLINK_MSG_ID_GPS_STATUS:
    {
#ifdef DEBUG_MAV
    Serial.println("GPS Status");    
#endif	
      mavlink_gps_status_t packet;
      mavlink_msg_gps_status_decode(msg, &packet);        
      numSats = packet.satellites_visible;
      break;
    }
    
    case MAVLINK_MSG_ID_RAW_PRESSURE:
    {
#ifdef DEBUG_MAV
    Serial.println("Raw Pressure");    
#endif	
      // decode
      mavlink_raw_pressure_t packet;
      mavlink_msg_raw_pressure_decode(msg, &packet);
      break;
    }
    
    case MAVLINK_MSG_ID_SYS_STATUS:
    {

      mavlink_sys_status_t packet;
      mavlink_msg_sys_status_decode(msg, &packet);
      
      battery = packet.voltage_battery;
      current = packet.current_battery;
      RemainingBat = packet.battery_remaining;
      SensorHelth = packet.onboard_control_sensors_health;
      SensorsPresent = packet.onboard_control_sensors_present;
      SensorsEnabled = packet.onboard_control_sensors_enabled;
      break;
    }


    case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
    {

      mavlink_global_position_int_t packet;
      mavlink_msg_global_position_int_decode(msg, &packet);
      relative_alt = packet.relative_alt;
      hdg = packet.hdg;    
      break;
    }
    
    
    case MAVLINK_MSG_ID_OPTICAL_FLOW:
    {

      mavlink_optical_flow_t packet;
      mavlink_msg_optical_flow_decode(msg, &packet);
      
      time_usec = packet.time_usec;
      flow_comp_m_x = packet.flow_comp_m_x;
      flow_comp_m_y = packet.flow_comp_m_y;
      ground_distance = packet.ground_distance;
      flow_x = packet.flow_x;
      flow_y = packet.flow_y;
      sensor_id = packet.sensor_id;
      quality = packet.quality;     
      break;
    }


    case MAVLINK_MSG_ID_PARAM_VALUE:
    {
#ifdef DEBUG_PARAM
//    Serial.println("Parameter Recieved");
#endif
      // decode
      mavlink_param_value_t packet;
      mavlink_msg_param_value_decode(msg, &packet);
      float value;
      char parameter[16];
      pIndex = packet.param_index;
      value = packet.param_value;
      mav_array_memcpy(parameter, packet.param_id, sizeof(char)*16);
      
     EEPROM_writeDouble((pIndex*4), value);
     if(pIndex >0)
     {
       dtostrf(EEPROM_readDouble((pIndex-1)*4), 4, 1, cFloat);
       bline = "Index:  ";
       bline += pIndex-1;
       bline += "    Param: ";
       bline += PName(pIndex-1);
       bline += ",";
       bline += cFloat;
       eLog.println(bline);
     }
     /*
     // Function used to build the parameter resolution list
     test += 1; //intID
     test += 16;
     test += 4;
     dtostrf(value, 4, 1, cFloat);
     bline = "   case ";
     bline += pIndex;
     bline += ": return >";
     bline += parameter;
     bline += ">;";
     //bline += ",";
     //bline += cFloat;
     Serial.println(bline);
     */
      break;
    }
  }
 }
}

void start_feeds()
{
  mavlink_message_t msg;
  mavlink_msg_request_data_stream_pack(127, 0, &msg, received_sysid, received_compid, MAV_DATA_STREAM_ALL, 5, MAV_DATA_STREAM_RAW_SENSORS_ACTIVE);
  send_message(&msg);
  delay(10);
  delay(460);
}

void send_message(mavlink_message_t* msg)
{
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  
  uint16_t len = mavlink_msg_to_send_buffer(buf, msg);
  for(uint16_t i = 0; i < len; i++)
  {
    Serial1.write(buf[i]);
  }
}



