/*
  ** CustomizedLanguage class **
  Base class for adding customizied characters in UTF8 (NFC normalized) encoding.

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Custom_h
#define LCDI2C_Custom_h

#include "LCDI2C_Types.h"
#include "LCDI2C_UTF8.h"

class CustomizedLanguage {
public:
  CustomizedLanguage(LCDI2C_UTF8* lcd) : screen(lcd) {}

  uint8_t getCharacter(uint16_t code, uint8_t col, uint8_t row) {
    uint8_t idx, ord;

	idx = getLetterIndex(code);
    if (idx == NOTFOUND) return NOTFOUND;

    // Declared unicode letter
    ord = getCGRAMLetterOrder(idx);
    if (ord == NOTFOUND) {                  // None exists in CGRAM
      if (cgramLettersNum < CGRAM_SIZE) {   // Run out of CGRAM?
        ord = createLetter(idx);            // No -> Create a new letter in CGRAM
        // Fix wrong cursor moving when creating custom character
        screen->setCursor(col, row);
      } else                                // Yes -> Replace with alternative letter
        ord = (uint8_t) getAlternativeLetter(CustomLetters[idx].code);
    }
    return ord;
  }

  // Dismiss all custom letters currently used in CGRAM
  void clearLetters() {
    cgramLettersNum = 0;
    memset(cgramLetters, NOTFOUND, CGRAM_SIZE);
  }

protected:
  // Tranpose charmap "src" 5x8 to charmap "dst" 8x5
  void tranpose(const uint8_t src[], uint8_t dst[]) {
    uint8_t element, mask = 0b10000000;
    memset(dst, 0, 8);
    for (uint8_t i = 0; i < 8; i++) {
      for (uint8_t j = 0; j < 5; j++) {
    	  element = ((src[j] & mask) << i) >> j + 3;
   		  dst[i] |= element;
      }
  	  mask >>= 1;
    }
  }

  // Create new letter having index "idx" ferencing to "CustomizedLetters"
  uint8_t createLetter(uint8_t idx) {
    uint8_t placeOrd = cgramLettersNum++;

    // Create new coresponding letter in CGRAM
    tranpose(CustomLetters[idx].mapT, charmap);
    screen->createChar(placeOrd, charmap);
    cgramLetters[placeOrd] = idx;

    return placeOrd;
  }

  // Return index of letter "c" referencing to "CustomizedLetters"
  uint8_t getLetterIndex(uint16_t c) {
    for (int idx = 0; idx < CustomLetterNum; idx++)
      if (CustomLetters[idx].code == c) return idx;
    return NOTFOUND;
  }

  // Check the existing of a letter index in CGRAM
  uint8_t getCGRAMLetterOrder(uint8_t idx) {
    for (uint8_t ord = 0; ord < cgramLettersNum; ord++)
      if (cgramLetters[ord] == idx) return ord;
    return NOTFOUND;
  }

  virtual  uint8_t    getAlternativeLetter(uint16_t c) {  // Each language may implements its own getAlternativeLetter()
    return uint8_t(c);   // Default implementation
  }

  uint8_t   getLongestWordLength() { return longestWordLength; }

  uint8_t   CustomLetterNum;              // Size of customized letter map
  CustomCharacterType* CustomLetters;     // Link to customized letter map
  LCDI2C_UTF8* screen;
  uint8_t   cgramLetters[CGRAM_SIZE] = {  // Indexes of Vietnamese letters in use in CGRAM. NOTFOUND: unallocated
            NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND, NOTFOUND};  // Change this with CGRAM_SIZE
  uint8_t   charmap[8];                   // Template used by createChar()
  uint8_t   longestWordLength; 
  uint8_t   cgramLettersNum = 0;          // Number of elements of cgramLetters
}; // CustomizedLanguage

#endif  // LCDI2C_Custom_h