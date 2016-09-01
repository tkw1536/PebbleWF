#pragma once
#include <pebble.h>

TextLayer *s_blue_layer;

// Component functions
extern void component_blue_init(Layer *window_layer, GRect *bounds);
extern void component_blue_register(); 
extern void component_blue_deinit();
extern void component_blue_update();