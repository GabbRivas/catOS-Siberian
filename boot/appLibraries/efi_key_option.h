//
// Made by Gab Rivas 25/01/25 14:11
//
// Launching Boot#### Load Options Using Hot Keys
// 0-9
// A-F
//

#ifndef EFI_KEY_OPTION_H
#define EFI_KEY_OPTION_H

#include "efi_base_lib.h"
#include "efi_boot_key_data.h"

typedef struct _EFI_KEY_OPTION {
    EFI_BOOT_KEY_DATA           KeyData;
    UINT32                      BootOptionCRC;
    UINT16                      BootOption;
    // EFI_INPUT_KEY               Keys[];
} EFI_KEY_OPTION;

#endif
