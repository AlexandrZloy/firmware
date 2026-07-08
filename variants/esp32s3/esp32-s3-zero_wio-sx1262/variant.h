/*

*/
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// Buttons
#define BUTTON_PIN 43 // TX pin
// UART
#define UART_TX 16
#define UART_RX 15
// I2C
#define I2C_SCL 8
#define I2C_SDA 7

// Board has RGB LED 21
#define HAS_NEOPIXEL                         // Enable the use of neopixels
#define NEOPIXEL_COUNT 1                     // How many neopixels are connected
#define NEOPIXEL_DATA 21                     // gpio pin used to send data to the neopixels
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800) // type of neopixels in use

//#define BATTERY_PIN 7
//#define ADC_CHANNEL ADC_CHANNEL_6
// #define ADC_CHANNEL ADC_CHANNEL_5
//   ratio of voltage divider = 3.0 (R17=200k, R18=100k)
//#define ADC_MULTIPLIER 3.1 // 3.0 + a bit for being optimistic

#define USE_SX1262

#define LORA_MISO 2
#define LORA_SCK 3
#define LORA_MOSI 1
#define LORA_CS 11

#define LORA_RESET 13
#define LORA_DIO1 44 // RX pin
#define LORA_DIO2 12
#define LORA_RXEN 10

#ifdef USE_SX1262
#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_DIO2_AS_RF_SWITCH // DIO2 is used to control the TX side of the RF switch
#define SX126X_ANT_SW LORA_RXEN // Broken in the SX126xInterface.cpp: tries to call digitalWrite() before pinMode()!
#ifndef SX126X_ANT_SW
    #define SX126X_RXEN LORA_RXEN
    #define SX126X_TXEN RADIOLIB_NC
#endif
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif
