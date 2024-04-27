/*
  ** DemoFrench **
  Print French text (UTF-8, NFC normalized) to
  LCD1602 (European ROM type) via I2C (PCF8574).
  Author: Loc P. Le <phuocloc@gmail.com>

  ** Class **
  - LCDI2C_Latin: for printing European languages (French, Spanish,
    German, Finnish, ...) to LCDs with Latin ROM (European ROM).

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>      // Include the whole header file
//#include <LCDI2C_Latin.h>           // or separate header file

LCDI2C_Latin lcd(0x27, 16, 2);        // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init(); lcd.backlight();
  lcd.println("La décoration du bâtiment d'un Noël français est la crèche.", 3); // wait for 3 seconds before next screen
  delay(2000); lcd.clear();
  lcd.println("Ça température =25±3°C");
}

void loop() {}
