# LiquidCrystal_I2C_Multilingual
Arduino library for printing multilingual UTF-8 strings (Katakana, Russian, French, Spanish, Finnish, Norwegian, Luxembourgish, German, Vietnamese, etc.) and specific symbols to LCD1602, LCD2004, LCD0801, etc. via I2C (PCF8574).

**LCD module must have appropriate language font built in its ROM**, except some languages like Vietnamese use customized font in CGRAM. Unicode strings might need to be normalized in NFC beforehand for better compatibility.

This library is continued from LiquidCrystal_I2C_UTF8 library, with adding more languages and support for more concurrent connected I2C LCDs.

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

## Print temperature and price in Finnish to LCD1602 (Latin ROM)
```C++
#include <LCDI2C_Multilingual.h>

LCDI2C_Latin_Symbols lcd(0x27, 16, 2);    // I2C address = 0x27; LCD = Surenoo SLC1602A (European)

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight

  lcd2.println("Lämpötila:  25°C");
  lcd2.println("Yhteensä:   €500");
}
void loop() {}
```

## Print a long Russian string to LCD2004 (Russian ROM)
```C++
#include <LCDI2C_Multilingual.h>

LCDI2C_Russian lcd(0x27, 20, 4);          // I2C address = 0x27; LCD = Surenoo SLC2004A (Russian)

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight
  lcd.print("Подмосковные вечера - одна из самых популярных советских песен, её исполняли \
известные эстрадные и академические певцы, хоры и оркестры в СССР и за рубежом.", 3); // wait 3s
}
void loop() {}
```

## Print a Vietnamese string to LCD1602 using customized characters
```C++
#include <LCDI2C_Multilingual.h>

LCDI2C_Vietnamese lcd(0x27, 16, 2);       // I2C address = 0x27; LCD1602A (16 columns, 2 rows)

void setup() {
  lcd.init();                             // Initialize the LCD
  lcd.backlight();                        // Turn on the LCD backlight
  lcd.println("Cao đẳng Công thương Việt Nam");
}
void loop() {}
```

## Dual languages on dual LCDs using letters from both ROM & CGRAM
```C++
#include <LCDI2C_Multilingual.h>

LCDI2C_Katakana_Vietnamese lcd1(0x27, 20, 4); // I2C address: 0x27; LCD = Surenoo SLC2004A (Japanese)
LCDI2C_Latin_Vietnamese lcd2(0x26, 16, 2);    // I2C address: 0x26; LCD = Surenoo SLC1602A (European)

void setup() {
  lcd1.init(); lcd1.backlight();
  lcd2.init(); lcd2.backlight();

  lcd1.println("Select language:");
  lcd1.println("1. English");
  lcd1.println("2. ジャパネセ「カタカナ」");    // Japanese Kana
  lcd1.println("3. Tiếng Việt");              // Vietnamese

  lcd2.println("Türkçe là tiếng Thổ Nhĩ Kỳ);  // Turkish + Vietnamese
}

void loop() {}
```

*See more demos in examples folder.*

![Triple I2C LCDs multilingual](https://i.postimg.cc/GpcgwTS6/Triple-LCDs.jpg "3 I2C LCDs multilingual")


## What class to use?
There are three cases:
- Print using ROM's language only
- Print using both ROM's language and customized symbols created in CGRAM
- Print using both ROM's language and customized language created in CGRAM
### Classes for the language built in LCD's ROM
*Choose the following classes depending on LCD's ROM type*
|         *Class*       |     *English*    |    *Japanese*    |     *Russian*    |*European languages*|  *Symbols*  | *Supported LCD chips* |
|:----------------------|:----------------:|:----------------:|:----------------:|:------------------:|:-----------:|:---------------------:|
|   **LCDI2C_Generic**  |:heavy_check_mark:|       :x:        |       :x:        |         :x:        |**¥** ÷ → ←  |HD44780UA00, AIP31066, KS0066F00, KS0066F04, SPLC780D, ST7066-0A, Surenoo SLC series|
|  **LCDI2C_Katakana**  |:heavy_check_mark:|:heavy_check_mark:|       :x:        |         :x:        |    **¥**    |HD44780UA00, AIP31066, KS0066F00, KS0066F04, SPLC780D, ST7066-0A, Surenoo SLC series (Japanese)|
|    **LCDI2C_Latin**   |:heavy_check_mark:|       :x:        |       :x:        | :heavy_check_mark: |**¢ £ ¥** ± ≈ ² ³|AIP31066W2, ST7066-0B, Surenoo SLC series (European)|
|**LCDI2C_RussianLatin**|:heavy_check_mark:|       :x:        |   Capital only   | :heavy_check_mark: |**¢ £ ¥** Latin-1 symbols|      HD44780UA02     |
|   **LCDI2C_Russian**  |:heavy_check_mark:|       :x:        |:heavy_check_mark:|         :x:        |   **¢ £**   |Surenoo SLC series (Russian) |

### Classes for the language built in ROM + customized symbols created in CGRAM
*Choose the following classes if you need specific symbols (° €) in addition to the above base class*
|             *Class*           |*All characters from*|*Additional symbols*|
|:------------------------------|:--------------------|:------------------:|
|       **LCDI2C_Symbols**      |    LCDI2C_Generic   |       **° €**      |
|  **LCDI2C_Katakana_Symbols**  |   LCDI2C_Katakana   |       **° €**      |
|   **LCDI2C_Latin_Symbols**    |     LCDI2C_Latin    |       **° €**      |
|**LCDI2C_RussianLatin_Symbols**| LCDI2C_RussianLatin |       **° €**      |
|   **LCDI2C_Russian_Symbols**  |    LCDI2C_Russian   |       **° €**      |

### Classes for the language built in ROM + the customized language created in CGRAM
*Choose the following classes if you need support for Vietnamese (not available in any ROM) in addition to the above base class*
|              *Class*             |*All characters from*|   *Vietnamese*   |*Additional symbols*|
|:---------------------------------|:--------------------|:----------------:|:------------------:|
|       **LCDI2C_Vietnamese**      |    LCDI2C_Generic   |:heavy_check_mark:|       **° ₫**      |
|  **LCDI2C_Katakana_Vietnamese**  |   LCDI2C_Katakana   |:heavy_check_mark:|       **° ₫**      |
|   **LCDI2C_Latin_Vietnamese**    |    LCDI2C_Latin     |:heavy_check_mark:|       **° ₫**      |
|**LCDI2C_RussianLatin_Vietnamese**| LCDI2C_RussianLatin |:heavy_check_mark:|       **° ₫**      |
|   **LCDI2C_Russian_Vietnamese**  |    LCDI2C_Russian   |:heavy_check_mark:|       **° ₫**      |

> :warning: Due to CGRAM size limit, maximum of 8 different Vietnamese letters with diacritics can be printed on a screen, otherwise diacritics removed.
> However it's usually adequate to print full of Vietnamese text on LCD0801, LCD0802, LCD1602.

## Function print()
- `print(text)`: print UTF-8 text (String or char[]) to LCD
> If no room in current line for the next word, it'll be printed in the next line.
- `print(text, nsec)`: print long text with **nsec** seconds paused
> If no room in the screen to print more, wait **nsec** seconds for audiences to read before clearing to print the next part.

## Not yet support
- Autoscroll, __FlashStringHelper, Printable
- Printing Hebrew on Hebrew ROM!!
