//
// Made by Gab Rivas 01/02/25
//

#ifndef EFI_MEMORY_RANGE_H
#define EFI_MEMORY_RANGE_H

#include "efi_core.h"

typedef struct {
    EFI_PHYSICAL_ADDRESS            Address;
    UINT64                          Length;
} EFI_MEMORY_RANGE;

#endif
