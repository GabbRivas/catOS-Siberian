//
// Made by Gab Rivas 01/02/25 15:26
//

#ifndef EFI_CAPSULE_BLOCK_DESCRIPTOR_H
#define EFI_CAPSULE_BLOCK_DESCRIPTOR_H

#include "../core/efi_core.h"

typedef struct {
    UINT64                      Length;
    union{
        EFI_PHYSICAL_ADDRESS    DataBlock;
        EFI_PHYSICAL_ADDRESS    ContinuationPointer;
    }Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

#endif //EFI_CAPSULE_BLOCK_DESCRIPTOR_H
