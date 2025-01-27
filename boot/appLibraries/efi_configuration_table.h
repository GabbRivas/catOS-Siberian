//
// Made by Gab Rivas 26/01/25 11:41
//

#ifndef EFI_CONFIGURATION_TABLE_H
#define EFI_CONFIGURATION_TABLE_H

#include "efi_base_lib.h"

typedef struct {
    EFI_GUID        VendorGuid;
    VOID           *VendorTable;
} EFI_CONFIGURATION_TABLE;

#endif
