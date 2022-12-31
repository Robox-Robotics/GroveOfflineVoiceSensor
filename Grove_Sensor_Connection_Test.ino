/*

###########################################

Designed by Anirudha Gaikwad, @_ro.box_ 
https://www.instagram.com/_ro.box_/?hl=en

Grove Offline Voice Recognition Module designed by me communicates over UART,
This code prints the HEX values sent by module over UART, 
List of commands: https://docs.ai-thinker.com/_media/vc-02_v1.0.0_specification.pdf



###########################################



*/


#include <SoftwareSerial.h>

#define SOFTWARE_RX 5   //RX connection of Grove Offline Voice Recognition Module
#define SOFTWARE_TX 6   //TX connection of Grove Offline Voice Recognition Module

SoftwareSerial Grove_Sensor(SOFTWARE_RX, SOFTWARE_TX); // RX, TX

void setup() 
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect. Needed for native USB port only , This port is for displaying data Grove Sensor sends

  Serial.println("USB Serial Port connection Established!");

  // Set the data rate for the SoftwareSerial port - Grove Offline Voice Recognition Module runs at 115200 baud rate
  Grove_Sensor.begin(115200);

}

void loop() 
{ 
  if (Grove_Sensor.available()) 
  {
    Serial.print(Grove_Sensor.read(),HEX);
  }
 delay(10);
}
