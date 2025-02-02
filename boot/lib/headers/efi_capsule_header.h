//
// Made by Gab Rivas 01/01/25
//

#ifndef EFI_CAPSULE_HEADER_H
#define EFI_CAPSULE_HEADER_H

#include "efi_core.h"

typedef struct {
    EFI_GUID            CapsuleGUID;
    UINT32              HeaderSize;
    UINT32              Flags;
    UINT32              CapsuleImageSize;
} EFI_CAPSULE_HEADER;

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

#endif //EFI_CAPSULE_HEADER_H
