/* SPDX-License-Identifier: MIT */

#include "../LCDI2C_Katakana.h"

uint8_t LCDI2C_Katakana::nextWordLength(const byte text[], uint16_t start,
                                        uint16_t code) {
  // Check for Katakana words with diacritic
  for (uint8_t idx = 0; idx < KanaDiacriticCharacterNum; idx++)
    if (KanaDiacriticCharacters[idx].code == code)
      return 2;

  // Check for other Katakana words
  if (code >= 0x30A1 && code <= 0x30F3)
    return 1;

  // Check for English word
  return LCDI2C_UTF8::nextWordLength(text, start, code);
}

uint16_t LCDI2C_Katakana::getCharacter(uint16_t code) {
  uint8_t base, diacritic = 0;

  // Look for katakana
  if (code >= 0x30A0 && code < 0x3100) {
    // Separate one Katakana character with diacritic into base character and
    // diacritic character
    for (uint8_t idx = 0; idx < KanaDiacriticCharacterNum; idx++) {
      if (KanaDiacriticCharacters[idx].code == code) {
        code = KanaDiacriticCharacters[idx].base;
        diacritic = KanaDiacriticCharacters[idx].diacritic;
      }
    }
  }

  // Look for Latin Fullwidth character
  if (code >= 0xFF01 && code <= 0xFF5D)
    return code - 0xFEE0; // Convert Latin Fullwidth to Latin ASCII

  base = LCDI2C_UTF8::getCharacter(code);

  if (diacritic == 0)
    return (uint16_t)base;
  else
    return uint16_t(base) | (diacritic << 8);
}
