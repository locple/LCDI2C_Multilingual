/*
  ** LCDI2C_Vietnamese class **
  A LCDI2C_Generic subclass makes Vietnamese
  as LCD's additional language using customized characters in CGRAM.
  Max 8 customized characters printed at once.

  ** Compatible LCDs **
  Only used for LCD chips with regular ROM (Japanese ROM - the most popular):
  - Hitachi HD44780UA00
  - Wuxi AIP31066
  - Samsung KS0066F00, KS0066F04
  - Jewel Hill SPLC780D1, SPLC063
  - Sitronix ST7066-0A
  - Surenoo SLC Japanese series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Vietnamese tones & diacritics for 5x8 Latin letters (C) 2023 Loc P. Le

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Vietnamese_h
#define LCDI2C_Vietnamese_h

#include "LCDI2C_Generic.h"
#include "Custom/Vietnamese.h"

class LCDI2C_Vietnamese : public LCDI2C_Generic {
public:
  LCDI2C_Vietnamese(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_Generic(lcd_addr, lcd_cols, lcd_rows) {
	setLongestWordLength(7);
	customizedLanguage = new CustomizedVietnamese(static_cast<LCDI2C_UTF8*>(this));
  }
};

typedef LCDI2C_Vietnamese LCDI2C_Generic_Vietnamese;

#endif  // LCDI2C_Vietnamese_h