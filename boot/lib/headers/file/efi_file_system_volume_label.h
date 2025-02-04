//
// Made by Gab Rivas 02/02/25
//

#ifndef EFI_FILE_SYSTEM_VOLUME_LABEL_H
#define EFI_FILE_SYSTEM_VOLUME_LABEL_H

#include "../core/efi_core.h"

#define EFI_FILE_SYSTEM_VOLUME_LABEL_ID \
{0xdb47d7d3,0xfe81,0x11d3,0x9a35,\
{0x00,0x90,0x27,0x3f,0xC1,0x4d}}

typedef struct {
    CHAR16          VolumeLabel[];
} EFI_FILE_SYSTEM_VOLUME_LABEL;

#endif //EFI_FILE_SYSTEM_VOLUME_LABEL_H
