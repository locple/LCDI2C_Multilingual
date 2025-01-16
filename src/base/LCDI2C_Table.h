/* SPDX-License-Identifier: MIT */
#ifndef LCDI2C_Table_h
#define LCDI2C_Table_h

#include "LCDI2C_Types.h"
#include <Arduino.h>

extern uint8_t getROMCharacter(uint16_t code,
                               const ROMCharacterType *table,
                               uint8_t count);

#endif // LCDI2C_Table_h
