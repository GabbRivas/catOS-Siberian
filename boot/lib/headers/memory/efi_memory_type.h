//
// Made by Gab Rivas 01/02/25 16:56
//

#ifndef EFI_MEMORY_TYPE_H
#define EFI_MEMORY_TYPE_H

#include "../core/efi_core.h"

typedef enum{
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMapped,IOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnnaceptedMemoryType,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

#endif //EFI_MEMORY_TYPE_H
