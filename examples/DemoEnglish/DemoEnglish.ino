/*
  ** DemoEnglish **
  Print a long English text to a LCD2004 (generic ROM type or any ROM) via I2C
  (PCF8574), call also some methods of the parent class (LiquidCrystal_I2C).
  Author: Loc P. Le <phuocloc@gmail.com>

  ** Class **
  - LCDI2C_Generic: for printing English to LCDs with generic ROM
    (Japanese ROM) or any other ROM.

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>

LCDI2C_Generic lcd(0x27, 20, 4);  // I2C address: 0x27; Display size: 20x4

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.print("Ernest Miller Hemingway was born in Chicago in 1899 as the son of a doctor\
 and the second of six children. After a stint as an ambulance driver at the Italian front,\
 Hemingway came home to America in 1919, only to return to the battlefield - this time\
 as a reporter on the Greco-Turkish war - in 1922. Resigning from journalism to focus on\
 his writing instead, he moved to Paris where he renewed his earlier friendship with fellow\
 American expatriates such as Ezra Pound and Gertrude Stein. Through the years, Hemingway\
 travelled widely and wrote avidly, becoming an internationally recognized literary\
 master of his craft. He received the Nobel Prize for Literature in 1954, following\
 the publication of The Old Man and the Sea.", 3); // wait for 3 seconds before each next screen
  lcd.println();
  lcd.print("He died in 1961.");

  lcd.setCursor(8, 2); lcd.println("←÷→");
  lcd.println("(https://amazon.com)");
}

void loop() {}