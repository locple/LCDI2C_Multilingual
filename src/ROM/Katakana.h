/*
  ** Katakana ROM data **
  Japanese Katakana code points to equivalent characters in Japanese ROM

  ** LCD chips using Japanese character ROM **
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

#ifndef ROM_Katakana_h
#define ROM_Katakana_h

#include "../base/LCDI2C_Types.h"
#include <Arduino.h>

// Struct for Katakana unicode character with diacritic (dakuten or handakuten)
typedef struct {
  uint16_t const code;     // Character code point
  uint16_t const base;     // Character code point
  uint8_t const diacritic; // Dakuten or Handakuten
} KanaDiacriticCharacterType;

// Array for mapping Kana character with diacritic to base Kana character +
// diacritic
const uint8_t KanaDiacriticCharacterNum = 31;
extern PROGMEM const KanaDiacriticCharacterType
    KanaDiacriticCharacters[KanaDiacriticCharacterNum];

// List of Katakana characters, punctuations, some symbols built in the ROM
const uint8_t KanaROMLetterNum = 87;
extern PROGMEM const ROMCharacterType KanaROMLetters[KanaROMLetterNum];

#endif // ROM_Katakana_h