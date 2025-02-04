//
// Made by Gab Rivas 02/02/25 16:05
//

#ifndef EFI_FILE_IO_TOKEN_H
#define EFI_FILE_IO_TOKEN_H

#include "../core/efi_core.h"

typedef struct {
    EFI_EVENT           Event;
    EFI_STATUS          Status;
    UINTN               BufferSize;
    VOID                *Buffer;
} EFI_FILE_IO_TOKEN;

#endif //EFI_FILE_IO_TOKEN_H
