/*
  ** LCDI2C_Katakana class **
  For printing Japanese Katakana UTF-8 strings (NFC normalized) to I2C LCD.

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
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Katakana_h
#define LCDI2C_Katakana_h

#include "ROM/Katakana.h"
#include "base/LCDI2C_Custom.h"
#include "base/LCDI2C_UTF8.h"

class LCDI2C_Katakana : public LCDI2C_UTF8 {
public:
  LCDI2C_Katakana(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
      : LCDI2C_UTF8(lcd_addr, lcd_cols, lcd_rows) {
    ROMLetterNum = KanaROMLetterNum;
    ROMLetters = KanaROMLetters;
    setLongestWordLength(2);
  }

protected:
  uint8_t nextWordLength(const byte text[], uint16_t start,
                         uint16_t code) override;
  uint16_t getCharacter(uint16_t code) override;
};

typedef LCDI2C_Katakana LiquidCrystal_I2C_Katakana;

#endif // LCDI2C_Katakana_h