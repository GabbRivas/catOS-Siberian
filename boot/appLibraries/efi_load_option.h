//
// Made by Gab Rivas 25/01/25
//
// Defines the EFI_LOAD_OPTION struct
//

#ifndef EFI_LOAD_OPTION_H
#define EFI_LOAD_OPTION_H

#include "efi_base_lib.h"
#include "keyLibraries/efi_data_types.h"

typedef struct _EFI_LOAD_OPTION {
    UINT32                      Attributes;
    UINT16                      FilePathListLength;
    // CHAR16                      Description[];
    // EFI_DEVICE_PATH_PROTOCOL    FilePathList[];
    // UINT8                       OptionalData[];
} EFI_LOAD_OPTION;

#endif
