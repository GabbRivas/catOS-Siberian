//
// Made by Gab Rivas 25/01/25 23:41
//

#ifndef EFI_MEMORY_TYPE_H
#define EFI_MEMORY_TYPE_H

#include "efi_base_lib.h"

typedef enum {
   EfiReservedMemoryType,
   EfiLoaderCode,
   EfiLoaderData,
   EfiBootServicesCode,
   EfiBootServicesData,
   EfiRuntimeServicesCode,
   EfiRuntimeServicesData,
   EfiConventionalMemory,
   EfiUnusableMemory,
   EfiACPIReclaimMemory,
   EfiACPIMemoryNVS,
   EfiMemoryMappedIO,
   EfiMemoryMappedIOPortSpace,
   EfiPalCode,
   EfiPersistentMemory,
   EfiUnacceptedMemoryType,
   EfiMaxMemoryType
} EFI_MEMORY_TYPE;

#endif
