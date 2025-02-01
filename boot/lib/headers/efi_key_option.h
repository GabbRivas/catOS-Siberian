/*

Made by Gab Rivas 31/01/25

*/

#ifndef EFI_KEY_OPTION_H
#define EFI_KEY_OPTION_H

#include "efi_core.h"
#include "efi_boot_key_data.h"

typedef struct _EFI_KEY_OPTION {
    EFI_BOOT_KEY_DATA           KeyData;
    UINT32                      BootOptionCRC;
    UINT16                      BootOption;
    // EFI_INPUT_KEY               Keys[]
} EFI_KEY_OPTION;

#endif