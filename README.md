# ESPVario
Simple PPG variometer, CHT, EGT and RPM display. Of course not working yet... :construction: :smile:

## ESP8266 connections

![ESP pinout](img/esp12e-pinout.png)
![ESP pinout](img/pin_functions.png)
http://www.esp8266.com/wiki/doku.php?id=esp8266_gpio_pin_allocations

| Function | ESP pin | 
| ------ | ------ |
| MISO  | GPIO 12 |
| MOSI  | GPIO 13 |
| SCK | GPIO 14 |
| CS1 EGT | GPIO 0  |
| CS2 CHT | GPIO 2  |
| CS3 SD| GPIO 15 |
| SDA | GPIO 4 |
| SCL | GPIO 5 |
| RPM | GPIO 16 |
|Vario out|GPIO 1|
|Battery V|TOUT/ADC|
|GPS|GPIO 3|

| Function | ESP pin | NodeMCU |
| ------ | ------ | ------ |
| MISO (TFT) | GPIO 12 | D6 |
| MOSI (TFT) | GPIO 13 | D7 |
| SCK (TFT) | GPIO 14 | D5 |
| DC (TFT) | GPIO 16 | D0 |
| CS (TFT) | GPIO 0 | D3 |
| Sensor RXD | GPIO 3 | RX |
| SDA (pressure, gesture) | GPIO 4 | D2 |
| SCL (pressure, gesture) | GPIO 5 | D1 |

Vario out, SD, gesture int.

GPIO 1,2,9,10,15
