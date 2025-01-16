/* SPDX-License-Identifier: MIT */
#include "LCDI2C_Custom.h"

#include "LCDI2C_Types.h"
#include "LCDI2C_UTF8.h"
#include <stdlib.h>
#include <stdint.h>

uint8_t CustomizedLanguage::getCharacter(uint16_t code, uint8_t col,
                                         uint8_t row) {
  uint8_t idx, ord;

  idx = getLetterIndex(code);
  if (idx == NOTFOUND)
    return NOTFOUND;

  // Declared unicode letter
  ord = getCGRAMLetterOrder(idx);
  if (ord == NOTFOUND) {                // None exists in CGRAM
    if (cgramLettersNum < CGRAM_SIZE) { // Run out of CGRAM?
      ord = createLetter(idx);          // No -> Create a new letter in CGRAM
      // Fix wrong cursor moving when creating custom character
      screen->setCursor(col, row);
    } else // Yes -> Replace with alternative letter
      ord = (uint8_t)getAlternativeLetter(code);
  }
  return ord;
}

void CustomizedLanguage::clearLetters() {
  cgramLettersNum = 0;
  memset(cgramLetters, NOTFOUND, CGRAM_SIZE);
}

void CustomizedLanguage::tranpose(const uint8_t src[], uint8_t dst[]) {
  uint8_t element, mask = 0b10000000;
  memset(dst, 0, 8);
  for (uint8_t i = 0; i < 8; i++) {
    for (uint8_t j = 0; j < 5; j++) {
      element = ((src[j] & mask) << i) >> (j + 3);
      dst[i] |= element;
    }
    mask >>= 1;
  }
}

uint8_t CustomizedLanguage::createLetter(uint8_t idx) {
  uint8_t bitmap[8];
  uint8_t placeOrd = cgramLettersNum++;

  // load character bitmap
  uint8_t compressed[5];
  memcpy_P(compressed, &(CustomLetters[idx].mapT), 5);

  // Create new coresponding letter in CGRAM
  tranpose(compressed, bitmap);
  screen->createChar(placeOrd, bitmap);
  cgramLetters[placeOrd] = idx;

  return placeOrd;
}

int cmpCustomLetter(const void *keyp, const void *entryp) {
  uint16_t code = *(uint16_t *)keyp;
  const CustomCharacterType *entry = (const CustomCharacterType *)entryp;
  uint16_t entryCode = pgm_read_word(&(entry->code));
  return (code > entryCode) - (code < entryCode);
}

uint8_t CustomizedLanguage::getLetterIndex(uint16_t c) {
  const CustomCharacterType *entry = (const CustomCharacterType *)bsearch(
      &c, CustomLetters, CustomLetterNum, sizeof(CustomCharacterType),
      &cmpCustomLetter);

  if (entry)
    return entry - CustomLetters;
  else
    return NOTFOUND;
}

uint8_t CustomizedLanguage::getCGRAMLetterOrder(uint8_t idx) {
  for (uint8_t ord = 0; ord < cgramLettersNum; ord++)
    if (cgramLetters[ord] == idx)
      return ord;
  return NOTFOUND;
}
