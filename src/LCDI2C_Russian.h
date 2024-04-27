/*
  ** LCDI2C_Russian class **
  For printing Russian UTF-8 strings (NFC normalized) to I2C LCD.

  ** Compatible LCDs **
  Only used for LCD chips with Russian character ROM:
  - Wuxi AIP31066W3
  - Surenoo SLC Russian series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Russian_h
#define LCDI2C_Russian_h

#include "ROM/Russian.h"
#include "base/LCDI2C_UTF8.h"

class LCDI2C_Russian : public LCDI2C_UTF8 {
public:
  LCDI2C_Russian(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_UTF8(lcd_addr, lcd_cols, lcd_rows) {
    ROMLetterNum = RussianROMLetterNum;
	ROMLetters = RussianROMLetters;
	setLongestWordLength(10);
  }
};

typedef LCDI2C_Russian LiquidCrystal_I2C_Russian;

#endif  // LCDI2C_Russian_h