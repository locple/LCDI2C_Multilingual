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

const uint8_t Dakuten = 0xDE;
const uint8_t Handakuten = 0xDF;

// Struct for Katakana unicode character with diacritic (dakuten or handakuten)
typedef struct {
  uint16_t const code;			// Character code point
  uint16_t const base;			// Character code point
  uint8_t const diacritic;		// Dakuten or Handakuten
} KanaDiacriticCharacterType;

// Array for mapping Kana character with diacritic to base Kana character + diacritic
const uint8_t KanaDiacriticCharacterNum = 29;
KanaDiacriticCharacterType KanaDiacriticCharacters [KanaDiacriticCharacterNum] = {
  {0x30AC, 0x30AB, Dakuten},	// ガ Ga
  {0x30AE, 0x30AD, Dakuten},	// ギ Gi
  {0x30B0, 0x30AF, Dakuten},	// グ Gu
  {0x30B2, 0x30B1, Dakuten},	// ゲ Ge
  {0x30B4, 0x30B3, Dakuten},	// ゴ Go
  {0x30B6, 0x30B5, Dakuten},	// ザ Za
  {0x30B8, 0x30B7, Dakuten},	// ジ Ji
  {0x30BA, 0x30B9, Dakuten},	// ズ Zu
  {0x30BC, 0x30BB, Dakuten},	// ゼ Ze
  {0x30BE, 0x30BD, Dakuten},	// ゾ Zo
  {0x30C0, 0x30BF, Dakuten},	// ダ Da
  {0x30C2, 0x30C1, Dakuten},	// ヂ Ji
  {0x30C5, 0x30C4, Dakuten},	// ヅ Zu
  {0x30C7, 0x30C6, Dakuten},	// デ De
  {0x30C9, 0x30C8, Dakuten},	// ド Do
  {0x30D0, 0x30CF, Dakuten},	// バ Ba
  {0x30D1, 0x30CF, Handakuten},	// パ Pa
  {0x30D3, 0x30D2, Dakuten},	// ビ Bi
  {0x30D4, 0x30D2, Handakuten},	// ピ Pi
  {0x30D6, 0x30D5, Dakuten},	// ブ Bu
  {0x30D7, 0x30D5, Handakuten},	// プ Pu
  {0x30D9, 0x30D8, Dakuten},	// ベ Be
  {0x30DA, 0x30D8, Handakuten},	// ペ Pe
  {0x30DC, 0x30DB, Dakuten},	// ボ Bo
  {0x30DD, 0x30DB, Handakuten},	// ポ Po
  {0x30F4, 0x30A6, Dakuten},	// ヴ
  {0x30F7, 0x30EF, Dakuten},	// ヷ
  //{0x30F8, 0x30F0, Dakuten},	// ヸ
  //{0x30F9, 0x30F1, Dakuten},	// ヹ
  {0x30FA, 0x30F2, Dakuten},	// ヺ
  {0x30FE, 0x30FD, Dakuten}		// ヾ
};

