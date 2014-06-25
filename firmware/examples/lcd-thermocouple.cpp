/*************************************************** 
  This is an example for the Adafruit Thermocouple Sensor w/MAX31855K

  Designed specifically to work with the Adafruit Thermocouple Sensor
  ----> https://www.adafruit.com/products/269

  These displays use SPI to communicate, 3 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include "math.h"
#include "Adafruit_MAX31855.h"
#include "LiquidCrystal/LiquidCrystal.h"

int thermoCLK = A3;
int thermoCS = A2;
int thermoDO = A4;

// Initialize the Thermocouple
Adafruit_MAX31855 thermocouple(thermoCLK, thermoCS, thermoDO);
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(D2, D3, D4, D5, D6, D7);

  
void setup() {
  // open serial terminal and press ENTER to start
  Serial.begin(9600);
  while(!Serial.available()) SPARK_WLAN_Loop();

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  lcd.print("MAX31855 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
   lcd.setCursor(0, 0);
   lcd.print("Int. Temp = ");
   lcd.println(thermocouple.readInternal());
   lcd.print("  "); 
     
   double c = thermocouple.readCelsius();
   lcd.setCursor(0, 1);
   if (isnan(c)) 
   {
     lcd.print("T/C Problem");
   } 
   else 
   {
     lcd.print("C = "); 
     lcd.print(c);
     lcd.print("  "); 
   }
 
   delay(1000);
}
