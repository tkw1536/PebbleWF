#include <pebble.h>
#include "comp_datetime.h"
#include "comp_battery.h"
#include "comp_blue.h"
#include "constants.h"

static Window *s_main_window; // Main Window

static void main_window_load(Window *window) {
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // initialise all the components
  component_datetime_init(window_layer, &bounds); 
  component_battery_init(window_layer, &bounds);
  component_blue_init(window_layer, &bounds);
}

static void main_window_unload(Window *window) {
  // Called on app unload
  
  // deinialise all the components
  component_datetime_deinit(); 
  component_battery_deinit(); 
  component_blue_deinit();
}


static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  
  // make the background black
  window_set_background_color(s_main_window, WATCHFACE_BACKGROUND_COLOR);

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  
  // register all the components
  component_datetime_register(); 
  component_battery_register(); 
  component_blue_register();
  
  // and update all of them
  component_datetime_update();
  component_battery_update();
  component_blue_update();
}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}