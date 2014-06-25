This is the Adafruit MAX31885 Arduino Library ported to Spark Core
---

Tested and works great with the Adafruit Thermocouple Breakout w/MAX31885K 
------> http://www.adafruit.com/products/269

These modules use SPI to communicate, 3 pins are required to
interface. Technically this is a software SPI implementation, so these pins can be defined anywhere on the Spark Core. For simplicity, the pins used below are the same pins used for the Hardware SPI.

```
MAX31885 Breakout    Spark Core
Vin                  3V3*
3Vo                  (No Connection)
GND                  GND
DO (Data Out)        A4 (MISO)
CS (Chip Select)     A2 (SS)
CLK (Clock)          A3 (SCK)
```

Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries. Ported to Spark Core by Technobly.
BSD license, check LICENSE for more information All text above must be included in any redistribution