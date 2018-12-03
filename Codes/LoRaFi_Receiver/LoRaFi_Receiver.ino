//LoRaFi Receiver example
/*
  LoRa Simple Arduino Server :
  Support Devices: 
  * LoRa Mini
  * LoRa Shield + Arduino;
  * LoRa GPS Shield + Arduino. 
  
  Example sketch showing how to create a simple messageing server, 
  with the RH_RF95 class. RH_RF95 class does not provide for addressing or
  reliability, so you should only use RH_RF95 if you do not need the higher
  level messaging abilities.

  It is designed to work with the other example LoRa Simple Client

  modified 16 11 2016
  by Edwin Chen <support@dragino.com>
  Dragino Technology Co., Limited
*/

#include <SPI.h>
#define CS    53
#define RST   22
#define RX_SW 8
#define TX_SW 7
#define DIO0  23
#define MOSI  51
#define MISO  50
#define SCK   52
#include <LoRaFi.h>



  //creat object to call functions of LoRaFi library
  LoRaFi LoRaFi;

  char message[11];

void setup() {
  
  //initialize serial communication
  Serial.begin(9600);
  delay(100);

  //initialize LoRa module
  LoRaFi.begin();
  delay(100);
}

void loop() {

  Serial.print("received Message: ");
  
  int len = 11;

  //Receive message
  LoRaFi.ReceivePackage(message,len);

  //Print received message
  int i;
  for(i=0; i<len; i++)
  {
  Serial.print(message[i]);
  }
  Serial.println();

  delay(1000);

}

