/*
  ** LCDI2C_Katakana_Vietnamese class **
  For printing Japanese Katakana & Vietnamese
  UTF-8 strings (NFC normalized) to I2C LCD.

  ** Compatible LCDs **
  Only used for LCD chips with Japanese character ROM (Katakana font):
  - Hitachi HD44780UA00
  - Wuxi AIP31066
  - Samsung KS0066F00, KS0066F04
  - Jewel Hill SPLC780D1, SPLC063
  - Sitronix ST7066-0A
  - Surenoo SLC Japanese series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 22 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Katakana_Vietnamese_h
#define LCDI2C_Katakana_Vietnamese_h

#include "LCDI2C_Katakana.h"
#include "Custom/Vietnamese.h"

class LCDI2C_Katakana_Vietnamese : public LCDI2C_Katakana {
public:
  LCDI2C_Katakana_Vietnamese(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_Katakana(lcd_addr, lcd_cols, lcd_rows) {
    setLongestWordLength(7);
	customizedLanguage = new CustomizedVietnamese(static_cast<LCDI2C_UTF8*>(this));
  }
};

#endif LCDI2C_Katakana_Vietnamese_h