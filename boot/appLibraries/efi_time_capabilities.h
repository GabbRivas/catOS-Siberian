//
// Made by Gab Rivas 26/01/25 00:46
//

#ifndef EFI_TIME_CAPABILITIES_H
#define EFI_TIME_CAPABILITIES_H

#include "efi_base_lib.h"

typedef struct {
    UINT32          Resolution;
    UINT32          Accuracy;
    BOOLEAN         SetsToZero;
} EFI_TIME_CAPABILITIES;

#endif
