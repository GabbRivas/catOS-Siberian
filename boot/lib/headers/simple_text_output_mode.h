//
// Made by Gab Rivas 31/01/25 23:40
//

#ifndef SIMPLE_TEXT_OUTPUT_MODE_H
#define SIMPLE_TEXT_OUTPUT_MODE_H

#include "efi_core.h"

typedef struct {
    INT32               MaxMode;
    // Current Settings
    INT32               Mode;
    INT32               Attribute;
    INT32               CursorColumn;
    INT32               CursorRow;
    BOOLEAN             CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

#endif
