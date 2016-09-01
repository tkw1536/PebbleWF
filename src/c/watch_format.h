#pragma once

extern void format_time(struct tm *time, char *buffer, size_t buffer_size); 
extern void format_date(struct tm *time, char *buffer, size_t buffer_size);
extern void format_battery(BatteryChargeState charge_state, char *buffer, size_t buffer_size);