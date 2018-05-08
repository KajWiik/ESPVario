#include <string.h>
#include "espvario.h"

void  beat_task(void *pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    char msg[DEBUG_MSG_LEN];
    int count = 0;

    while (1) {
        vTaskDelayUntil(&xLastWakeTime, 10000 / portTICK_PERIOD_MS);
        printf("beat\r\n");
        snprintf(msg, DEBUG_MSG_LEN, "Beat %d\r\n", count++);
        if (xQueueSend(debug_queue, (void *)msg, 0) == pdFALSE) {
            printf("Debug queue overflow.\r\n");
        }
    }
}
