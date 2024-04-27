/*
  ** TripleLCDDemo **
  Print customized symbols (° €) and UTF-8 text (NFC normalized)
  in English, Japanese to LCD2004 (using Japanese ROM) and
  in Finnish to LCD1602 (using Latin ROM) and
  in Russian to LCD1602 (using Russian ROM)
  via I2C (PCF8574).
  Author: Loc P. Le <phuocloc@gmail.com>

  ** Classes **
  - LCDI2C_Katakana_Symbols: for printing English, Katakana and customized symbols with LCD's Japanese ROM
  - LCDI2C_Latin_Symbols: for printing English, Latin (European) and customized symbols with LCD's Latin ROM
  - LCDI2C_Russian_Symbols: for printing English, Russian and customized symbols with LCD's Russian ROM

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>

LCDI2C_Katakana_Symbols lcd1(0x27, 20, 4); // I2C address: 0x27; Display size: 20x4
LCDI2C_Latin_Symbols lcd2(0x26, 16, 2);    // I2C address: 0x26; Display size: 16x2
LCDI2C_Russian_Symbols lcd3(0x25, 16, 2);  // I2C address: 0x25; Display size: 16x2

void setup() {
  lcd1.init(); lcd1.backlight();
  lcd2.init(); lcd2.backlight();
  lcd3.init(); lcd3.backlight();

  lcd1.println("Temperature:25°C");
  lcd1.println("In total:   €500");
  lcd1.println("テンプレチャー:   25°C");
  lcd1.println("プライス:      €500");

  lcd2.println("Lämpötila:  25°C");
  lcd2.println("Yhteensä:   €500");

  lcd3.println("Температура:20°C");
  lcd3.println("Цена:       €500");
}

void loop() {}