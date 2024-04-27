/*
  ** RussianLatin ROM data **
  Capital Russian & Latin code points to equivalent characters in Russian Latin ROM

  ** LCD chips using Russian Latin character ROM (capital only) **
  - Hitachi HD44780UA02

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef ROM_RussianLatin_h
#define ROM_RussianLatin_h

#include "../base/LCDI2C_Types.h"

const uint8_t  RussianLatinROMLetterNum = 33;
// List of capital Russian, Latin, Greek letters and some symbols built in the ROM
ROMCharacterType RussianLatinROMLetters [RussianLatinROMLetterNum] = {
  /*{0x21B5, 0x17},   // ↵ enter	//// Removed for saving Arduino RAM
  {0x2191, 0x18},   // ↑ up arrow
  {0x2193, 0x19},   // ↓ down arrow
  {0x2192, 0x1A},   // → right arrow
  {0x2190, 0x1B},   // ← left arrow
  {0x2264, 0x1C},   // ≤ LTE
  {0x2265, 0x1D},   // ≥ GTE
  {0x221E, 0x9C},   // ∞ infinity
  {0x03A3, 0x94},   // Σ sigma (capital)
  {0x03A9, 0x9A},   // Ω omega (capital)
  {0x03B1, 0x90},   // α alpha
  {0x03B2, 0xDF},   // β beta
  {0x03B4, 0x9B},   // δ delta
  {0x03B5, 0x9E},   // ε epsilon
  {0x03B8, 0x99},   // θ theta
  {0x03BC, 0xB5},   // μ mu
  {0x03C0, 0x93},   // π pi
  {0x03C3, 0x95},   // σ sigma
  {0x03C9, 0xB8},*/   // ω omega
  {0x0401, 0xCB},   // Ё
  {0x0410, 0x41},   // А
  {0x0411, 0x80},   // Б
  {0x0412, 0x42},   // В
  {0x0413, 0x92},   // Г
  {0x0414, 0x81},   // Д
  {0x0415, 0x45},   // Е
  {0x0416, 0x82},   // Ж
  {0x0417, 0x83},   // З
  {0x0418, 0x84},   // И
  {0x0419, 0x85},   // Й
  {0x041A, 0x4B},   // К
  {0x041B, 0x86},   // Л
  {0x041C, 0x4D},   // М
  {0x041D, 0x48},   // Н
  {0x041E, 0x4F},   // О
  {0x041F, 0x87},   // П
  {0x0420, 0x50},   // Р
  {0x0421, 0x43},   // С
  {0x0422, 0x54},   // Т
  {0x0423, 0x88},   // У
  {0x0424, 0xD8},   // Ф
  {0x0425, 0x58},   // Х
  {0x0426, 0x89},   // Ц
  {0x0427, 0x8A},   // Ч
  {0x0428, 0x8B},   // Ш
  {0x0429, 0x8C},   // Щ
  {0x042A, 0x8D},   // Ъ
  {0x042B, 0x8E},   // Ы
  {0x042C, 0x62},   // Ь (b)
  {0x042D, 0x8F},   // Э
  {0x042E, 0xAC},   // Ю
  {0x042F, 0xAD},   // Я
};

#endif  // ROM_RussianLatin_h