#include <stdio.h>
#include "driver/ledc.h"
#include "esp_err.h"

#define LED_TIMER           LEDC_TIMER_0
#define LEDC_MODE           LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO      (48)  // RGB LED 
#define LEDC_CHANNEL        LEDC_CHANNEL_0

static void led_ledc_init(void)
{
    // Prepare and then apply the LEDC PWM timer config
    ledc_timer_config_t ledc_timer = {
        .speed_mode         = LEDC_MODE,
        .duty_resolution    = LEDC_DUTY_RES,
        .timer_num          = LEDC_TIMER, 
        .freq_hz            = LEDC_FREQUENCY, 
        .clk_cfg            = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));


}