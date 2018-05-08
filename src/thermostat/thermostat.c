/*
 *
 */
#include "esp/uart.h"
#include "blinken.h"
#include "wifi.h"
#include "mqtt.h"
#include "thermostat.h"

const int gpio = 2;

#if 0
uint32_t fs_size() { // returns the flash chip's size, in BYTES
    uint32_t chipId = sdk_spi_flash_get_id();
    /**
     * Chip ID
     * 00 - always 00 (Chip ID use only 3 byte)
     * 17 - ? looks like 2^xx is size in Byte ?     //todo: find docu to this
     * 40 - ? may be Speed ?                        //todo: find docu to this
     * C8 - manufacturer ID
     */
    printf("Chip id: %x\n", chipId);
    
    switch(chipId) {

        // GigaDevice
    case 0x1740C8: // GD25Q64B
            return (8*1048576);
    case 0x1640C8: // GD25Q32B
        return (4*1048576);
    case 0x1540C8: // GD25Q16B
        return (2*1048576);
    case 0x1440C8: // GD25Q80
        return (1*1048576);
    case 0x1340C8: // GD25Q40
        return (512*1024);
    case 0x1240C8: // GD25Q20
        return (256*1024);
    case 0x1140C8: // GD25Q10
        return (128*1024);
    case 0x1040C8: // GD25Q12
        return (64*1024);
        
        // Winbond
    case 0x1640EF: // W25Q32
        return (4*1048576);
    case 0x1540EF: // W25Q16
        return (2*1048576);
    case 0x1440EF: // W25Q80
        return (1*1048576);
    case 0x1340EF: // W25Q40
        return (512*1024);

        // BergMicro
    case 0x1640E0: // BG25Q32
        return (4*1048576);
    case 0x1540E0: // BG25Q16
        return (2*1048576);
    case 0x1440E0: // BG25Q80
        return (1*1048576);
    case 0x1340E0: // BG25Q40
        return (512*1024);
        
    default:
        return 0;
    }
}
#endif

void user_init(void)
{
  
  uart_set_baud(0, 115200);
  //    printf("Flash size is %d\n", fs_size());
  printf("SDK version:%s\n", sdk_system_get_sdk_version());
  vSemaphoreCreateBinary(wifi_alive);
  publish_queue = xQueueCreate(3, PUB_MSG_LEN);
  xTaskCreate(&blinkenTask, "blinkenTask", 256, NULL, 2, NULL);
  xTaskCreate(&wifi_task, "wifi_task",  256, NULL, 2, NULL);
  xTaskCreate(&beat_task, "beat_task", 256, NULL, 3, NULL);
  xTaskCreate(&mqtt_task, "mqtt_task", 1024, NULL, 4, NULL);
}
