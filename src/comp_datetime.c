#include <pebble.h>
#include "comp_datetime.h"


#include "watch_format.h"
#include "constants.h"

void component_datetime_init (Layer *window_layer, GRect *bounds) {
  // called on creation of the app
  
  // Create a layer for the time
  s_time_layer = text_layer_create( GRect(0, PBL_IF_ROUND_ELSE(58, 52), (*bounds).size.w, 50) );
  
  text_layer_set_background_color(s_time_layer, WATCHFACE_TEXT_BACKGROUND_COLOR);
  text_layer_set_text_color(s_time_layer, WATCHFACE_TIME_COLOR);
  text_layer_set_text(s_time_layer, "00:00");
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  
  // Create a layer for the date
  s_date_layer = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(113, 105), (*bounds).size.w, 20));
  
  text_layer_set_background_color(s_date_layer, WATCHFACE_TEXT_BACKGROUND_COLOR);
  text_layer_set_text_color(s_date_layer, WATCHFACE_DATE_COLOR);
  text_layer_set_text(s_date_layer, "MON - 01 JAN 00");
  text_layer_set_font(s_date_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_date_layer));
}

static void component_datetime_tick(struct tm *tick_time, TimeUnits units_changed) {
  // called whenever the datetime component updates

  // update the buffer for the time layer
  static char s_buffer_t[8];
  format_time(tick_time, s_buffer_t, sizeof(s_buffer_t)); 
  text_layer_set_text(s_time_layer, s_buffer_t);
  
  // update the buffer for the date layer
  static char s_buffer_d[20];
  format_date(tick_time, s_buffer_d, sizeof(s_buffer_d)); 
  text_layer_set_text(s_date_layer, s_buffer_d);
}

void component_datetime_update () {
  // updates date and time on the watch
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);
  
  component_datetime_tick(tick_time, MINUTE_UNIT);
}

void component_datetime_register () {
  // called on registration time
  
  tick_timer_service_subscribe(MINUTE_UNIT, component_datetime_tick);
}

void component_datetime_deinit () {
  // called on destruction of the app
  
  text_layer_destroy(s_time_layer);
  text_layer_destroy(s_date_layer);
}