//void OpenCSVLog()
//{
//	/*
//	float flow_comp_m_x;
//float flow_comp_m_y;
//float ground_distance;
//uint8_t sensor_id;
//uint8_t quality;
//int relative_alt;
//int SensorHelth=0;
//int SensorsPresent=0;
//int SensorsEnabled=0;
//int waitingAck=0;
//int paramsRecv=0;
//int beat=0;
//*/
//	strcpy(bline, P("Time,"));
//	strcat(bline, P("Drone Type,"));
//	strcat(bline, P("Auto Pilot,"));
//	strcat(bline, P("Roll,"));
//	strcat(bline, P("Pitch,"));
//	strcat(bline, P("Yaw,"));
//	strcat(bline, P("Altitude,"));
//	strcat(bline, P("Velocity,"));
//	strcat(bline, P("Battery,"));
//	strcat(bline, P("Current,"));
//	strcat(bline, P("Remaining Battery,");
//	strcat(bline, P("APM Longitude,"));
//	strcat(bline, P("APM Latitude,"));
//	strcat(bline, P("Headding,"));
//	strcat(bline, P("APM Sats,");
//	strcat(bline, P("GPS Fix,"));
//	strcat(bline, P("Current S Mode,"));
//	strcat(bline, P("Current N Mode,"));
//	strcat(bline, P("Flow X,"));
//	strcat(bline, P("Flow Y"));
//
//}
//
//void LogLine()
//{
//	strcpy(bline, time);
//	itoa(droneType, cFloat, 10);
//	strcat(bline, cFloat);
//	strcat(bline, ",");
//	//strcat(bline, P("Auto Pilot,"));
//	itoa(autoPilot, cFloat, 10);
//	strcat(bline, cFloat);
//	strcat(bline, ",");
//	
//	//strcat(bline, P("Roll,"));
//	dtostrf(roll, 10, 6, cFloat);
//	strcat(bline, cFloat);
//	strcat(bline, ",");
//	
//	//strcat(bline, P("Pitch,"));
//	dtostrf(pitch, 10, 6, cFloat);
//	strcat(bline, cFloat);
//	strcat(bline, ",");
//
//	//strcat(bline, P("Yaw,"));
//	dtostrf(yaw, 10, 6, cFloat);
//	strcat(bline, cFloat);
//	strcat(bline, ",");
//	
//	strcat(bline, P("Altitude,"));
//	strcat(bline, P("Velocity,"));
//
//	//strcat(bline, P("Battery,"));
//	dtostrf(battery/1000, 10, 6, cFloat);
//	strcat(bline, cFloat);
//	strcat(bline, ",");
//
//	//strcat(bline, P("Current,"));
//	dtostrf(battery/1000, 10, 6, cFloat);
//	strcat(bline, cFloat);
//	strcat(bline, ",");
//
//	strcat(bline, P("Remaining Battery,");
//	strcat(bline, P("APM Longitude,"));
//	strcat(bline, P("APM Latitude,"));
//	strcat(bline, P("Headding,"));
//	strcat(bline, P("APM Sats,");
//	strcat(bline, P("GPS Fix,"));
//	strcat(bline, P("Current S Mode,"));
//	strcat(bline, P("Current N Mode,"));
//	strcat(bline, P("Flow X,"));
//	strcat(bline, P("Flow Y"));
//
//}