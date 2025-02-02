//
// Made by Gab Rivas 01/02/25 16:02
//

#ifndef EFI_CAPSULE_RESULT_VARIABLE_FMP_H
#define EFI_CAPSULE_RESULT_VARIABLE_FMP_H

#include "efi_core.h"

typedef struct {
    UINT16          Version;
    UINT8           PayloadIndex;
    UINT8           UpdateImageIndex;

    EFI_GUID        UpdateImageTypeId;

    // CHAR16       CapsuleFileName[];
    // CHAR16       CapsuleTarget[];
} EFI_CASPULE_RESULT_VARIABLE_FMP;

#endif //EFI_CAPSULE_RESULT_VARIABLE_FMP_H
