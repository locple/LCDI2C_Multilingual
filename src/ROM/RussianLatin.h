/*
  ** RussianLatin ROM data **
  Capital Russian & Latin code points to equivalent characters in Russian Latin
  ROM

  ** LCD chips using Russian Latin character ROM (capital only) **
  - Hitachi HD44780UA02

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef ROM_RussianLatin_h
#define ROM_RussianLatin_h

#include "../base/LCDI2C_Types.h"
#include <Arduino.h>

const uint8_t RussianLatinROMLetterNum = 52;
// List of capital Russian, Latin, Greek letters and some symbols built in the
// ROM
extern PROGMEM const ROMCharacterType RussianLatinROMLetters[RussianLatinROMLetterNum];

#endif // ROM_RussianLatin_h