//
// Made by Gab Rivas 01/02/25 16:42
//

#ifndef EFI_EVENT_NOTIFY_H
#define EFI_EVENT_NOTIFY_H

#include "../core/efi_core.h"

typedef VOID(EFIAPI *EFI_EVENT_NOTIFY)(
    IN EFI_EVENT        Event,
    IN VOID            *Context
);

#endif //EFI_EVENT_NOTIFY_H
