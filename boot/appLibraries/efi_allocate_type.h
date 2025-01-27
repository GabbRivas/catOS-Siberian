//
// Made by Gab Rivas 25/01/25 23:39
//

#ifndef EFI_ALLOCATE_TYPE_H
#define EFI_ALLOCATE_TYPE_H

#include "efi_base_lib.h"

typedef enum{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

#endif
