/*
  ** CustomizedLanguage class **
  Base class for adding customizied characters in UTF8 (NFC normalized)
  encoding.

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Custom_h
#define LCDI2C_Custom_h

#include <stdint.h>

#include "LCDI2C_Types.h"
#include "LCDI2C_UTF8.h"
#include <Arduino.h>

class CustomizedLanguage {
public:
  CustomizedLanguage(LCDI2C_UTF8 *lcd) : screen(lcd) {}

  uint8_t getCharacter(uint16_t code, uint8_t col, uint8_t row);

  // Dismiss all custom letters currently used in CGRAM
  void clearLetters();

protected:
  // Tranpose charmap "src" 5x8 to charmap "dst" 8x5
  void tranpose(const uint8_t src[], uint8_t dst[]);

  // Create new letter having index "idx" ferencing to "CustomizedLetters"
  uint8_t createLetter(uint8_t idx);

  // Return index of letter "c" referencing to "CustomizedLetters"
  uint8_t getLetterIndex(uint16_t c);

  // Check the existing of a letter index in CGRAM
  uint8_t getCGRAMLetterOrder(uint8_t idx);

  // Get fallback form of a letter
  virtual uint8_t getAlternativeLetter(uint16_t c) { return uint8_t(c); }

  uint8_t getLongestWordLength() { return longestWordLength; }

  uint8_t CustomLetterNum;            // Size of customized letter map
  const CustomCharacterType *CustomLetters; // Link to customized letter map
  LCDI2C_UTF8 *screen;
  uint8_t cgramLetters[CGRAM_SIZE] =
      { // Indexes of Vietnamese letters in use in CGRAM. NOTFOUND: unallocated
          NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND,
          NOTFOUND, NOTFOUND, NOTFOUND}; // Change this with CGRAM_SIZE
  uint8_t longestWordLength;
  uint8_t cgramLettersNum = 0; // Number of elements of cgramLetters
};                             // CustomizedLanguage

#endif // LCDI2C_Custom_h