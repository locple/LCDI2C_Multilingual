/*
  ** LCDI2C_UTF8 class implementation **
  Base class implementation for printing UTF8 strings (NFC normalized) to I2C LCD.

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#include <Arduino.h>
#include "LCDI2C_Types.h"
#include "LCDI2C_UTF8.h"
#include "LCDI2C_Custom.h"

LCDI2C_UTF8::LCDI2C_UTF8(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : LCDI2C(lcd_addr, lcd_cols, lcd_rows),
  colNum(lcd_cols), rowNum(lcd_rows),
  cursorColumn(0), cursorRow(0), nextWordEndCol(0),
  minExcludedChar(0), maxExcludedChar(0),
  longestWordLength(0), autoNewLine(true), customizedLanguage(NULL) {}

void LCDI2C_UTF8::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {
  colNum = cols;
  rowNum = lines;
  if (longestWordLength == 0 || longestWordLength > colNum)
    checkNextWordCol = 0;       // check next word from first column
  else
    checkNextWordCol = colNum - longestWordLength;
  LCDI2C::begin(cols, lines, dotsize);
}

void LCDI2C_UTF8::clear() {
  if (customizedLanguage != NULL)
    customizedLanguage->clearLetters(); // Clear customized characters
  cursorColumn = 0; cursorRow = 0;
  nextWordEndCol = checkNextWordCol;
  LCDI2C::clear();
}

void LCDI2C_UTF8::home() {
  cursorColumn = 0; cursorRow = 0;
  nextWordEndCol = checkNextWordCol;
  LCDI2C::home();
}

void LCDI2C_UTF8::setCursor(uint8_t col, uint8_t row) {
  if (row >= rowNum) row %= rowNum;
  cursorColumn = col; cursorRow = row;
  nextWordEndCol = checkNextWordCol;
  LCDI2C::setCursor(col, row);
}

void LCDI2C_UTF8::setLongestWordLength(uint8_t longest_wordlength) {
  longestWordLength = longest_wordlength;
  if (longestWordLength == 0 || longestWordLength > colNum)
    checkNextWordCol = 0;       // check next word from first column
  else
    checkNextWordCol = colNum - longestWordLength;
}

// Enable or disable auto new line (default = true)
void LCDI2C_UTF8::setAutoNewLine(bool stat = true) {
  autoNewLine = stat;
}

void LCDI2C_UTF8::newLine() {
  cursorColumn = 0;
  cursorRow = ++cursorRow % rowNum;
  nextWordEndCol = checkNextWordCol;
  LCDI2C::setCursor(cursorColumn, cursorRow);
}

// Get byte number of the UTF8 codes in text reperenting the letter
uint8_t LCDI2C_UTF8::getUTF8ByteNum(const byte text[]) {
  if (text[0] < 0x80) return 1;
  else if (text[0] < 0xC2) return 0;  // Invalid UTF8
  uint8_t byte0 = text[0], num = 1;

  // Scan first byte for UTF8 byte number (= total of first bits in this byte)
  for (int i = 0; i < 4; i++) {   // max 4 bytes (presented by 4 first bits)
    byte0 <<= 1;
    if (byte0 & 0x80) num++;
    else break;
  }

  // Check the total of following bytes
  for (int i = 1; i < num; i++)
    if ((text[i] >> 6) != 0x02) return 0; // Invalid UTF8

  return num;
}

// Convert UTF8 codes to code point (UTF-16) reprenting the letter
// Output: nbytes = number of UTF-8 bytes used in convetion
// Most popular UTF-8: 2-byte or 3-byte codes
uint16_t LCDI2C_UTF8::getCodePoint(const byte text[], uint8_t& nbytes) {
  uint16_t result = 0;
  nbytes = 1;
  if (text[0] < 0x80) return (uint16_t) text[0];
  else if (text[0] < 0xC2) return result;  // Invalid UTF8
  uint16_t units[4];  // Decomposed byte codes, each unit size large enough for whole code point
  byte byte0 = text[0];

  // Scan first byte for UTF8 byte number (= total of first bits in this byte)
  for (int i = 0; i < 4; i++) {       // Max 4 bytes (presented by 4 first bits)
    byte0 <<= 1;                      // Cut the next bit in 4 first bits
    if (byte0 & 0x80) {               // Left shift while next bit = 1
      nbytes++;
      units[i+1] = text[i+1] & 0x7F;  // Extract approriate component of the code point
    } else {
      units[0] = byte0 >> nbytes;     // Right shift to start position without first bits 1
      for (int j = nbytes; j > 0; j--) { // Collect each next component
        units[j-1] <<= 6 * (nbytes - j); // Each component of 6-bit
        result += units[j-1];            // will be joined
      }
      return result;
    }
  }

  return result; // Invalid UTF8
}

// Predict the length of the word to print
uint8_t LCDI2C_UTF8::nextWordLength(const byte text[], uint16_t start, uint16_t code) {
  uint16_t i = start, nbytes, length = 0;

  while (text[i] != '\0') {                     // Find first non-letter character from start
    if ((text[i] < 0x30) ||                     // Below '0'
        (text[i] > 0x39 && text[i] < 0x41) ||   // Between '9' and 'A'
        (text[i] > 0x5A && text[i] < 0x61) ||   // Between 'Z' and 'a'
        (text[i] > 0x7A && text[i] < 0x80)) {   // Between 'z' and first multi-byte UTF8 character
          return length;
    } else {                                    // Go through UTF8 characters
        nbytes = getUTF8ByteNum(&text[i]);
        if (nbytes) {
          length++;
          i += nbytes;
        } else i++;
      } // else
    } // if

  return length;
}

// Find corresponding symbols in LCD character table
uint8_t LCDI2C_UTF8::getROMCharacter(uint16_t c) {
  for (int idx = 0; idx < ROMLetterNum; idx++)
    if (c == ROMLetters[idx].code)
      return ROMLetters[idx].link;

  return NOTFOUND;
}

// Mapping from Code point to one equivalent character on LCD's ROM or CGRAM.
uint16_t LCDI2C_UTF8::getCharacter(uint16_t code) {
  uint8_t ord;

  if (code < 0x7E ||                          // ASCII character?
     (code <= maxExcludedChar && code >= minExcludedChar))	// Exclude a selected range in a LCD's ROM character set
    if (code > 0x1F)
      return (uint16_t) code;                 // Printable
    else
      return (uint16_t) '*';                  // Non-printable

  // Look for Unicode character in CGRAM (search in CGRAM first)
  if (customizedLanguage != NULL) {
    ord = customizedLanguage->getCharacter(code, cursorColumn, cursorRow);
    if (ord != NOTFOUND)                      // Character is in CGRAM?
      return (uint16_t) ord;                  // Return customized character
  }

  // Look for Unicode character in ROM
  ord = getROMCharacter(code);
  if (ord != NOTFOUND)                        // Character is in ROM?
    return (uint16_t) ord;                    // Return ROM character

  return (uint16_t) '*';                      // Unknown character
}

// Printing char* 'text' that contains multibyte UTF8 letters,
// automatically moving to new line when reaching last column
// 'pause' >= 0: delay 'pause' seconds before printing on next page
size_t LCDI2C_UTF8::print(const char text[], int pause) {
  uint16_t code;
  uint16_t ord;
  uint8_t length, nbytes;
  size_t nletters = 0;
  bool skip_print;

  // Look at each UTF-8 byte in text till the end
  for (uint16_t i = 0; text[i] != '\0'; i += nbytes, nletters++) {
    // Convert to appropriate code point (UTF-16). Out: nbytes = bytes used in the convetion.
	code = getCodePoint((const byte*) &text[i], nbytes);

    // Check for enough spaces to print the whole word
    skip_print = false;
    if (autoNewLine && (cursorColumn > nextWordEndCol)) {
      length = nextWordLength((const byte*) text, i, code);   // Note that we don't check again on the same word
      if (length) nextWordEndCol = (length > colNum? colNum - 1 : cursorColumn + length - 1);
      if (nextWordEndCol >= colNum)             // Not enough columns to print the whole word?
        if ((cursorRow + 1) % rowNum) {         // Print it if next row exists
          newLine();                            // Automatically move to the next row to print the whole next word
		  if (code == 0x20) skip_print = true;  // Don't print leading space of next word
        } else {                                // No row left to print
          if (pause > 0) delay(pause * 1000);
          clear();                              // Automatically clear LCD and CGRAM for printing the whole next word
        }
    }

    // Process to print the character 'code'
    if (!skip_print && cursorColumn < colNum) { // The leading space not printed after auto moving, and don't move the cursor
      // Retrieve order in LCD's ROM or CGRAM for the character 'code'
	  ord = getCharacter(code);
	  if (ord < 0x100)                          // Only one character returned
          write(uint8_t(ord));
	  else {                                    // Two character returned (base and diacritic), like in Katakana.
	      write(uint8_t(ord & 0x00FF));            // Print base character (low byte)
		  write(uint8_t(ord >> 8));                // Print diacritic character (high byte)
		  ++cursorColumn;                       // Move 1 pos cause printing 2 characters at once (having enough space)
      }

      // Move cursor to next position
      if (++cursorColumn == colNum)             // Check if the cursor exceeds max column of LCD screen?
        if (text[i + nbytes] != '\0')           // Check if the end of 'text'?
          if (autoNewLine) {
            if ((cursorRow + 1) % rowNum)       // Check if existing rows left to print?
              newLine();                        // Automatically move to the next row if the cursor exceeds colNum
            else {
              if (pause >= 0) delay(pause * 1000);
              clear();                          // Automatically clear LCD and CGRAM if no space left to print
            }
	      } else // autoNewLine
            cursorColumn = colNum;              // Keep the cursor staying at the end of LCD screen
    } // skip_print
  } // for

  return nletters;
}

// Printing String 'text' that contains multibyte UTF8 letters,
// automatically moving to new line when reaching last column
// 'pause' >= 0: delay 'pause' seconds before printing on next page
size_t LCDI2C_UTF8::print(const String& text, int pause) {
  unsigned int size = text.length() + 1;
  char buff[size];
  text.toCharArray(buff, size);
  return print(buff, pause);
}

// Printing char* 'text' that contains multibyte UTF8 letters + new line,
// automatically moving to new line when reaching last column
// 'pause' >= 0: delay 'pause' seconds before printing on next page
size_t LCDI2C_UTF8::println(const char text[], int pause) {
  size_t len = print(text, pause);
  newLine();
  return len;
}

// Printing String 'text' that contains multibyte UTF8 letters + new line,
// automatically moving to new line when reaching last column
// 'pause' >= 0: delay 'pause' seconds before printing on next page
size_t LCDI2C_UTF8::println(const String& text, int pause) {
  size_t len = print(text, pause);
  newLine();
  return len;
}

size_t LCDI2C_UTF8::println(void) {
  newLine();
  return 0;
}

size_t LCDI2C_UTF8::print(char c) {
  char str[2] = {c, '\0'};
  return print(str);
}

size_t LCDI2C_UTF8::print(unsigned char b, int base) {
  return print((unsigned long) b, base);
}

size_t LCDI2C_UTF8::print(int n, int base) {
  return print((long) n, base);
}

size_t LCDI2C_UTF8::print(unsigned int n, int base) {
  return print((unsigned long) n, base);
}

size_t LCDI2C_UTF8::print(long n, int base) {
  size_t len = Print::print(n, base);
  cursorColumn += len;

  return len;
}

size_t LCDI2C_UTF8::print(unsigned long n, int base) {
  size_t len = Print::print(n, base);
  cursorColumn += len;

  return len;
}

size_t LCDI2C_UTF8::print(double n, int digits) {
  size_t len = Print::print(n, digits);
  cursorColumn += len;

  return len;
}

size_t LCDI2C_UTF8::println(char c) {
  size_t len = print(c);
  newLine();
  return len;
}

size_t LCDI2C_UTF8::println(unsigned char b, int base) {
  return println((unsigned long) b, base);
}

size_t LCDI2C_UTF8::println(int n, int base) {
  return println((long) n, base);
}

size_t LCDI2C_UTF8::println(unsigned int n, int base) {
  return println((unsigned long) n, base);
}

size_t LCDI2C_UTF8::println(long n, int base) {
  size_t len = Print::print(n, base);
  newLine();

  return len;
}

size_t LCDI2C_UTF8::println(unsigned long n, int base) {
  size_t len = Print::print(n, base);
  newLine();

  return len;
}

size_t LCDI2C_UTF8::println(double n, int digits) {
  size_t len = Print::print(n, digits);
  newLine();

  return len;
}