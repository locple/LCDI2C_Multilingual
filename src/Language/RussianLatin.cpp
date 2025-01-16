/* SPDX-License-Identifier: MIT */

#include "../LCDI2C_RussianLatin.h"

uint16_t LCDI2C_RussianLatin::getCharacter(uint16_t code) {
  // Look for Unicode Latin letter in ROM
  if (code >= 0xA1 &&
      code <= 0xFF) // Latin characters have the same code in ROM
    return code;    // so simply return it
    
  return LCDI2C_UTF8::getCharacter(code);
}
