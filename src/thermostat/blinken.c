#include "espressif/esp_common.h"
#include "thermostat.h"

void blinkenTask(void *pvParameters)
{
    gpio_enable(gpio, GPIO_OUTPUT);
    while(1) {
        gpio_write(gpio, 1);
//        printf("Huu\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        gpio_write(gpio, 0);
//        printf("Haa\n");
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
