//
// Made by Gab Rivas 31/01/25 23:24
//

#ifndef EFI_INPUT_KEY_H
#define EFI_INPUT_KEY_H

#include "../core/efi_core.h"

typedef struct {
    UINT16    ScanCode;
    CHAR16    UnicodeChar;
} EFI_INPUT_KEY;

#endif
