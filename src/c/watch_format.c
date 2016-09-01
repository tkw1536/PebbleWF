#include <pebble.h>
#include "watch_format.h"
#include "constants.h"

const char *weekday_to_string(int day); 
const char *month_to_string(int month);
  
void format_time(struct tm *time, char *buffer, size_t buffer_size) {
  // helper function to write time into a buffer
  // does not respect local settings on the watch
  
  // since we just want the time we can use strftime
  strftime(buffer, buffer_size, "%H:%M", time);
}

void format_date(struct tm *time, char *buffer, size_t buffer_size) {
  // helper function to write date into a buffer
  // does not respect local conventions
  
  // write it into a buffer
  snprintf(buffer, buffer_size, "%s - %2u %s %4u", weekday_to_string(time->tm_wday), time->tm_mday, month_to_string(time->tm_mon), time->tm_year + 1900);
}

void format_battery(BatteryChargeState charge_state, char *buffer, size_t buffer_size) {
  // helper function to write battery state into a buffer
  
  // and print it
  snprintf(buffer, buffer_size, "%03d %%", charge_state.charge_percent);
}

const char *weekday_to_string(int day) {
  switch(day){
    case 0:
      return WATCHFACE_STR_SUNDAY;
      break; 
    case 1:
      return WATCHFACE_STR_MONDAY;
      break;
    case 2:
      return WATCHFACE_STR_TUESDAY;
      break;
    case 3:
      return WATCHFACE_STR_WEDNESDAY;
      break;
    case 4:
      return WATCHFACE_STR_THURSDAY;
      break;
    case 5:
      return WATCHFACE_STR_FRIDAY;
      break;
    case 6:
      return WATCHFACE_STR_SATURDAY;
      break;
  }
  return "";
}

const char *month_to_string(int month) {
  switch(month){
    case 0:
      return WATCHFACE_STR_JANUARY;
      break; 
    case 1:
      return WATCHFACE_STR_FEBRUARY;
      break;
    case 2:
      return WATCHFACE_STR_MARCH;
      break;
    case 3:
      return WATCHFACE_STR_APRIL;
      break;
    case 4:
      return WATCHFACE_STR_MAY;
      break;
    case 5:
      return WATCHFACE_STR_JUNE;
      break;
    case 6:
      return WATCHFACE_STR_JULY;
      break;
    case 7:
      return WATCHFACE_STR_AUGUST;
      break;
    case 8:
      return WATCHFACE_STR_SEPTEMBER;
      break;
    case 9:
      return WATCHFACE_STR_OCTOBER;
      break;
    case 10:
      return WATCHFACE_STR_NOVEMBER;
      break;
    case 11:
      return WATCHFACE_STR_DECEMBER;
      break;
  }
  return "";
}