/*
  ** Latin ROM data **
  Latin-1 code points to equivalent characters in European ROM

  ** LCD chips using Latin-1 character ROM **
  - Wuxi AIP31066W2
  - Sitronix ST7066-0B
  - Surenoo SLC European series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef ROM_Latin_h
#define ROM_Latin_h

#include "../base/LCDI2C_Types.h"

// List of Latin-1 letters and some symbols built in the ROM
const uint8_t LatinROMLetterNum = 54;
extern ROMCharacterType LatinROMLetters[LatinROMLetterNum];

#endif // ROM_Latin_h