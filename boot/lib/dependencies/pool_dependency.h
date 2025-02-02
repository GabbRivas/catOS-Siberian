//
// Made by Gab Rivas 02/02/25 11:05
//
// Pool library that includes function for
// allocating and freeing pools
//

#ifndef POOL_DEPENDENCY_H
#define POOL_DEPENDENCY_H

#include "../efi.h"

void *AllocatePool(EFI_SYSTEM_TABLE *SysTab, UINTN Size);

void FreePool(EFI_SYSTEM_TABLE *SysTab, void *Buffer);

#endif
