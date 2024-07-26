#include <stdio.h>
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
