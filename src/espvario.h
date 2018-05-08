#define DEBUG_MSG_LEN 80
#include <stdlib.h>
#include "espressif/esp_common.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "private_ssid_config.h"
//#include <ssid_config.h>
const int gpio;

SemaphoreHandle_t spi_bus;
SemaphoreHandle_t i2c_bus;

QueueHandle_t debug_queue;
