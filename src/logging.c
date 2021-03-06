#include <string.h>

#include "espressif/esp_common.h"
#include "esp/uart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "lwip/api.h"

void broadcast_temperature(void *pvParameters)
{

    char msg[100];

    // Broadcaster part
    err_t err;

    while(1) {

        // Send out some UDP data
        struct netconn* conn;

        // Create UDP connection
        conn = netconn_new(NETCONN_UDP);

        // Connect to local port
        err = netconn_bind(conn, IP_ADDR_ANY, 8004);

        if (err != ERR_OK) {
            netconn_delete(conn);
            printf("%s : Could not bind! (%s)\n", __FUNCTION__, lwip_strerr(err));
            continue;
        }

        err = netconn_connect(conn, IP_ADDR_BROADCAST, 8005);

        if (err != ERR_OK) {
            netconn_delete(conn);
            printf("%s : Could not connect! (%s)\n", __FUNCTION__, lwip_strerr(err));
            continue;
        }

        for(;;) {
                sprintf(msg, "Sensor %08x%08x reports: %f \xC2\xB0""C\n", (uint32_t)(addrs[i] >> 32), (uint32_t)addrs[i], results[i]);
                printf("%s", msg);

                struct netbuf* buf = netbuf_new();
                void* data = netbuf_alloc(buf, strlen(msg));

                memcpy (data, msg, strlen(msg));
                err = netconn_send(conn, buf);

                if (err != ERR_OK) {
                    printf("%s : Could not send data!!! (%s)\n", __FUNCTION__, lwip_strerr(err));
                    continue;
                }
                netbuf_delete(buf); // De-allocate packet buffer
            }
            vTaskDelay(1000/portTICK_RATE_MS);
        }

        err = netconn_disconnect(conn);
        printf("%s : Disconnected from IP_ADDR_BROADCAST port 12346 (%s)\n", __FUNCTION__, lwip_strerr(err));

        err = netconn_delete(conn);
        printf("%s : Deleted connection (%s)\n", __FUNCTION__, lwip_strerr(err));

        vTaskDelay(1000/portTICK_RATE_MS);
    }
}

//#include <string.h>
#include "espvario.h"

void  logging_task(void *pvParameters)
{
    while(1) {
        xSemaphoreTake(wifi_alive, portMAX_DELAY);
        printf("%s: started\n\r", __func__);
    

	while(1){

	  char msg[PUB_MSG_LEN - 1] = "\0";
	  while(xQueueReceive(publish_queue, (void *)msg, 0) ==
		pdTRUE){

}
