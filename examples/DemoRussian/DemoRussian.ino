/*
  ** DemoRussian **
  Print a long Russian text (UTF-8, NFC normalized) to LCD1602
  (Russian ROM type like Surenoo SLC1602 Russian) via I2C (PCF8574).
  Author: Loc P. Le <phuocloc@gmail.com>

  ** Class **
  - LCDI2C_Russian: for printing Russian UTF-8 text to LCDs with Russian ROM

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>

LCDI2C_Russian lcd(0x27, 16, 2);  // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("Расцветали яблони и груши, Поплыли туманы над рекой.\
 Выходила на берег Катюша, На высокий берег на крутой.\
 Выходила, песню заводила, Про степного, сизого орла,\
 Про того, которого любила, Про того, чьи письма берегла.\
 Ой ты, песня, песенка девичья, Ты лети за ясным солнцем вслед.\
 И бойцу на дальнем пограничье, От Катюши передай привет.\
 Пусть он вспомнит девушку простую, Пусть услышит, как она поет,\
 Пусть он землю бережет родную, А любовь Катюша сбережет.", 4); // wait for 4 seconds before each next screen
}

void loop() {}