/*
  ** Russian ROM data **
  Russian code points to equivalent characters in Russian ROM

  ** LCD chips using Russian character ROM **
  - Wuxi AIP31066W3
  - Surenoo SLC Russian series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef ROM_Russian_h
#define ROM_Russian_h

#include "../base/LCDI2C_Types.h"
#include <Arduino.h>

// List of Russian letters and some symbols built in the ROM
const uint8_t RussianROMLetterNum = 74;
extern PROGMEM const ROMCharacterType RussianROMLetters[RussianROMLetterNum];

#endif // ROM_Russian_h