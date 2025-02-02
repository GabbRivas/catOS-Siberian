//
// Made by Gab Rivas 02/02/25 11:56
//
// Print library that includes function for
// formatted printing.
//

#ifndef PRINT_DEPENDENCY_H
#define PRINT_DEPENDENCY_H

#include "../efi.h"
#include "pool_dependency.h"

#define VA_LIST         VOID*
#define VA_START(Args)  (Args = (VA_LIST)((UINT8*)&Format + sizeof(Format)))
#define VA_ARG(Args, T) (*(T*)((Args = (UINT8*)Args + sizeof(T)) - sizeof(T)))
#define VA_END(Args)    ((VOID)Args)

void Output(EFI_SYSTEM_TABLE *SysTab, const CHAR16 *Format, ...);

[[noreturn]] void HaltSystem(EFI_SYSTEM_TABLE *SysTab, const CHAR16 *Format,...);

#endif
