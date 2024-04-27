# LiquidCrystal_I2C_Multilingual
Arduino library for printing multilingual UTF-8 strings (French, Spanish, Finnish, Russian, Vietnamese, Katakana, etc.) and specific symbols to LCD1602, LCD2004, LCD0801, etc. via I2C (PCF8574).

Unicode strings might need to be normalized in NFC beforehand for better compatibility.

This library is continued from LiquidCrystal_I2C_UTF8 library.

## Hardware Required
*Similar to LiquidCrystal_I2C*
- **MCU dev board**: Arduino /Uno/Mini/Nano/Micro, ESP8266, ESP32, WeMos LOLIN D1 Mini, WeMos LOLIN D32, ...
- **LCD** (1602, 2004, ...) using controller:
  Hitachi HD44780U, Wuxi AIP31066, Samsung KS0066, Jewel SPLC780D, Sitronix ST7066

  *For convenience, you can buy LCD with an I2C adapter soldered instead doing it yourself.*
- **I2C adapter** using PCF8574 chip having 1x16-pin or 2x8-pin interface to LCD.

  *Refer to table below to find the I2C adapter having right pin type for the LCD:*

|   LCD  | 0801 | 0802 | 1601 | 1602 | 1604 | 2002 | 2004 | 2402 | 4002 | 4004 |
|:------:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|Pin type|2x7 +2|  2x8 | 1x16 | 1x16 | 1x16 | 2x8  | 1x16 |  2x8 |  2x8 |  2x8 |

## I2C Wiring
*Similar to LiquidCrystal_I2C*
- Solder or connect I2C's 1x16 (or 2x8) pins to LCD's 1x16 (or 2x8) pins
- Connect I2C's GND pin to MCU's GND pin
- Connect I2C's VCC pin to MCU's VIN pin
- Connect I2C's **SCL** pin to MCU's SCL pin (*see table below for pin location*)
- Connect I2C's **SDA** pin to MCU's SDA pin (*see table below for pin location*)

|    Pin  | Arduino Uno/Mini/Nano | Arduino Micro | LOLIN D1 Mini | ESP8266 | LOLIN D32 | ESP32 |
|:-------:|:---------------------:|:-------------:|:-------------:|:-------:|:-----:|:-----:|
| **SCL** |           A5          |       3       |        5      |   D1    |  22   |  D22  |
| **SDA** |           A4          |       2       |        4      |   D2    |  21   |  D21  |

## Find Display Size
|  LCD  | 0801 | 0802 | 1601 | 1602 | 1604 | 2002 | 2004 | 2402 | 4002 | 4004 |
|:-----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|columns|   8  |   8  |  16  |  16  |  16  |  20  |  20  |  24  |  40  |  40  |
|  rows |   1  |   2  |   1  |   2  |   4  |   2  |   4  |   2  |   2  |   4  |

## Find I2C Address
See pin A0, A1, A2 on I2C adapter:

For I2C PCF8574 using **TI** (Texas Instruments) chip: *(most likely **0x27**)*

![I2C TI PCF8574](https://lastminuteengineers.com/wp-content/uploads/arduino/I2C-LCD-Address-Selection-Jumper-Table-for-TI.png)

For I2C PCF8574 using **NXP** chip: *(most likely **0x3F**)*

![I2C NXP PCF8574](https://lastminuteengineers.com/wp-content/uploads/arduino/I2C-LCD-Address-Selection-Jumper-Table-for-NXP.png)

Otherwise, use I2C scanning program to detect I2C address:
https://learn.adafruit.com/scanning-i2c-addresses/arduino

## Print temperature and price in Finnish to LCD1602 (*Latin ROM*)
```C++
#include <LCDI2C_Multilingual.h>

LCDI2C_Latin_Symbols lcd(0x27, 16, 2);    // I2C address = 0x27; Display columns = 16, rows = 2

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight

  lcd2.println("Lämpötila:  25°C");
  lcd2.println("Yhteensä:   €500");
}
void loop() {}
```

## Print a long Russian string to LCD2004 (*Russian ROM*)
```C++
#include <LCDI2C_Multilingual.h>

LCDI2C_Russian lcd(0x27, 20, 4);          // I2C address = 0x27; Display columns = 20, rows = 4

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight
  lcd.print("Подмосковные вечера - одна из самых популярных советских песен, её исполняли \
известные эстрадные и академические певцы, хоры и оркестры в СССР и за рубежом.", 3);
}
void loop() {}
```

## Print a Vietnamese string to LCD1602 using customized characters
```C++
#include <LCDI2C_Multilingual.h>

LCDI2C_Vietnamese lcd(0x27, 16, 2);       // I2C address = 0x27; Display columns = 16, rows = 2

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight
  lcd.println("Cao đẳng Công thương Việt Nam");
}
void loop() {}
```

*See more demos in examples folder.*

## What class used to print
There three cases:
- Print using ROM's language only
- Print using both ROM's language and customized symbols created in CGRAM
- Print using both ROM's language and customized language created in CGRAM
### Classes for printing the language built in LCD's ROM
*Include one of the following files depending on LCD's ROM type*
|                  | ROM_Standard_JP.h | ROM_Standard_EU.h |  ROM_Standard_RU.h | ROM_Surenoo_RU.h |
|:----------------:|:-----------------:|:-----------------:|:------------------:|:----------------:|
| **For LCD chips**|**HD44780UA00, AIP31066, KS0066F00, KS0066F04, SPLC780D, ST7066-0A**|**AIP31066W2, ST7066-0B**|**HD44780UA02**|**Surenoo SLC series (Russian)**|
|    **Russian**   |        :x:        |        :x:        |**Capital letters only**|:heavy_check_mark:|
|  Special symbols | ÷ √ ∞ → ← | ± ≈ ² ³ × ÷ ≤ ≥ √ ∞ ↵ ↑ ↓ → ← | ↵ ↑ ↓ → ← ≤ ≥ ± ² ³ × ÷ ∞ | ↵ ↑ → ↓ ← × |
|   Greek symbols  |Σ Ω α β δ ε θ μ π ρ|Σ Ω α β γ δ ε η θ μ π ρ σ ψ ω|Σ Ω α β δ ε θ μ π σ ω|       |
| Currency symbols |          ¥        |       ¢ £ ¥       |        ¢ £ ¥       |        ¢ £       |

### Class for printing both the language built in LCD's ROM and customized symbols in LCD's CGRAM
*Include one of the following files depending on character set needed*
| Character set |  LCDI2C_UTF8.h   |       LCDI22C_Viet.h      |
|:-------------:|:----------------:|:-------------------------:|
|  **Symbols**  |    Degree (°)    |         Degree (°)        |
|  **English**  |:heavy_check_mark:|     :heavy_check_mark:    |
| **Vietnamese**|        :x:       |:heavy_check_mark::warning:|
> :warning: Due to CGRAM limit, maximum of 8 different Vietnamese letters with diacritics can be printed on a screen, otherwise diacritics removed.
> But it's usually adequate to print full of Vietnamese text on LCD0801, LCD0802, LCD1602.

### Class for printing both the language available in LCD's ROM and customized language in LCD's CGRAM

## Function print()
- `print(text)`: print UTF-8 text (String or char[]) to LCD
> If no room in current line for the next word, it'll be printed in the next line.
- `print(text, nsec)`: print long text with **nsec** seconds paused
> If no room in the screen to print more, wait **nsec** seconds for audiences to read before clearing to print the next part.

## Not yet support
- Autoscroll
- Printing Hebrew on Hebrew ROM!!
