//
// Made by Gab Rivas 01/02/25 15:08
//

#ifndef EFI_TIME_CAPABILITIES_H
#define EFI_TIME_CAPABILITIES_H

#include "../core/efi_core.h"

typedef struct{
    UINT32          Resolution;
    UINT32          Accuracy;
    BOOLEAN         SetsToZero;
} EFI_TIME_CAPABILITIES;

#endif
