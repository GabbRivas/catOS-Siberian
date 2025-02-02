//
// Made by Gab Rivas 31/01/25 23:09
//

#ifndef EFI_TABLE_HEADER_H
#define EFI_TABLE_HEADER_H

#include "efi_core.h"

typedef struct {
    UINT64          Signature;
    UINT32          Revision;
    UINT32          HeaderSize;
    UINT32          CRC32;
    UINT32          Reserved;
} EFI_TABLE_HEADER;

#endif
