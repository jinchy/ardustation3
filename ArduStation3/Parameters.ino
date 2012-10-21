
char *PName(int Index)
{
  switch(Index)
  {
   case 0: return P("SYSID_SW_MREV");
   case 1: return P("SYSID_SW_TYPE");
   case 2: return P("SYSID_THISMAV");
   case 3: return P("SYSID_MYGCS");
   case 4: return P("SERIAL3_BAUD");
   case 5: return P("TELEM_DELAY");
   case 6: return P("ALT_HOLD_RTL");
   case 7: return P("SONAR_ENABLE");
   case 8: return P("SONAR_TYPE");
   case 9: return P("BATT_MONITOR");
   case 10: return P("VOLT_DIVIDER");
   case 11: return P("AMP_PER_VOLT");
   case 12: return P("INPUT_VOLTS");
   case 13: return P("BATT_CAPACITY");
   case 14: return P("MAG_ENABLE");
   case 15: return P("FLOW_ENABLE");
   case 16: return P("LOW_VOLT");
   case 17: return P("SUPER_SIMPLE");
   case 18: return P("APPROACH_ALT");
   case 19: return P("TILT");
   case 20: return P("WP_MODE");
   case 21: return P("WP_TOTAL");
   case 22: return P("WP_INDEX");
   case 23: return P("WP_MUST_INDEX");
   case 24: return P("WP_RADIUS");
   case 25: return P("WP_LOITER_RAD");
   case 26: return P("WP_SPEED_MAX");
   case 27: return P("XTRK_GAIN_SC");
   case 28: return P("AUTO_LAND");
   case 29: return P("THR_MIN");
   case 30: return P("THR_MAX");
   case 31: return P("THR_FAILSAFE");
   case 32: return P("THR_FS_ACTION");
   case 33: return P("THR_FS_VALUE");
   case 34: return P("TRIM_THROTTLE");
   case 35: return P("FLTMODE1");
   case 36: return P("FLTMODE2");
   case 37: return P("FLTMODE3");
   case 38: return P("FLTMODE4");
   case 39: return P("FLTMODE5");
   case 40: return P("FLTMODE6");
   case 41: return P("SIMPLE");
   case 42: return P("LOG_BITMASK");
   case 43: return P("LOG_LASTFILE");
   case 44: return P("TOY_RATE");
   case 45: return P("ESC");
   case 46: return P("TUNE");
   case 47: return P("TUNE_LOW");
   case 48: return P("TUNE_HIGH");
   case 49: return P("FRAME");
   case 50: return P("CH7_OPT");
   case 51: return P("AUTO_SLEW");
   case 52: return P("CAM_TRIGG_TYPE");
   case 53: return P("RC1_MIN");
   case 54: return P("RC1_TRIM");
   case 55: return P("RC1_MAX");
   case 56: return P("RC1_REV");
   case 57: return P("RC1_DZ");
   case 58: return P("RC2_MIN");
   case 59: return P("RC2_TRIM");
   case 60: return P("RC2_MAX");
   case 61: return P("RC2_REV");
   case 62: return P("RC2_DZ");
   case 63: return P("RC3_MIN");
   case 64: return P("RC3_TRIM");
   case 65: return P("RC3_MAX");
   case 66: return P("RC3_REV");
   case 67: return P("RC3_DZ");
   case 68: return P("RC4_MIN");
   case 69: return P("RC4_TRIM");
   case 70: return P("RC4_MAX");
   case 71: return P("RC4_REV");
   case 72: return P("RC4_DZ");
   case 73: return P("RC5_MIN");
   case 74: return P("RC5_TRIM");
   case 75: return P("RC5_MAX");
   case 76: return P("RC5_REV");
   case 77: return P("RC5_DZ");
   case 78: return P("RC5_FUNCTION");
   case 79: return P("RC6_MIN");
   case 80: return P("RC6_TRIM");
   case 81: return P("RC6_MAX");
   case 82: return P("RC6_REV");
   case 83: return P("RC6_DZ");
   case 84: return P("RC6_FUNCTION");
   case 85: return P("RC7_MIN");
   case 86: return P("RC7_TRIM");
   case 87: return P("RC7_MAX");
   case 88: return P("RC7_REV");
   case 89: return P("RC7_DZ");
   case 90: return P("RC7_FUNCTION");
   case 91: return P("RC8_MIN");
   case 92: return P("RC8_TRIM");
   case 93: return P("RC8_MAX");
   case 94: return P("RC8_REV");
   case 95: return P("RC8_DZ");
   case 96: return P("RC8_FUNCTION");
   case 97: return P("RC10_MIN");
   case 98: return P("RC10_TRIM");
   case 99: return P("RC10_MAX");
   case 100: return P("RC10_REV");
   case 101: return P("RC10_DZ");
   case 102: return P("RC10_FUNCTION");
   case 103: return P("RC11_MIN");
   case 104: return P("RC11_TRIM");
   case 105: return P("RC11_MAX");
   case 106: return P("RC11_REV");
   case 107: return P("RC11_DZ");
   case 108: return P("RC11_FUNCTION");
   case 109: return P("RC_SPEED");
   case 110: return P("STAB_D");
   case 111: return P("STAB_D_S");
   case 112: return P("ACRO_P");
   case 113: return P("AXIS_P");
   case 114: return P("AXIS_ENABLE");
   case 115: return P("LED_MODE");
   case 116: return P("RATE_RLL_P");
   case 117: return P("RATE_RLL_I");
   case 118: return P("RATE_RLL_D");
   case 119: return P("RATE_RLL_IMAX");
   case 120: return P("RATE_PIT_P");
   case 121: return P("RATE_PIT_I");
   case 122: return P("RATE_PIT_D");
   case 123: return P("RATE_PIT_IMAX");
   case 124: return P("RATE_YAW_P");
   case 125: return P("RATE_YAW_I");
   case 126: return P("RATE_YAW_D");
   case 127: return P("RATE_YAW_IMAX");
   case 128: return P("LOITER_LAT_P");
   case 129: return P("LOITER_LAT_I");
   case 130: return P("LOITER_LAT_D");
   case 131: return P("LOITER_LAT_IMAX");
   case 132: return P("LOITER_LON_P");
   case 133: return P("LOITER_LON_I");
   case 134: return P("LOITER_LON_D");
   case 135: return P("LOITER_LON_IMAX");
   case 136: return P("NAV_LAT_P");
   case 137: return P("NAV_LAT_I");
   case 138: return P("NAV_LAT_D");
   case 139: return P("NAV_LAT_IMAX");
   case 140: return P("NAV_LON_P");
   case 141: return P("NAV_LON_I");
   case 142: return P("NAV_LON_D");
   case 143: return P("NAV_LON_IMAX");
   case 144: return P("THR_RATE_P");
   case 145: return P("THR_RATE_I");
   case 146: return P("THR_RATE_D");
   case 147: return P("THR_RATE_IMAX");
   case 148: return P("OF_RLL_P");
   case 149: return P("OF_RLL_I");
   case 150: return P("OF_RLL_D");
   case 151: return P("OF_RLL_IMAX");
   case 152: return P("OF_PIT_P");
   case 153: return P("OF_PIT_I");
   case 154: return P("OF_PIT_D");
   case 155: return P("OF_PIT_IMAX");
   case 156: return P("STB_RLL_P");
   case 157: return P("STB_RLL_I");
   case 158: return P("STB_RLL_IMAX");
   case 159: return P("STB_PIT_P");
   case 160: return P("STB_PIT_I");
   case 161: return P("STB_PIT_IMAX");
   case 162: return P("STB_YAW_P");
   case 163: return P("STB_YAW_I");
   case 164: return P("STB_YAW_IMAX");
   case 165: return P("THR_ALT_P");
   case 166: return P("THR_ALT_I");
   case 167: return P("THR_ALT_IMAX");
   case 168: return P("HLD_LAT_P");
   case 169: return P("HLD_LAT_I");
   case 170: return P("HLD_LAT_IMAX");
   case 171: return P("HLD_LON_P");
   case 172: return P("HLD_LON_I");
   case 173: return P("HLD_LON_IMAX");
   case 174: return P("COMPASS_OFS_X");
   case 175: return P("COMPASS_OFS_Y");
   case 176: return P("COMPASS_OFS_Z");
   case 177: return P("COMPASS_DEC");
   case 178: return P("COMPASS_LEARN");
   case 179: return P("COMPASS_USE");
   case 180: return P("COMPASS_AUTODEC");
   case 181: return P("INS_XH");
   case 182: return P("INS_XL");
   case 183: return P("INS_YH");
   case 184: return P("INS_YL");
   case 185: return P("INS_ZH");
   case 186: return P("INS_ZL");
   case 187: return P("SR0_RAW_SENS");
   case 188: return P("SR0_EXT_STAT");
   case 189: return P("SR0_RC_CHAN");
   case 190: return P("SR0_RAW_CTRL");
   case 191: return P("SR0_POSITION");
   case 192: return P("SR0_EXTRA1");
   case 193: return P("SR0_EXTRA2");
   case 194: return P("SR0_EXTRA3");
   case 195: return P("SR0_PARAMS");
   case 196: return P("SR3_RAW_SENS");
   case 197: return P("SR3_EXT_STAT");
   case 198: return P("SR3_RC_CHAN");
   case 199: return P("SR3_RAW_CTRL");
   case 200: return P("SR3_POSITION");
   case 201: return P("SR3_EXTRA1");
   case 202: return P("SR3_EXTRA2");
   case 203: return P("SR3_EXTRA3");
   case 204: return P("SR3_PARAMS");
   case 205: return P("IMU_PRODUCT_ID");
   case 206: return P("AHRS_GPS_GAIN");
   case 207: return P("AHRS_GPS_USE");
   case 208: return P("AHRS_YAW_P");
   case 209: return P("AHRS_RP_P");
   case 210: return P("MNT_MODE");
   case 211: return P("MNT_RETRACT_X");
   case 212: return P("MNT_RETRACT_Y");
   case 213: return P("MNT_RETRACT_Z");
   case 214: return P("MNT_NEUTRAL_X");
   case 215: return P("MNT_NEUTRAL_Y");
   case 216: return P("MNT_NEUTRAL_Z");
   case 217: return P("MNT_CONTROL_X");
   case 218: return P("MNT_CONTROL_Y");
   case 219: return P("MNT_CONTROL_Z");
   case 220: return P("MNT_STAB_ROLL");
   case 221: return P("MNT_STAB_TILT");
   case 222: return P("MNT_STAB_PAN");
   case 223: return P("MNT_RC_IN_ROLL");
   case 224: return P("MNT_ANGMIN_ROL");
   case 225: return P("MNT_ANGMAX_ROL");
   case 226: return P("MNT_RC_IN_TILT");
   case 227: return P("MNT_ANGMIN_TIL");
   case 228: return P("MNT_ANGMAX_TIL");
   case 229: return P("MNT_RC_IN_PAN");
   case 230: return P("MNT_ANGMIN_PAN");
   case 231: return P("MNT_ANGMAX_PAN");
   case 232: return P("MNT_JSTICK_SPD");
   case 233: return P("LIM_ENABLED");
   case 234: return P("LIM_REQUIRED");
   case 235: return P("LIM_DEBUG");
   case 236: return P("LIM_SAFETIME");
   case 237: return P("LIM_CHANNEL");
   case 238: return P("LIM_RECMODE");
   case 239: return P("LIM_GPSLCK_ON");
   case 240: return P("LIM_GPSLCK_REQ");
   case 241: return P("LIM_FNC_ON");
   case 242: return P("LIM_FNC_REQ");
   case 243: return P("LIM_FNC_SMPL");
   case 244: return P("LIM_FNC_RAD");
   case 245: return P("LIM_FNC_TOT");
   case 246: return P("LIM_ALT_ON");
   case 247: return P("LIM_ALT_REQ");
   case 248: return P("LIM_ALT_MIN");
   case 249: return P("LIM_ALT_MAX");
   case 250: return P("MOT_TB_RATIO");

  }
}
