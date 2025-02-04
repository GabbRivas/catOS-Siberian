//
// Made by Gab Rivas 02/02/25 11:56
//
// Print library that includes functions for
// formatted printing.
//

#ifndef PRINT_DEPENDENCY_H
#define PRINT_DEPENDENCY_H

#define PRINT_BUFFER_SIZE   512
#define MAX_NUMBER_LENGTH   64

#include "../efi.h"
#include "stdarg_efi_dependency.h"
#include "global_dependency.h"

// Helper Functions
// static VOID AddChar(CHAR16 **Pointer, CONST CHAR16 *End, CHAR16 c);
// static VOID AddString(CHAR16 **Pointer, CONST CHAR16 *End, CONST CHAR16 *Str);
// static VOID AddNumber(CHAR16 **Pointer, CONST CHAR16 *End, UINT64 Number, UINTN Base);

VOID Print(IN CONST CHAR16 *Format, ...);

#endif
