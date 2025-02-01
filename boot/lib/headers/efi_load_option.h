/*

Made by Gab Rivas 31/01/25 10:50

*/

#ifndef EFI_LOAD_OPTION_H
#define EFI_LOAD_OPTION_H

#include "efi_core.h"

typedef struct _EFI_LOAD_OPTION {
    UINT32              Attrributes;
    UINT16              FilePathListLength;
    // CHAR16                         Description[];
    // EFI_DEVICE_PATH_PROTOCOL       FilePathList[];
    // UINT8                          OptionalData[];
} EFI_LOAD_OPTION;

#define LOAD_OPTION_ACTIVE                0x00000001
#define LOAD_OPTION_FORCE_RECONNECT       0x00000002
#define LOAD_OPTION_HIDDEN                0x00000008
#define LOAD_OPTION_CATEGORY              0x00001F00

#define LOAD_OPTION_CATEGORY_BOOT         0x00000000
#define LOAD_OPTION_CATEGORY_APP          0x00000100
// All values 0x00000200-0x00001F00 are reserved

#endif