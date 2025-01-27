//
// Made by Gab Rivas 25/01/25 22:53
//

#ifndef EFI_KEY_NOTIFY_H
#define EFI_KEY_NOTIFY_H

#include "efi_base_lib.h"
#include "efi_key_data.h"

typedef EFI_STATUS(EFIAPI *EFI_KEY_NOTIFY_FUNCTION)(
    IN EFI_KEY_DATA             *KeyData
);

#endif
