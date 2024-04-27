/*
  ** MultipleStringDemo **
  Print multiple Vietnamese strings (UTF-8, NFC normalized)
  to a LCD2004 (generic ROM type or any ROM) via I2C (PCF8574)
  Author: Loc P. Le <phuocloc@gmail.com>

  Note:
  - LCDI2C_Vietnamese (LCDI2C_Generic_Vietnamese): for printing
    Vietnamese to LCDs with generic ROM (Japanese ROM or any other ROM)
	  using customized characters created in CGRAM.
  - Max 8 Vietnamese letters with diacritics printed on a screen, otherwise diacritics removed.
  - If no longer room to print the next word in current line, it'll be printed in next line.

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <LCDI2C_Multilingual.h>
//#include <LCDI2C_Vietnamese.h>

LCDI2C_Vietnamese lcd(0x27, 20, 4);  // I2C address: 0x27; Display size: 20x4

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("Bộ đội gặp bợm!");
  lcd.println("Chập choạng, một bợm");
  lcd.println("nhậu nhậu chục xị rượu Ngọc Lợn.");
  delay(4000); lcd.clear();

  lcd.print("Bợm nọ khệnh khạng");
  lcd.println("dựa cột điện, gặp");
  lcd.println("chị bộ đội tại địa phận chạy lại.");
  delay(4000); lcd.clear();

  lcd.print("Chị bộ đội đội chục");
  lcd.println("hột vịt lộn thật nặng nhọc.");
  delay(4000); lcd.clear();

  lcd.println("Bợm gặp mặt chị đẹp");
  lcd.println("tuyệt, định chặn chị");
  lcd.println("bộ đội lại \"bậy bạ\".");
  delay(4000); lcd.clear();

  lcd.println("Chị sợ, chạy gọi cụ");
  lcd.println("thợ điện cạnh bệnh viện.");
}

void loop() {}