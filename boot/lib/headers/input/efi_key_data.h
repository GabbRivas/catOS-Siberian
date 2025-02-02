//
// Made by Gab Rivas 31/01/25 23:17
//

#ifndef EFI_KEY_DATA_H
#define EFI_KEY_DATA_H

#include "../core/efi_core.h"
#include "efi_input_key.h"
#include "efi_key_state.h"

typedef struct {
    EFI_INPUT_KEY           Key;
    EFI_KEY_STATE           KeyState;
} EFI_KEY_DATA;

#endif
