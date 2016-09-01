#pragma once
#include <pebble.h>

// text and date layer
TextLayer *s_time_layer;
TextLayer *s_date_layer;

// Component functions
extern void component_datetime_init(Layer *window_layer, GRect *bounds);
extern void component_datetime_register(); 
extern void component_datetime_deinit();
extern void component_datetime_update();