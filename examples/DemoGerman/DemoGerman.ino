/*
  ** DemoGerman **
  Print German text (UTF-8, NFC normalizaed) to
  LCD1602 (European ROM type) via I2C (PCF8574).
  Author: Loc P. Le <phuocloc@gmail.com>

  ** Class **
  - LCDI2C_Latin: for printing European languages (French, Spanish,
    German, Finnish, ...) to LCDs with Latin ROM (European ROM).

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>

LCDI2C_Latin lcd(0x27, 16, 2);        // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init(); lcd.backlight();
  lcd.print("Ist das Wetter dafür schön?");
  lcd.println(" 5°C");
}

void loop() {}
