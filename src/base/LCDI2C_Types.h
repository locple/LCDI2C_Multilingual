/*
  ** LCDI2C_Types **
  Defines types and constants used in LCDI2C program

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_Types_h
#define LCDI2C_Types_h

#define CGRAM_SIZE 8  // Max number of customized characters in CGRAM
#define NOTFOUND 255  // Default error code (so ROM last code FF must reserved)

// Struct for mapping Unicode character to character available in LCD's ROM
typedef struct {
  uint16_t const code;     // Unicode code point (2 bytes) of the character
  uint8_t  const link;     // ROM character order
} ROMCharacterType;

// Struct for a customized unicode character
typedef struct {
  uint16_t const code;     // Unicode code point (2 bytes) of the character
  uint8_t  const mapT[5];  // Tranposed bitmap matrix (5x8) to render (use 5x8 instead of 8x8 for saving RAM)
} CustomCharacterType;

#endif // LCDI2C_Types_h