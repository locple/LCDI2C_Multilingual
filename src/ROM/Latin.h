/*
  ** Latin ROM data **
  Latin-1 code points to equivalent characters in European ROM

  ** LCD chips using Latin-1 character ROM **
  - Wuxi AIP31066W2
  - Sitronix ST7066-0B
  - Surenoo SLC European series

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef ROM_Latin_h
#define ROM_Latin_h

#include "../base/LCDI2C_Types.h"

// List of Latin-1 letters and some symbols built in the ROM
const uint8_t LatinROMLetterNum = 54;
ROMCharacterType LatinROMLetters [LatinROMLetterNum] = {
  {0x00B1, 0x10},   // ± Plus-Minus
  {0x2248, 0x1D},   // ≈ almost equal
  {0x00B2, 0x1E},   // ² power of 2
  {0x00B3, 0x1F},   // ³ power of 3
  {0x00A2, 0xA4},   // ¢ Cent
  {0x00A3, 0xA5},   // £ Pound
  {0x00A5, 0xA6},   // ¥ Yen
  {0x00C7, 0x80},	// Ç C with cedilla
  {0x00FC, 0x81},	// ü u with diaeresis
  {0x00E9, 0x82},	// é e with acute
  {0x00E2, 0x83},	// â a with circumflex
  {0x00E4, 0x84},	// ä a with diaeresis
  {0x00E0, 0x85},	// à a with grave
  {0x00E5, 0x86},	// å a with ring above
  {0x00E7, 0x87},	// ç c with cedilla
  {0x00EA, 0x88},	// ê e with circumflex
  {0x00EB, 0x89},	// ë e with diaeresis
  {0x00E8, 0x8A},	// è e with grave
  {0x00CF, 0x8B},	// Ï I with diaeresis
  {0x00EE, 0x8C},	// î i with circumflex
  {0x00EC, 0x8D},	// ì i with grave
  {0x00C4, 0x8E},	// Ä A with diaeresis
  {0x00C5, 0x8F},	// Å A with ring above
  {0x00C9, 0x90},	// É E with acute
  {0x00E6, 0x91},	// æ
  {0x00C6, 0x92},	// Æ
  {0x00F4, 0x93},	// ô o with circumflex
  {0x00F6, 0x94},	// ö o with diaeresis
  {0x00F2, 0x95},	// ò o with grave
  {0x00FB, 0x96},	// û u with circumflex
  {0x00F9, 0x97},	// ù u with grave
  {0x00FF, 0x98},	// ÿ y with diaeresis
  {0x00D6, 0x99},	// Ö O with diaeresis
  {0x00DC, 0x9A},	// Ü U with diaeresis
  {0x00F1, 0x9B},	// ñ n with tilde
  {0x00D1, 0x9C},	// Ñ N with tilde
  {0x00AA, 0x9D},	// ª feminine ordinal indicator
  {0x00BA, 0x9E},	// º masculine ordinal indicator
  {0x00BF, 0x9F},	// ¿ inverted question mark
  {0x00E1, 0xA0},	// á a with acute
  {0x00ED, 0xA1},	// í i with acute
  {0x00F3, 0xA2},	// ó o with acute
  {0x00FA, 0xA3},	// ú u with acute
  {0x00A1, 0xA9},	// ¡ inverted exclamation mark
  {0x00C3, 0xAA},	// Ã A with tilde
  {0x00E3, 0xAB},	// ã a with tilde
  {0x00D5, 0xAC},	// Õ O with tilde
  {0x00F5, 0xAD},	// õ o with tilde
  {0x00D8, 0xAE},	// Ø O with stroke
  {0x00F8, 0xAF},	// ø o with stroke
  {0x00B7, 0xB0},	// · middle dot
  {0x00A8, 0xB1},	// ¨ diaeresis
  {0x00B0, 0xB2},	// ° degree sign
  //{0x0060, 0xB3},	// ` grave accent (use ASCII grave instead)
  {0x00B4, 0xB4}	// ´ acute accent
  /*{0x00D7, 0xB7},   // × Multiplication	//// Removed for saving Arduino RAM
  {0x00F7, 0xB8},   // ÷ Division
  {0x2264, 0xB9},   // ≤ LTE
  {0x2265, 0xBA},   // ≥ GTE
  {0x221A, 0xBE},   // √ sqrt
  {0x221E, 0xC2},   // ∞ infinity
  {0x21B5, 0xC4},   // ↵ enter
  {0x2191, 0xC5},   // ↑ up arrow
  {0x2193, 0xC6},   // ↓ down arrow
  {0x2192, 0xC7},   // → right arrow
  {0x2190, 0xC8},   // ← left arrow
  {0x03A3, 0xDA},   // Σ sigma (capital)
  {0x03A9, 0xDE},   // Ω omega (capital)
  {0x03B1, 0xDF},   // α alpha
  {0x03B2, 0xE0},   // β beta
  {0x03B3, 0xE1},   // γ gamma
  {0x03B4, 0xE2},   // δ delta
  {0x03B5, 0xE3},   // ε epsilon
  {0x03B7, 0xE5},   // η eta
  {0x03B8, 0xE6},   // θ theta
  {0x03BC, 0xEA},   // μ mu
  {0x03C0, 0xED},   // π pi
  {0x03C1, 0xEE},   // ρ rho
  {0x03C3, 0xEF},   // σ sigma
  {0x03C8, 0xF3},   // ψ psi
  {0x03C9, 0xF4}*/    // ω omega
};

#endif  // ROM_Latin_h