//
// Made by Gab Rivas 25/01/25 22:40
//

#ifndef EFI_KEY_STATE_H
#define EFI_KEY_STATE_H

#include "efi_base_lib.h"

typedef struct EFI_KEY_STATE {
    UINT32                  KeyShiftState;
    EFI_KEY_TOGGLE_STATE    KeyToggelState;
} EFI_KEY_STATE;

#endif
