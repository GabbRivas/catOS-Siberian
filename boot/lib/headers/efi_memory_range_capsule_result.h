//
// Made by Gab Rivas 01/02/25 15:48
//

#ifndef EFI_MEMORY_RANGE_CAPSULE_RESULT_H
#define EFI_MEMORY_RANGE_CAPSULE_RESULT_H

#include "efi_core.h"

typedef struct {
    UINT64              FirmwareMemoryRequirement;
    UINT64              NumberOfMemoryRanges;
} EFI_MEMORY_RANGE_CAPSULE_RESULT;

#endif
