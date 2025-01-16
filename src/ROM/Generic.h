/*
  ** Generic ROM data **
  Greek symbol code points to equivalent characters in regular ROM

  ** LCD chips using regular ROM (Japanese ROM) **
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

#ifndef ROM_Generic_h
#define ROM_Generic_h

#include "../base/LCDI2C_Types.h"

// List of some symbols built in the ROM
const uint8_t GenericROMLetterNum = 4;
extern ROMCharacterType GenericROMLetters[GenericROMLetterNum];

#endif // ROM_Generic_h