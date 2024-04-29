/*
  ** LCDI2C_UTF8 class **
  Base class for printing UTF8 strings (NFC normalized) to I2C LCD.

  ** Credentials **
  Author:  Loc P. Le <phuocloc@gmail.com>
  Updated: April 20 2024

  ** Help **
  https://github.com/locple/LCDI2C_Multilingual
*/

#ifndef LCDI2C_UTF8_h
#define LCDI2C_UTF8_h

#include "LCDI2C.h"

class CustomizedLanguage;

class LCDI2C_UTF8 : public LCDI2C {
public:
  LCDI2C_UTF8(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);
  void      begin(uint8_t cols, uint8_t lines, uint8_t dotsize);
  void      clear();                      // Clear LCD screen
  void      home();                       // Move cursor to top first position
  void      setCursor(uint8_t col, uint8_t row);
  uint8_t   getCursorColumn() { return cursorColumn; }
  uint8_t   getCursorRow() { return cursorRow; }
  void		setLongestWordLength(uint8_t);
  void      setAutoNewLine(bool);
  using     LCDI2C::write;                // Use the parent's method
  // Print methods with: moving to new line when reaching last column, pausing some times before next page
  size_t    print(const char[], int pause);
  size_t    print(const String &, int pause = 0);
  size_t    println(const char[], int pause = 0);
  size_t    println(const String &, int pause = 0);
  size_t    println(void);
  size_t    print(char);
  size_t    print(unsigned char, int = DEC);
  size_t    print(int, int = DEC);
  size_t    print(unsigned int, int = DEC);
  size_t    print(long, int = DEC);
  size_t    print(unsigned long, int = DEC);
  size_t    print(double, int = 2);
  size_t    println(char);
  size_t    println(unsigned char, int = DEC);
  size_t    println(int, int = DEC);
  size_t    println(unsigned int, int = DEC);
  size_t    println(long, int = DEC);
  size_t    println(unsigned long, int = DEC);
  size_t    println(double, int = 2);

private:
  uint8_t   longestWordLength;
  uint8_t   checkNextWordCol;

protected:
  uint8_t   ROMLetterNum;                 // Size of ROM letter mapping
  ROMCharacterType* ROMLetters;           // Link to ROM letter mapping
  CustomizedLanguage* customizedLanguage; // Link to Customized letter class
  uint8_t   minExcludedChar;
  uint8_t   maxExcludedChar;
  uint8_t   nextWordEndCol;
  uint8_t   colNum, rowNum;
  uint8_t   cursorColumn, cursorRow;
  bool      autoNewLine;

  void      newLine();
  uint8_t   getUTF8ByteNum(const byte[]);
  uint16_t   getCodePoint(const byte[], uint8_t&);
  virtual   uint16_t  getCharacter(uint16_t code);
  virtual   uint8_t   nextWordLength(const byte[], uint16_t, uint16_t);
  uint8_t   getROMCharacter(uint16_t);
};

#endif  // LCDI2C_UTF8_h