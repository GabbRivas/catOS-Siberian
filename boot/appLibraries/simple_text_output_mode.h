//
// Made by Gab Rivas 25/01/25 23:06
//

#ifndef SIMPLE_TEXT_OUTPUT_MODE_H
#define SIMPLE_TEXT_OUTPUT_MODE_H

#include "efi_base_lib.h"

typedef struct {
    INT32                              MaxMode;
    // current settings
    INT32                              Mode;
    INT32                              Attribute;
    INT32                              CursorColumn;
    INT32                              CursorRow;
    BOOLEAN                            CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

#endif
