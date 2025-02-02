//
// Made by Gab Rivas 01/02/25 16:07
//

#ifndef EFI_CAPSULE_VARIABLE_RESULT_JSON_H
#define EFI_CAPSULE_VARIABLE_RESULT_JSON_H

#include "../core/efi_core.h"

typedef struct {
    UINT32          Version;
    UINT32          CapsuleID;
    UINT32          RespLength;
    UINT8           Resp[];
} EFI_CAPSULE_RESULT_JSON;

#endif
