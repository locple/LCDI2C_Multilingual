/*
  ** Vietnamese customization data **
  Vietnamese code points to customized character maps

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Vietnamese tones & diacritics for 5x8 Latin letters **
  (C) 2023 Loc P. Le

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef Custom_Vietnamese_h
#define Custom_Vietnamese_h

#include "../base/LCDI2C_Custom.h"
#include "../base/LCDI2C_Types.h"
#include <Arduino.h>

// List of Vietnamese letters with diacritics and custom Unicode characters
const uint8_t VietnameseCustomLetterNum = 136;
extern PROGMEM const CustomCharacterType
    VietnameseCustomLetters[VietnameseCustomLetterNum];

class CustomizedVietnamese : public CustomizedLanguage {
public:
  CustomizedVietnamese(LCDI2C_UTF8 *lcd) : CustomizedLanguage(lcd) {
    CustomLetterNum = VietnameseCustomLetterNum;
    CustomLetters = VietnameseCustomLetters;
  }

protected:
  uint8_t getAlternativeLetter(uint16_t c) override;
};

#endif // Custom_Vietnamese_h