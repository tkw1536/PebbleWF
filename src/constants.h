#pragma once
#include <pebble.h>

// ===== COLORS =====

// watchface background color
#define WATCHFACE_BACKGROUND_COLOR GColorWhite

// text + background defaults
#define WATCHFACE_TEXT_COLOR GColorBlack
#define WATCHFACE_TEXT_BACKGROUND_COLOR GColorClear

// colors for data + time
#define WATCHFACE_TIME_COLOR WATCHFACE_TEXT_COLOR
#define WATCHFACE_DATE_COLOR WATCHFACE_TEXT_COLOR
#define WATCHFACE_BATTERY_COLOR WATCHFACE_TEXT_COLOR

// background colors depending on the battery state
#define WATCHFACE_BATTERY_00_COLOR GColorFromRGB(255, 0, 0) // RED
#define WATCHFACE_BATTERY_10_COLOR GColorFromRGB(255, 51, 0)
#define WATCHFACE_BATTERY_20_COLOR GColorFromRGB(255, 102, 0)
#define WATCHFACE_BATTERY_30_COLOR GColorFromRGB(255, 153, 0)
#define WATCHFACE_BATTERY_40_COLOR GColorFromRGB(255, 204, 0)
#define WATCHFACE_BATTERY_50_COLOR GColorFromRGB(255, 255, 0) // YELLOW
#define WATCHFACE_BATTERY_60_COLOR GColorFromRGB(204, 255, 0)
#define WATCHFACE_BATTERY_70_COLOR GColorFromRGB(153, 255, 0)
#define WATCHFACE_BATTERY_80_COLOR GColorFromRGB(102, 255, 0)
#define WATCHFACE_BATTERY_90_COLOR GColorFromRGB(51, 255, 0)
#define WATCHFACE_BATTERY_100_COLOR GColorFromRGB(0, 255, 0) // GREEN

// backhground colors for charging / discharging
#define WATCHFACE_BATTERY_CHARGE_BACKGROUND GColorOxfordBlue

// the blue background is red
#define WATCHFACE_BLUE_COLOR GColorRed

// ===== TEXT =====

// disconnected message
#define WATCHFACE_STR_DISCONNECTED "PHONE DISCONNECTED"

// days of the week
#define WATCHFACE_STR_SUNDAY     "SUN"
#define WATCHFACE_STR_MONDAY     "MON"
#define WATCHFACE_STR_TUESDAY    "TUE"
#define WATCHFACE_STR_WEDNESDAY  "WED"
#define WATCHFACE_STR_THURSDAY   "THU"
#define WATCHFACE_STR_FRIDAY     "FRI"
#define WATCHFACE_STR_SATURDAY   "SAT"

// months of the year
#define WATCHFACE_STR_JANUARY    "JAN"
#define WATCHFACE_STR_FEBRUARY   "FEB"
#define WATCHFACE_STR_MARCH      "MAR"
#define WATCHFACE_STR_APRIL      "APR"
#define WATCHFACE_STR_MAY        "MAY"
#define WATCHFACE_STR_JUNE       "JUN"
#define WATCHFACE_STR_JULY       "JUL"
#define WATCHFACE_STR_AUGUST     "AUG"
#define WATCHFACE_STR_SEPTEMBER  "SEP"
#define WATCHFACE_STR_OCTOBER    "OCT"
#define WATCHFACE_STR_NOVEMBER   "NOV"
#define WATCHFACE_STR_DECEMBER   "DEC"