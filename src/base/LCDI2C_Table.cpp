/* SPDX-License-Identifier: MIT */
#include "LCDI2C_Table.h"

#include "LCDI2C_Types.h"
#include <stdlib.h>

static int cmpTableEntry(const void *keyp, const void *entryp) {
  uint16_t code = *(uint16_t *)keyp;
  const ROMCharacterType *entry = (const ROMCharacterType *)entryp;
  uint16_t entryCode = pgm_read_word(&(entry->code));
  return (code > entryCode) - (code < entryCode);
}

uint8_t getROMCharacter(uint16_t code, const ROMCharacterType *table,
                        uint8_t count) {
  const ROMCharacterType *entry = (const ROMCharacterType *)bsearch(
      &code, table, count, sizeof(ROMCharacterType), &cmpTableEntry);

  if (entry)
    return pgm_read_byte(&(entry->link));
  else
    return NOTFOUND;
}
