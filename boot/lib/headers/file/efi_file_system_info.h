//
// Made by Gab Rivas 02/02/25
//

#ifndef EFI_FILE_SYSTEM_INFO_H
#define EFI_FILE_SYSTEM_INFO_H

#include "../core/efi_core.h"

#define EFI_FILE_SYSTEM_INFO_ID \
{0x09576e93,0x6d3f,0x11d2,0x8e39,0x00,0xa0,0xc9,0x69,0x72,\
0x3b}

typedef struct {
    UINT64              Size;
    BOOLEAN             ReadOnly;
    UINT64              VolumeSize;
    UINT64              FreeSpace;
    UINT32              BlockSize;
    CHAR16              VolumeLabel[];
} EFI_FILE_SYSTEM_INFO;

#endif //EFI_FILE_SYSTEM_INFO_H
