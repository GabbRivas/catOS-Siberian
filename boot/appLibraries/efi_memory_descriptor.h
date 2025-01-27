//
// Made by Gab Rivas
//

#ifndef EFI_MEMORY_DESCRIPTOR_H
#define EFI_MEMORY_DESCRIPTOR_H

#include "efi_base_lib.h"

typedef struct {
    UINT32                  Type;
    EFI_PHYSICAL_ADDRESS    PhysicalStart;
    EFI_VIRTUAL_ADDRESS     VirtualStart;
    UINT64                  NumberOfPages;
    UINT64                  Attribute;
} EFI_MEMORY_DESCRIPTOR;

#endif
