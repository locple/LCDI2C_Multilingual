/*
  ** LCDI2C_RussianLatin class **
  For printing Russian, Latin-1 UTF-8 (NFC normalized)
  capital-only strings and Greek symbols to I2C LCD.

  ** Compatible LCDs **
  Only used for LCD chips with Russian & Latin character ROM (capital only):
  - Hitachi HD44780UA02

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_RussianLatin_h
#define LCDI2C_RussianLatin_h

#include "ROM/RussianLatin.h"
#include "base/LCDI2C_UTF8.h"
#include "base/LCDI2C_Custom.h"

class LCDI2C_RussianLatin : public LCDI2C_UTF8 {
public:
  LCDI2C_RussianLatin(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C_UTF8(lcd_addr, lcd_cols, lcd_rows) {
    ROMLetterNum = RussianLatinROMLetterNum;
	ROMLetters = RussianLatinROMLetters;
    setLongestWordLength(10);
  }

protected:
  uint16_t getCharacter(uint16_t code) override {
    uint8_t ord;

    if (code < 0x7E ||                          // ASCII character?
       (code <= maxExcludedChar && code >= minExcludedChar))	// Exclude a selected range in a LCD's ROM character set
      if (code > 0x1F)
        return (uint16_t) code;                 // Printable
      else
        return (uint16_t) '*';                  // Non-printable

    // Look for Unicode character in CGRAM (search in CGRAM first)
    if (customizedLanguage != NULL) {
      ord = customizedLanguage->getCharacter(code, cursorColumn, cursorRow);
      if (ord != NOTFOUND)                      // Character is in CGRAM?
        return (uint16_t) ord;                  // Return customized character
    }

    // Look for Unicode Latin letter in ROM
	if (code >= 0xA1 && code <= 0xFF)           // Latin characters have the same code in ROM
        return code;		  	                // so simply return it

    // Look for Unicode Russian letter in ROM
    ord = getROMCharacter(code);
    if (ord != NOTFOUND)                        // Character is in ROM?
      return (uint16_t) ord;                    // Return ROM character

    return (uint16_t) '*';                      // Unknown character
  }
};

typedef LCDI2C_RussianLatin LiquidCrystal_I2C_RussianLatin;

#endif  // LCDI2C_RussianLatin_h