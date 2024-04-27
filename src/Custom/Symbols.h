/*
  ** Symbols customization data **
  Symbol code points to customized character maps

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef Custom_Symbols_h
#define Custom_Symbols_h

#include "../base/LCDI2C_Types.h"
#include "../base/LCDI2C_Custom.h"

const uint8_t SymbolCustomLetterNum = 2;
// List of custom Unicode characters
CustomCharacterType SymbolCustomLetters [SymbolCustomLetterNum] = {
  {0x00B0, {0b00000000,0b01100000,0b10010000,0b10010000,0b01100000}},	// ° (degree symbol)
  {0x20AC, {0b00101000,0b01111100,0b10101010,0b10101010,0b10000010}}	// € (Euro sign)
};

class CustomizedSymbols : public CustomizedLanguage {
public:
  CustomizedSymbols(LCDI2C_UTF8* lcd) : CustomizedLanguage(lcd) {
    CustomLetterNum = SymbolCustomLetterNum;
    CustomLetters = SymbolCustomLetters;
  }

protected:
  uint8_t getAlternativeLetter(uint16_t c) override {
    switch (c) {
      case 0x00B0:  // degree symbol
        return 0xDF;
      case 0x20AC:  // Euro sign
        return 0x45;
      default:  // Input code point is not symbols!
        return '*';
    }
  }
};

#endif  // Custom_Symbols_h