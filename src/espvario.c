#include "espvario.h"
#include "esp/uart.h"
#include "beat.h"
#include "logging.h"

void user_init(void)
{
  uart_set_baud(0, 115200);
  printf("SDK version:%s\n", sdk_system_get_sdk_version());
  // Set led to indicate wifi status.
  sdk_wifi_status_led_install(2, PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);

  struct sdk_station_config config = {
    .ssid = WIFI_SSID,
    .password = WIFI_PASS,
  };

  // Required to call wifi_set_opmode before station_set_config.
  sdk_wifi_set_opmode(STATION_MODE);
  sdk_wifi_station_set_config(&config);
  vSemaphoreCreateBinary(spi_bus);
  vSemaphoreCreateBinary(i2c_bus);
  
  debug_queue = xQueueCreate(3, DEBUG_MSG_LEN);

  //  xTaskCreate(&blinkenTask, "blinkenTask", 256, NULL, 2, NULL);
  //  xTaskCreate(&wifi_task, "wifi_task",  256, NULL, 2, NULL);
  xTaskCreate(&beat_task, "beat_task", 256, NULL, 3, NULL);
  xTaskCreate(&logging_task, "logging_task", 1024, NULL, 4, NULL);
}
