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
#include "base/LCDI2C_UTF8.h"
#include "base/LCDI2C_Custom.h"

class LCDI2C_Katakana : public LCDI2C_UTF8 {
public:
  LCDI2C_Katakana(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_UTF8(lcd_addr, lcd_cols, lcd_rows) {
    ROMLetterNum = KanaROMLetterNum;
	ROMLetters = KanaROMLetters;
    setLongestWordLength(2);
  }

protected:
  uint8_t   nextWordLength(const byte[], uint16_t, uint16_t code) override {
    // Check for Katakana words with diacritic
    for (uint8_t idx = 0; idx < KanaDiacriticCharacterNum; idx++)
      if (KanaDiacriticCharacters[idx].code == code) return 2;

    // Check for other Katakana words
    if (code >= 0x30A1 && code <= 0x30F3) return 1;

    // Check for English word
    return 1; //// Predicting English word length not supported yet!
  };

  uint16_t  getCharacter(uint16_t code) override {
    uint8_t ord, diacritic = 0;

    if (code < 0x7E)                            // ASCII character?
      if (code > 0x1F)
        return (uint16_t) code;                 // Printable
      else
        return (uint16_t) '*';                  // Non-printable

    // Separate one Katakana character with diacritic into base character and diacritic character
    for (uint8_t idx = 0; idx < KanaDiacriticCharacterNum; idx++)
      if (KanaDiacriticCharacters[idx].code == code) {
        code = KanaDiacriticCharacters[idx].base;
        diacritic = KanaDiacriticCharacters[idx].diacritic;
      }

    // Look for Latin Fullwidth character
    if (code >= 0xFF01 && code <= 0xFF5D)     
      return code - 0xFEE0;				        // Convert Latin Fullwidth to Latin ASCII

    // Base Katakana character (without diacritic) or customized characters (looking in ROM first)
    ord = getROMCharacter(code);
    if (ord == NOTFOUND)                        // Character ready in ROM?
      if (customizedLanguage != NULL) {         // Customized character in CGRAM ?
        ord = customizedLanguage->getCharacter(code, cursorColumn, cursorRow);
        if (ord != NOTFOUND)
          return (uint16_t) ord;                // Customized character
      } else
        return (uint16_t) '*';                  // Unknown character

    if (diacritic == 0)
      return (uint16_t) ord;
    else
      return uint16_t(ord) | (diacritic << 8);
  }
};

typedef LCDI2C_Katakana LiquidCrystal_I2C_Katakana;

#endif LCDI2C_Katakana_h