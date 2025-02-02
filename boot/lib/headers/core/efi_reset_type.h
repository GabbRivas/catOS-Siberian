//
// Made by Gab Rivas 01/01/25
//

#ifndef EFI_RESET_TYPE_H
#define EFI_RESET_TYPE_H

#include "efi_core.h"

typedef enum {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

#endif
