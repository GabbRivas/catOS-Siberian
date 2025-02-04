//
// Made by Gab Rivas 02/02/25 11:05
//
// Pool library that includes function for
// allocating and freeing pools
//

#ifndef POOL_DEPENDENCY_H
#define POOL_DEPENDENCY_H

#include "../efi.h"
#include "global_dependency.h"

EFI_STATUS AllocatePool(UINTN Size, VOID **Buffer);
EFI_STATUS FreePool(VOID *Buffer);

#endif
