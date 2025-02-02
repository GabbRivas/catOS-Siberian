//
// Made by Gab Rivas 31/01/25
//

#ifndef EFI_KEY_NOTIFY_FUNCTION_H
#define EFI_KEY_NOTIFY_FUNCTION_H

#include "efi_core.h"
#include "efi_key_data.h"

typedef EFI_STATUS(EFIAPI *EFI_KEY_NOTIFY_FUNCTION)(
    IN EFI_KEY_DATA            *KeyData
);


#endif
