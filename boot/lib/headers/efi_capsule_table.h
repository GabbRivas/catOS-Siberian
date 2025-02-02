//
// Made by Gab Rivas 01/01/25
//

#ifndef EFI_CAPSULE_TABLE_H
#define EFI_CAPSULE_TABLE_H

#include "efi_core.h"

typedef struct {
    UINT32          CapsuleArrayNumber;
    VOID           *CapsulePtr[1];
} EFI_CAPSULE_TABLE;

#endif
