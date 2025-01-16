/*
  ** Vietnamese customization data **
  Vietnamese code points to customized character maps

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Vietnamese tones & diacritics for 5x8 Latin letters **
  (C) 2023 Loc P. Le

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef Custom_Vietnamese_h
#define Custom_Vietnamese_h

#include "../base/LCDI2C_Custom.h"
#include "../base/LCDI2C_Types.h"


// List of Vietnamese letters with diacritics and custom Unicode characters
const uint8_t VietnameseCustomLetterNum = 136;
extern CustomCharacterType VietnameseCustomLetters[VietnameseCustomLetterNum];
;

class CustomizedVietnamese : public CustomizedLanguage {
public:
  CustomizedVietnamese(LCDI2C_UTF8 *lcd) : CustomizedLanguage(lcd) {
    CustomLetterNum = VietnameseCustomLetterNum;
    CustomLetters = VietnameseCustomLetters;
  }

protected:
  uint8_t getAlternativeLetter(uint16_t c) override {
    // Convert a Vietnamese letter with diacritics into coresponding Latin
    // letter (without diacritics)
    switch (c) {
    case 0x111:
    case 0x20AB: // VND symbol
      return 'd';
    case 0x110:
      return 'D';
    case 0xE0 ... 0xE3:
    case 0x103:
    case 0x1EA1:
    case 0x1EA3:
    case 0x1EA5:
    case 0x1EA7:
    case 0x1EA9:
    case 0x1EAB:
    case 0x1EAD:
    case 0x1EAF:
    case 0x1EB1:
    case 0x1EB3:
    case 0x1EB5:
    case 0x1EB7:
      return 'a';
    case 0xC0 ... 0xC3:
    case 0x102:
    case 0x1EA0:
    case 0x1EA2:
    case 0x1EA4:
    case 0x1EA6:
    case 0x1EA8:
    case 0x1EAA:
    case 0x1EAC:
    case 0x1EAE:
    case 0x1EB0:
    case 0x1EB2:
    case 0x1EB4:
    case 0x1EB6:
      return 'A';
    case 0xE8 ... 0xEA:
    case 0x1EB9:
    case 0x1EBB:
    case 0x1EBD:
    case 0x1EBF:
    case 0x1EC1:
    case 0x1EC3:
    case 0x1EC5:
    case 0x1EC7:
      return 'e';
    case 0xC8 ... 0xCA:
    case 0x1EB8:
    case 0x1EBA:
    case 0x1EBC:
    case 0x1EBE:
    case 0x1EC0:
    case 0x1EC2:
    case 0x1EC4:
    case 0x1EC6:
      return 'E';
    case 0xEC:
    case 0xED:
    case 0x129:
    case 0x1EC9:
    case 0x1ECB:
      return 'i';
    case 0xCC:
    case 0xCD:
    case 0x128:
    case 0x1EC8:
    case 0x1ECA:
      return 'I';
    case 0xB0: // degree symbol
    case 0xF2 ... 0XF5:
    case 0x1A1:
    case 0x1ECD:
    case 0x1ECF:
    case 0x1ED1:
    case 0x1ED3:
    case 0x1ED5:
    case 0x1ED7:
    case 0x1ED9:
    case 0x1EDB:
    case 0x1EDD:
    case 0x1EDF:
    case 0x1EE1:
    case 0x1EE3:
      return 'o';
    case 0xD2 ... 0xD5:
    case 0x1A0:
    case 0x1ECC:
    case 0x1ECE:
    case 0x1ED0:
    case 0x1ED2:
    case 0x1ED4:
    case 0x1ED6:
    case 0x1ED8:
    case 0x1EDA:
    case 0x1EDC:
    case 0x1EDE:
    case 0x1EE0:
    case 0x1EE2:
      return 'O';
    case 0xF9 ... 0xFA:
    case 0x169:
    case 0x1B0:
    case 0x1EE5:
    case 0x1EE7:
    case 0x1EE9:
    case 0x1EEB:
    case 0x1EED:
    case 0x1EEF:
    case 0x1EF1:
      return 'u';
    case 0xD9 ... 0xDA:
    case 0x168:
    case 0x1AF:
    case 0x1EE4:
    case 0x1EE6:
    case 0x1EE8:
    case 0x1EEA:
    case 0x1EEC:
    case 0x1EEE:
    case 0x1EF0:
      return 'U';
    case 0xFD:
    case 0x1EF3:
    case 0x1EF5:
    case 0x1EF7:
    case 0x1EF9:
      return 'y';
    case 0xDD:
    case 0x1EF2:
    case 0x1EF4:
    case 0x1EF6:
    case 0x1EF8:
      return 'Y';
    default: // Input code point is not Vietnamese!
      return '*';
    }
  }
};

#endif // Custom_Vietnamese_h