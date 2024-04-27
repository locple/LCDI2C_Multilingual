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
const uint8_t  GenericROMLetterNum = 4;
ROMCharacterType GenericROMLetters [GenericROMLetterNum] = {
  {0x00A5, 0x5C},   // ¥ Yen
  {0x2192, 0x7E},   // → right arrow
  {0x2190, 0x7F},   // ← left arrow
  /*{0x03B1, 0xE0},   // α alpha	//// Removed for saving Arduino RAM
  {0x03B2, 0xE2},   // β beta
  {0x03B5, 0xE3},   // ε epsilon
  {0x03BC, 0xE4},   // μ mu
  {0x03B4, 0xE5},   // δ delta
  {0x03C1, 0xE6},   // ρ rho
  {0x221A, 0xE8},   // √ sqrt
  {0x03B8, 0xF2},   // θ theta
  {0x221E, 0xF3},   // ∞ infinity
  {0x03A9, 0xF4},   // Ω omega (capital)
  {0x03A3, 0xF6},   // Σ sigma (capital)
  {0x03C0, 0xF7},*/   // π pi
  {0x00F7, 0xFD}    // ÷ Division
};

#endif // ROM_Generic_h