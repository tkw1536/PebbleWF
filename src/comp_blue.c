#include <pebble.h>
#include "comp_blue.h"

#include "constants.h"

void component_blue_update () {
  // updates battery on the watch
  
  // check if we are currently connected
  bool connected = connection_service_peek_pebble_app_connection();
  
  // Hide or show layer
  layer_set_hidden((Layer *) s_blue_layer, connected);
}

void component_blue_init (Layer *window_layer, GRect *bounds) {
  // called on creation of the app
  
  // Create a layer for the battery
  s_blue_layer = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(153, 145), (*bounds).size.w, 20));
  
  text_layer_set_background_color(s_blue_layer, WATCHFACE_TEXT_BACKGROUND_COLOR);
  text_layer_set_text_color(s_blue_layer, WATCHFACE_BLUE_COLOR);
  text_layer_set_text(s_blue_layer, WATCHFACE_STR_DISCONNECTED);
  text_layer_set_font(s_blue_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_text_alignment(s_blue_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_layer, text_layer_get_layer(s_blue_layer));
}

static void component_blue_tick(bool connected) {
  // called whenever the bluetooth component updates
  component_blue_update(); 
}

void component_blue_register () {
  // called on registration time
  connection_service_subscribe((ConnectionHandlers) {
    .pebble_app_connection_handler = component_blue_tick
  });
}

void component_blue_deinit () {
  // called on destruction of the app
  
  text_layer_destroy(s_blue_layer);
}