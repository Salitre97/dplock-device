#include <stdio.h>
<<<<<<< HEAD
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
=======
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#define TAG "rgb_led_example"

void flash_rgb(void *pvParameters) {
  const int ledPin = 48; // IO48 indicated on MCU

  ESP_LOGI(TAG, "Flashing RGB LED");

  gpio_set_direction(ledPin, GPIO_MODE_OUTPU);

  // Set RGB Color directly
  gpio_set_level(ledPin, 255); // White

  vTaskDelay(pdMS_TO_TICKS(1000));

  gpio_set_level(ledPin, 255 << 8 | 255 << 16); // Red (Green and Blue are shifted into thier respective places)

  vTaskDelay(pdMS_TO_TICKS(1000));

  gpio_set_level(ledPin, 255 << 8); // Green

  vTaskDelay(pdMS_TO_TICKS(1000));

  gpio_set_level(ledPin, 255 << 16); // Blue

  vTaskDelay(pdMS_TO_TICKS(1000));

  gpio_set_direction(ledPin, GPIO_MODE_INPUT);



void app_main(void) {
  ESP_LOGI(TAG, "Starting rgb_led_example");

  xTaskCreate(&flash_rgb, "rgb_flash", 2048, NULL, 5, NULL);

}
>>>>>>> 912df63 (added sdkconfig)
