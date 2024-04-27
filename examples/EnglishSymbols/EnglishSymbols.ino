/*
  ** EnglishSymbols **
  Print English text and customized symbols (° €) to LCD1602
  (using generic ROM or any other ROM) via I2C (PCF8574).
  Author: Loc P. Le <phuocloc@gmail.com>

  ** Class **
  - LCDI2C_Symbols (LCDI2C_Generic_Symbols): for printing English and
  customized symbols (° €) with generic ROM (Japanese ROM) or any other ROM.

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>

LCDI2C_Symbols lcd(0x27, 16, 2);           // I2C address: 0x27; Display size: 16x2
//LCDI2C_Generic_Symbols lcd(0x27, 16, 2); // Another name of LCDI2C_Symbols class

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("Temperature:25°C");
  lcd.println("Price:      €500");
}

void loop() {}