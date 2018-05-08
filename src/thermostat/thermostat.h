#define MQTT_HOST ("kw.dy.fi")
#define MQTT_PORT 1883

#define MQTT_USER NULL
#define MQTT_PASS NULL

#define PUB_MSG_LEN 16
#include "espressif/esp_common.h"
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include "private_ssid_config.h"
//#include <ssid_config.h>

typedef struct {
  float set_temp;
  float hysteresis;
  char sitename[10];
} Settings;

const int gpio;
SemaphoreHandle_t wifi_alive;
QueueHandle_t publish_queue;
