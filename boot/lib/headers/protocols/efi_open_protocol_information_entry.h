//
// Made by Gab Rivas 01/02/25
//

#ifndef EFI_OPEN_PROTOCOL_INFORMATION_ENTRY_H
#define EFI_OPEN_PROTOCOL_INFORMATION_ENTRY_H

#include "../core/efi_core.h"

typedef struct {
    EFI_HANDLE              AgentHandle;
    EFI_HANDLE              ControllerHandle;
    UINT32                  Attributes;
    UINT32                  OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

#endif //EFI_OPEN_PROTOCOL_INFORMATION_ENTRY_H
