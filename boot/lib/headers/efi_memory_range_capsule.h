//
// Made by Gab Rivas 01/02/25 15:43
//

#ifndef EFI_MEMORY_RANGE_CAPSULE_H
#define EFI_MEMORY_RANGE_CAPSULE_H

#include "efi_capsule_header.h"
#include "efi_core.h"
#include "efi_memory_range.h"

// {0DE9F0EC-88B6-428F-977A-258F1D0E5E72}
#define EFI_MEMORY_RANGE_CAPSULE_GUID \
{ 0xde9f0ec, 0x88b6, 0x428f, \
{ 0x97, 0x7a, 0x25, 0x8f, 0x1d, 0xe, 0x5e, 0x72 } }

typedef struct {
    EFI_CAPSULE_HEADER              Header;
    UINT32                          OsRequestedMemoryType;
    UINT64                          NumberOfMemoryRanges;
    EFI_MEMORY_RANGE                MemoryRanges[];
} EFI_MEMORY_RANGE_CAPSULE;

#endif //EFI_MEMORY_RANGE_CAPSULE_H
