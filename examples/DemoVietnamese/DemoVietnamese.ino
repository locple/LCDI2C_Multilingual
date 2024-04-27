/*
  ** DemoVietnamese **
  Print Vietnamese text (UTF-8, NFC normalized) to LCD1602
  (generic ROM type or any ROM) via I2C (PCF8574).
  Author: Loc P. Le <phuocloc@gmail.com>

  ** Class **
  - LCDI2C_Vietnamese (LCDI2C_Generic_Vietnamese): for printing
    Vietnamese to LCDs with generic ROM (Japanese ROM or any other ROM)
	using customized characters created in CGRAM.

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>      // Include the whole header file
//#include <LCDI2C_Vietnamese.h>      // or separate header file

LCDI2C_Vietnamese lcd(0x27, 16, 2);   // I2C address: 0x27; Display size: 16x2
//LCDI2C_Generic_Vietnamese lcd(0x27, 16, 2);  // Another name of LCDI2C_Vietnamese class

void setup() {
  lcd.init();
  lcd.backlight();

  float tempe = 27.78;
  float price = 19.498;
  char buff[7];
  dtostrf(price, 2, 2, buff);
  lcd.println("Nhiệt độ: " + String(tempe, 1) + "°C");
  lcd.print("Thời giá: "); lcd.print(buff); lcd.println("₫");
}

void loop() {}