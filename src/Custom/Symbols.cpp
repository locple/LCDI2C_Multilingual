/* SPDX-License-Identifier: MIT */

#include "Symbols.h"

PROGMEM const CustomCharacterType SymbolCustomLetters[SymbolCustomLetterNum] = {
    {0x00B0,
     {0b00000000, 0b01100000, 0b10010000, 0b10010000,
      0b01100000}}, // ° (degreeF symbol)
    {0x20AC,
     {0b00101000, 0b01111100, 0b10101010, 0b10101010,
      0b10000010}} // € (Euro sign)
};

uint8_t getAlternativeLetter(uint16_t c) {
  switch (c) {
  case 0x00B0: // degree symbol
    return 0xDF;
  case 0x20AC: // Euro sign
    return 0x45;
  default: // Input code point is not symbols!
    return '*';
  }
}
