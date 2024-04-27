/*
  ** LCDI2C_Russian_Symbols class **
  For printing Russian and some common symbols (° €)
  in UTF-8 (NFC normalized) to I2C LCD.

  ** Compatible LCDs **
  Only used for LCD chips with Russian character ROM:
  - Wuxi AIP31066W3
  - Surenoo SLC Russian series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 22 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Russian_Symbols_h
#define LCDI2C_Russian_Symbols_h

#include "LCDI2C_Russian.h"
#include "Custom/Symbols.h"

class LCDI2C_Russian_Symbols : public LCDI2C_Russian {
public:
  LCDI2C_Russian_Symbols(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_Russian(lcd_addr, lcd_cols, lcd_rows) {
	customizedLanguage = new CustomizedSymbols(static_cast<LCDI2C_UTF8*>(this));
  }
};

#endif  // LCDI2C_Russian_Symbols_h