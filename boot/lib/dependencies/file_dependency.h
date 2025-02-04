//
// Made by Gab Rivas 02/02/25 16:39
//

#ifndef FILE_DEPENDENCY_H
#define FILE_DEPENDENCY_H

#include "../efi.h"
#include "global_dependency.h"
#include "print_dependency.h"
#include "pool_dependency.h"

EFI_STATUS FileOpenRoot(EFI_FILE_PROTOCOL **Root);
EFI_STATUS FileOpen(EFI_FILE_PROTOCOL *Dir, CHAR16 *Path, EFI_FILE_PROTOCOL **File);
EFI_STATUS FileGetSize(EFI_FILE_PROTOCOL *File, UINTN *Size);
EFI_STATUS FileRead(EFI_FILE_PROTOCOL *File, UINTN *Size, VOID **Buffer);
EFI_STATUS FileClose(EFI_FILE_PROTOCOL *File);

#endif
