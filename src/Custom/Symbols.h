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

#include "../base/LCDI2C_Custom.h"
#include "../base/LCDI2C_Types.h"
#include <Arduino.h>

const uint8_t SymbolCustomLetterNum = 2;
// List of custom Unicode characters
extern PROGMEM const CustomCharacterType
    SymbolCustomLetters[SymbolCustomLetterNum];

class CustomizedSymbols : public CustomizedLanguage {
public:
  CustomizedSymbols(LCDI2C_UTF8 *lcd) : CustomizedLanguage(lcd) {
    CustomLetterNum = SymbolCustomLetterNum;
    CustomLetters = SymbolCustomLetters;
  }

protected:
  uint8_t getAlternativeLetter(uint16_t c) override;
};

#endif // Custom_Symbols_h