/*
  ** LCDI2C_Generic class **
  For printing ASCII strings and
  some Greek UTF-8 symbols (NFC normalized) to I2C LCD.

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

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Generic_h
#define LCDI2C_Generic_h

#include "ROM/Generic.h"
#include "base/LCDI2C_UTF8.h"

class LCDI2C_Generic : public LCDI2C_UTF8 {
public:
  LCDI2C_Generic(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_UTF8(lcd_addr, lcd_cols, lcd_rows) {
    ROMLetterNum = GenericROMLetterNum;
	ROMLetters = GenericROMLetters;
	setLongestWordLength(10);
  }
};

typedef LCDI2C_Generic LiquidCrystal_I2C_Generic;

#endif // LCDI2C_Generic_h