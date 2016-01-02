#include <pebble.h>
#include "comp_battery.h"

#include "watch_format.h"
#include "constants.h"

void component_battery_init (Layer *window_layer, GRect *bounds) {
  // called on creation of the app
  
  // Create a layer for the battery
  s_bat_layer = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(128, 120), (*bounds).size.w, 20));
  
  text_layer_set_background_color(s_bat_layer, WATCHFACE_TEXT_BACKGROUND_COLOR);
  text_layer_set_text_color(s_bat_layer, WATCHFACE_BATTERY_COLOR);
  text_layer_set_text(s_bat_layer, "000 %");
  text_layer_set_font(s_bat_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_text_alignment(s_bat_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_layer, text_layer_get_layer(s_bat_layer));
}

static void component_battery_tick(BatteryChargeState charge_state) {
  // called whenever the battery component updates
  
  // update the color
  set_battery_color(charge_state);
  
  // update the buffer for the time layer
  static char s_buffer_b[10];
  format_battery(charge_state, s_buffer_b, sizeof(s_buffer_b)); 
  text_layer_set_text(s_bat_layer, s_buffer_b);
}

void component_battery_update () {
  // updates battery on the watch
  
  component_battery_tick(battery_state_service_peek());
}

void component_battery_register () {
  // called on registration time
  
  battery_state_service_subscribe(component_battery_tick);
}

void component_battery_deinit () {
  // called on destruction of the app
  
  text_layer_destroy(s_bat_layer);
}

void set_battery_color(BatteryChargeState charge_state) {
  
  // if we are charging, we can set the color immediatly
  if (charge_state.is_charging) {
    text_layer_set_background_color(s_bat_layer, WATCHFACE_BATTERY_CHARGE_BACKGROUND);
    return; 
  }
  
  // get a new color for the text
  GColor newcolor = GColorClear; 
  
  // switch color based on the current percentage
  switch (charge_state.charge_percent / 10) {
    case 0:
      newcolor = WATCHFACE_BATTERY_00_COLOR; 
      break;
    case 1:
      newcolor = WATCHFACE_BATTERY_10_COLOR;
      break;
    case 2:
      newcolor = WATCHFACE_BATTERY_20_COLOR;
      break;
    case 3:
      newcolor = WATCHFACE_BATTERY_30_COLOR;
      break;
    case 4:
      newcolor = WATCHFACE_BATTERY_40_COLOR;
      break;
    case 5:
      newcolor = WATCHFACE_BATTERY_50_COLOR;
      break;
    case 6:
      newcolor = WATCHFACE_BATTERY_60_COLOR;
      break;
    case 7:
      newcolor = WATCHFACE_BATTERY_70_COLOR;
      break;
    case 8:
      newcolor = WATCHFACE_BATTERY_80_COLOR;
      break;
    case 9:
      newcolor = WATCHFACE_BATTERY_90_COLOR;
      break;
    case 10:
      newcolor = WATCHFACE_BATTERY_100_COLOR;
      break;
  }
  
  // set the background color
  text_layer_set_background_color(s_bat_layer, newcolor);
}