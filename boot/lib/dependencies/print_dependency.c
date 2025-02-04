//
// Made by Gab Rivas 02/02/25 11:56
//

#include "print_dependency.h"

static CONST CHAR16 mHexDigits[] = L"0123456789ABCDEF"; //Doesn't matter, use -fshort-wchar on clang compiler for it to work

static VOID AddChar(CHAR16 **Pointer, CONST CHAR16 *End, CHAR16 c) {
    if (*Pointer < (CHAR16 *)End) *(*Pointer)++ = c;
}

static VOID AddString(CHAR16 **Pointer, CONST CHAR16 *End, CONST CHAR16 *Str) {
    while (Str && *Str && *Pointer < (CHAR16 *)End) {
        AddChar(Pointer, End, *Str++);
    }
}

static VOID AddNumber(CHAR16 **Pointer, CONST CHAR16 *End, UINT64 Number, UINTN Base) {

    CHAR16 NumBuf[MAX_NUMBER_LENGTH] = {0};
    INTN Index = 0;
    UINT64 Temp = Number;

    if (Number == 0){
        AddChar(Pointer, End, L'0');
        return;
    }

    while (Temp > 0 && Index < MAX_NUMBER_LENGTH - 1){
        NumBuf[Index++] = mHexDigits[Temp % Base];
        Temp /= Base;
    }

    // Write reversed string to buffer
    while (Index > 0 && *Pointer < End){
        AddChar(Pointer, End, NumBuf[--Index]);
    }
}

VOID Print(CONST CHAR16 *Format, ...){
    va_list Args;
    CHAR16 Buffer[PRINT_BUFFER_SIZE];
    CHAR16 *Ptr = Buffer;
    CONST CHAR16 *End = Buffer + PRINT_BUFFER_SIZE - 1;

    va_start(Args, Format);

    while (*Format && Ptr < End){
        // Handle regular characters
        if (*Format != L'%'){
            AddChar(&Ptr, End, *Format++);
            continue;
        }

        // Handle format specifiers
        switch (*++Format){
            case L's':
                AddString(&Ptr, End, va_arg(Args, CHAR16*));
                break;

            case L'd':
                AddNumber(&Ptr, End, va_arg(Args, UINT64), 10);
                break;

            case L'x':
                AddNumber(&Ptr, End, va_arg(Args, UINT64), 16);
                break;

            case L'c':
                AddChar(&Ptr, End, (CHAR16)va_arg(Args, UINTN));
                break;

            case L'%':
                AddChar(&Ptr, End, L'%');
                break;

            default:
                AddChar(&Ptr, End, L'?');
                break;
        }
        Format++;
    }

    // Finalize and print
    *Ptr = L'\0';
    Sys->ConsoleOutput->OutputString(Sys->ConsoleOutput,Buffer);
    va_end(Args);
}
