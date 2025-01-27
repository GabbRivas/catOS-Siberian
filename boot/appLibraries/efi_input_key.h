//
// Made by Gab Rivas 25/01/25 22:45
//

#ifndef EFI_INPUT_KEY_H
#define EFI_INPUT_KEY_H

#include "efi_base_lib.h"

typedef struct {
    UINT16          ScanCode;
    CHAR16          UnicodeChar;
} EFI_INPUT_KEY;

#endif
