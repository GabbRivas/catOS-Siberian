//
// Made by Gab Rivas 01/02/25
//

#ifndef EFI_CAPSULE_RESULT_VARIABLE_HEADER_H
#define EFI_CAPSULE_RESULT_VARIABLE_HEADER_H

#include "efi_core.h"
#include "efi_time.h"

typedef struct {
    UINT32              VariableTotalSize;
    UINT32              Reserved;
    EFI_GUID            CapsuleGUID;
    EFI_TIME            CapsuleProcessed;
    EFI_STATUS          CapsuleStatus;
} EFI_CAPSULE_RESULT_VARIABLE_HEADER;

#endif //EFI_CAPSULE_RESULT_VARIABLE_HEADER_H
