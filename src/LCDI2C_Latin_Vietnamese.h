/*
  ** LCDI2C_Latin_Vietnamese class **
  For printing Latin-1 (French, Spanish, ...), Vietnamese text
  and Greek symbols in UTF-8 (NFC normalized) to I2C LCD.

  ** Compatible LCDs **
  Only used for LCD chips with Latin-1 character ROM:
  - Wuxi AIP31066W2
  - Sitronix ST7066-0B
  - Surenoo SLC European series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 22 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Latin_Vietnamese_h
#define LCDI2C_Latin_Vietnamese_h

#include "LCDI2C_Latin.h"
#include "Custom/Vietnamese.h"

class LCDI2C_Latin_Vietnamese : public LCDI2C_Latin {
public:
  LCDI2C_Latin_Vietnamese(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_Latin(lcd_addr, lcd_cols, lcd_rows) {
    //setLongestWordLength(7);
    customizedLanguage = new CustomizedVietnamese(static_cast<LCDI2C_UTF8*>(this));
  }
};

#endif  // LCDI2C_Latin_Vietnamese_h