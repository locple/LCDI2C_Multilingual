/*
  ** LCDI2C_Latin class **
  For printing Latin-1 (French, Spanish, German, ...) text
  and Greek symbols in UTF-8 (NFC normalized) to I2C LCD.

  ** Compatible LCDs **
  Only used for LCD chips with Latin-1 character ROM:
  - Wuxi AIP31066W2
  - Sitronix ST7066-0B
  - Surenoo SLC European series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Latin_h
#define LCDI2C_Latin_h

#include "ROM/Latin.h"
#include "base/LCDI2C_UTF8.h"

class LCDI2C_Latin : public LCDI2C_UTF8 {
public:
  LCDI2C_Latin(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_UTF8(lcd_addr, lcd_cols, lcd_rows) {
    ROMLetterNum = LatinROMLetterNum;
	ROMLetters = LatinROMLetters;
	setLongestWordLength(10);
  }
};

typedef LCDI2C_Latin LiquidCrystal_I2C_Latin;

#endif  // LCDI2C_Latin_h