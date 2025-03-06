#ifndef FUEL_CELL_CONTROL_H
#define FUEL_CELL_CONTROL_H

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "esp_chip_info.h"
#include "esp_err.h"
#include "esp_flash.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"

#include "driver/gpio.h"
#include "driver/mcpwm_cmpr.h"
#include "driver/mcpwm_gen.h"
#include "driver/mcpwm_oper.h"
#include "driver/mcpwm_timer.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "esp_adc/adc_oneshot.h"
#include "hal/mcpwm_types.h"

#define PURGE_DURATION_MS        300
#define PURGE_MOSFET_DELAY_MS    5000
#define MOSFET_SHORT_DURATION_MS 15
#define MOSFET_SHORT_INTERVAL_MS 40

// Start value
extern bool main_valve_toggle;  // ================= ustawienie zaworu zasilajacego _ main valve n-mosfet (1 on, 0 off)
extern bool purge_valve_toggle; // ================= ustawienie przedmuchu - purge valve n-mosfet (1 on, 0 off)
extern bool mosfet_toggle;      // ================= ustawienie zwarcia mosfet - driver i n-mosfet (1 on, 0 off)

// Control
// int START_V = 3000;
// int PURGE_V = 1000;

extern bool fan_toggle;
extern bool purge_in_process;
extern int purge_step;

extern uint64_t purge_timer;

void fc_init();
void fc_on_loop();
void fc_purge();

#endif // FUEL_CELL_CONTROL_H