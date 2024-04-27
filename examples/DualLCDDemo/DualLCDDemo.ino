/*
  ** DualLCDDemo **
  Print UTF-8 text (NFC normalized) in
  English, Japanese Katakana, Vietnamese to LCD2004 (Japanese ROM type)
  and in English, Vietnamese to LCD1602 (any ROM) via I2C (PCF8574).
  Author: Loc P. Le <phuocloc@gmail.com>

  Note:
  - LCDI2C_Katakana_Vietnamese: for printing English, Katakana
    (using ROM) and Vietnamese (using CGRAM) to LCDs with Japanese ROM.
  - LCDI2C_Vietnamese (LCDI2C_Generic_Vietnamese): for printing
    English, Vietnamese to LCDs with generic ROM (any other ROM)
	  using customized characters created in CGRAM.

  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>

LCDI2C_Katakana_Vietnamese lcd1(0x27, 20, 4); // I2C address: 0x27; Display size: 20x4
LCDI2C_Vietnamese lcd2(0x26, 16, 2);          // I2C address: 0x26; Display size: 16x2

void setup() {
  lcd1.init(); lcd1.backlight();
  lcd2.init(); lcd2.backlight();

  lcd1.println("Select language:");
  lcd1.println("1. English");
  lcd1.println("2. ジャパネセ「カタカナ」");
  lcd1.println("3. Tiếng Việt");

  lcd2.println("1. English");
  lcd2.println("2. Tiếng Việt");
}

void loop() {}