// List of Katakana characters, punctuations, some symbols built in the ROM
const uint8_t  KanaROMLetterNum = 73;
ROMCharacterType KanaROMLetters [KanaROMLetterNum] = {
  {0x3000, 0xA0},   //   full-width space
  {0x3002, 0xA1},	// 。 period (full stop)
  {0x300C, 0xA2},   // 「 single quotation (left corner bracket)
  {0xFF62, 0xA2},   // 「 single quotation (left corner bracket)
  {0x300E, 0xA2},   // 『 double quotation (left white corner bracket)
  {0x300D, 0xA3},   // 」 single quotation (right corner bracket)
  {0xFF63, 0xA3},   // 」 single quotation (right corner bracket)
  {0x300F, 0xA3},   // 』 double quotation (right white corner bracket)
  {0x3001, 0xA4},   // 、 comma
  {0xFF0C, 0xA4},   // ， comma
  {0x30FB, 0xA5},   // ・ interpunct (middle dot)
  {0x30A0, 0x3D},   // ゠ doulle hyphen
  {0x301D, 0x22},   // 〝 reverse double prime quotation
  {0x301E, 0x22},   // 〞 double prime quotation
  {0x30F2, 0xA6},   // ヲ Wo
  {0x30A1, 0xA7},   // ァ a
  {0x30A3, 0xA8},   // ィ i
  {0x30A5, 0xA9},   // ゥ u
  {0x30A7, 0xAA},   // ェ e
  {0x30A9, 0xAB},   // ォ o
  {0x30E3, 0xAC},   // ャ ya
  {0x30E5, 0xAD},   // ュ yu
  {0x30E7, 0xAE},   // ョ yo
  {0x30C3, 0xAF},   // ッ tu
  {0x30FC, 0xB0},   // ー prolonged sound mark
  {0x30A2, 0xB1},   // ア A
  {0x30A4, 0xB2},   // イ I
  {0x30A6, 0xB3},   // ウ U
  {0x30A8, 0xB4},   // エ E
  {0x30AA, 0xB5},   // オ O
  {0x30AB, 0xB6},   // カ Ka
  {0x30AD, 0xB7},   // キ Ki
  {0x30AF, 0xB8},   // ク Ku
  {0x30B1, 0xB9},   // ケ Ke
  {0x30B3, 0xBA},   // コ Ko
  {0x30B5, 0xBB},   // サ Sa
  {0x30B7, 0xBC},   // シ Si
  {0x30B9, 0xBD},   // ス Su
  {0x30BB, 0xBE},   // セ Se
  {0x30BD, 0xBF},   // ソ So
  {0x30BF, 0xC0},   // タ Ta
  {0x30C1, 0xC1},   // チ Ti
  {0x30C4, 0xC2},   // ツ Tu
  {0x30C6, 0xC3},   // テ Te
  {0x30C8, 0xC4},   // ト To
  {0x30CA, 0xC5},   // ナ Na
  {0x30CB, 0xC6},   // ニ Ni
  {0x30CC, 0xC7},   // ヌ Nu
  {0x30CD, 0xC8},   // ネ Ne
  {0x30CE, 0xC9},   // ノ No
  {0x30CF, 0xCA},   // ハ Ha
  {0x30D2, 0xCB},   // ヒ Hi
  {0x30D5, 0xCC},   // フ Hu
  {0x30D8, 0xCD},   // ヘ He
  {0x30DB, 0xCE},   // ホ Ho
  {0x30DE, 0xCF},   // マ Ma
  {0x30DF, 0xD0},   // ミ Mi
  {0x30E0, 0xD1},   // ム Mu
  {0x30E1, 0xD2},   // メ Me
  {0x30E2, 0xD3},   // モ Mo
  {0x30E4, 0xD4},   // ヤ Ya
  {0x30E6, 0xD5},   // ユ Yu
  {0x30E8, 0xD6},   // ヨ Yo
  {0x30E9, 0xD7},   // ラ Ra
  {0x30EA, 0xD8},   // リ Ri
  {0x30EB, 0xD9},   // ル Ru
  {0x30EC, 0xDA},   // レ Re
  {0x30ED, 0xDB},   // ロ Ro
  {0x30EF, 0xDC},   // ワ Wa
  {0x30F3, 0xDD},   // ン N
  {0x00A5, 0x5C},   // ¥ Yen
  {0x00A2, 0xEC},   // ¢ Cent
  {0x5186, 0xFC}    // 円 Yen (in Kanji)
  /*{0x2192, 0x7E},   // → right arrow	//// Removed for saving Arduino RAM
  {0x2190, 0x7F},   // ← left arrow
  {0x03B1, 0xE0},   // α alpha
  {0x03B2, 0xE2},   // β beta
  {0x03B5, 0xE3},   // ε epsilon
  {0x03BC, 0xE4},   // μ mu
  {0x03B4, 0xE5},   // δ delta
  {0x03C1, 0xE6},   // ρ rho
  {0x221A, 0xE8},   // √ sqrt
  {0x03B8, 0xF2},   // θ theta
  {0x221E, 0xF3},   // ∞ infinity
  {0x03A9, 0xF4},   // Ω omega (capital)
  {0x03A3, 0xF6},   // Σ sigma (capital)
  {0x03C0, 0xF7},   // π pi
  {0x00F7, 0xFD}*/    // ÷ Division
};

#endif ROM_Katakana_h