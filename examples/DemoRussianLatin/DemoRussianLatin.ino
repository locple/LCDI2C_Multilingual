/*
  ** DemoRussianLatin**
  Print multiple Russian strings to LCD1602
  (Russian+Latin ROM type) using I2C (PCF8574).
  Author: Loc P. Le <phuocloc@gmail.com>

  ** Class **
  - LCDI2C_RussianLatin: for printing Russian (capital only) & Latin to LCDs with Russian ROM

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

//#include <LCDI2C_Multilingual.h>     // Include the whole header file
#include <LCDI2C_RussianLatin.h>       // or separate header file

LCDI2C_RussianLatin lcd(0x27, 16, 2);  // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.println("ПОДМОСКОВНЫЕ ВЕЧЕРА");
  delay(3000); lcd.clear();
  lcd.println("НЕ СЛЫШНЫ В САДУ ДАЖЕ ШОРОХИ, ВСЁ ЗДЕСЬ ЗАМЕРЛО ДО УТРА. ЕСЛИ Б ЗНАЛИ ВЫ, КАК МНЕ ДОРОГИ, ПОДМОСКОВНЫЕ ВЕЧЕРА", 3);
  delay(3000); lcd.clear();
  lcd.println("РЕЧКА ДВИЖЕТСЯ И НЕ ДВИЖЕТСЯ, ВСЯ ИЗ ЛУННОГО СЕРЕБРА. ПЕСНЯ СЛЫШИТСЯ И НЕ СЛЫШИТСЯ, В ЭТИ ТИХИЕ ВЕЧЕРА", 3);
  delay(3000); lcd.clear();
  lcd.println("ЧТО Ж ТЫ, МИЛАЯ, СМОТРИШЬ ИСКОСА, НИЗКО ГОЛОВУ НАКЛОНЯ", 3);
  delay(3000); lcd.clear();
  lcd.println("ТРУДНО ВЫСКАЗАТЬ И НЕ ВЫСКАЗАТЬ. ВСЁ, ЧТО НА СЕРДЦЕ У МЕНЯ", 3);
  delay(3000); lcd.clear();
  lcd.println("А РАССВЕТ УЖЕ ВСЁ ЗАМЕТНЕЕ. ТАК, ПОЖАЛУЙСТА, БУДЬ ДОБРА", 3);
  delay(3000); lcd.clear();
  lcd.println("НЕ ЗАБУДЬ И ТЫ ЭТИ ЛЕТНИЕ, ПОДМОСКОВНЫЕ ВЕЧЕРА", 3);
}

void loop() {}