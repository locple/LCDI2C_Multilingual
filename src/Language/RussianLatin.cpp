/* SPDX-License-Identifier: MIT */

#include "../LCDI2C_RussianLatin.h"

uint16_t LCDI2C_RussianLatin::getCharacter(uint16_t code) {
  uint8_t ord;

  if (code < 0x7E || // ASCII character?
      (code <= maxExcludedChar &&
       code >= minExcludedChar)) { // Exclude a selected range in a LCD's ROM
                                   // character set
    if (code > 0x1F)
      return (uint16_t)code; // Printable
    else
      return (uint16_t)'*'; // Non-printable
  }

  // Look for Unicode character in CGRAM (search in CGRAM first)
  if (customizedLanguage != NULL) {
    ord = customizedLanguage->getCharacter(code, cursorColumn, cursorRow);
    if (ord != NOTFOUND)    // Character is in CGRAM?
      return (uint16_t)ord; // Return customized character
  }

  // Look for Unicode Latin letter in ROM
  if (code >= 0xA1 &&
      code <= 0xFF) // Latin characters have the same code in ROM
    return code;    // so simply return it

  // Look for Unicode Russian letter in ROM
  ord = getROMCharacter(code);
  if (ord != NOTFOUND)    // Character is in ROM?
    return (uint16_t)ord; // Return ROM character

  return (uint16_t)'*'; // Unknown character
}
