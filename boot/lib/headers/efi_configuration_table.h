//
// Made by Gab Rivas 01/02/25 16:30
//

#ifndef EFI_CONFIGURATION_TABLE_H
#define EFI_CONFIGURATION_TABLE_H

#include "efi_core.h"

typedef struct {
    EFI_GUID        VendorGUID;
    VOID           *VendorTable;
} EFI_CONFIGURATION_TABLE;

#endif //EFI_CONFIGURATION_TABLE_H
