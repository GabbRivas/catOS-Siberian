//
// Made by Gab Rivas 26/01/25 00:53
//

#ifndef EFI_RESET_TYPE_H
#define EFI_RESET_TYPE_H

#include "efi_base_lib.h"

typedef enum {
   EfiResetCold,
   EfiResetWarm,
   EfiResetShutdown,
   EfiResetPlatformSpecific
} EFI_RESET_TYPE;


#endif
