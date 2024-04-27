/*
  ** LCDI2C_RussianLatin_Symbols class **
  For printing Russian (capital only) and common symbols (° €)
  UTF-8 strings (NFC normalized) to I2C LCD.

  ** Compatible LCDs **
  Only used for LCD chips with RussianLatin character ROM:
  - Hitachi HD44780UA02

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 22 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_RussianLatin_Symbols_h
#define LCDI2C_RussianLatin_Symbols_h

#include "LCDI2C_RussianLatin.h"
#include "Custom/Symbols.h"

class LCDI2C_RussianLatin_Symbols : public LCDI2C_RussianLatin {
public:
  LCDI2C_RussianLatin_Symbols(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_RussianLatin(lcd_addr, lcd_cols, lcd_rows) {
	customizedLanguage = new CustomizedSymbols(static_cast<LCDI2C_UTF8*>(this));
  }
};

#endif  // LCDI2C_RussianLatin_Symbols_h