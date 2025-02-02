//
// Made by Gab Rivas 01/02/25 16:54
//

#ifndef EFI_ALLOCATE_TYPE_H
#define EFI_ALLOCATE_TYPE_H

#include "../core/efi_core.h"

typedef enum{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

#endif //EFI_ALLOCATE_TYPE_H
