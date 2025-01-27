//
// Made by Gab Rivas 26/01/25 00:55
//

#ifndef EFI_CAPSULE_HEADER_H
#define EFI_CAPSULE_HEADER_H

#include "efi_base_lib.h"

typedef struct {
    EFI_GUID             CapsuleGUID;
    UINT32               HeaderSize;
    UINT32               Flags;
    UINT32               CapsuleImageSize;
} EFI_CAPSULE_HEADER;

#endif
