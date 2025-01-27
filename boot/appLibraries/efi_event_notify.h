//
// Made by Gab Rivas 25/01/25 23:24
//

#ifndef EFI_EVENT_NOTIFY_H
#define EFI_EVENT_NOTIFY_H

#include "efi_base_lib.h"

typedef VOID(EFIAPI *EFI_EVENT_NOTIFY)(
    IN EFI_EVENT            Event,
    IN VOID                *Context
);

#endif
