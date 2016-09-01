#pragma once

// battery layer
TextLayer *s_bat_layer;

// Component functions
extern void component_battery_init(Layer *window_layer, GRect *bounds);
extern void component_battery_register(); 
extern void component_battery_deinit();
extern void component_battery_update();

static void set_battery_color(BatteryChargeState charge_state); 