//
// Made by Gab Rivas 25/01/25 14:14
//
// Indicates the revision of the EFI_KEY_OPTION structure. This revision level should be 0.
//

#ifndef EFI_BOOT_KEY_DATA_H
#define EFI_BOOT_KEY_DATA_H

#include "efi_base_lib.h"

typedef union {
    struct {
        UINT32   Revision : 8;
        UINT32   ShiftPressed : 1;
        UINT32   ControlPressed : 1;
        UINT32   AltPressed : 1;
        UINT32   LogoPressed : 1;
        UINT32   MenuPressed : 1;
        UINT32   SysReqPressed : 1;
        UINT32   Reserved : 16;
        UINT32   InputKeyCount : 2;
    } Options;
    UINT32       PackedValue;
} EFI_BOOT_KEY_DATA;

#endif
