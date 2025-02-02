//
// Made by Gab Rivas 02/02/25 11:56
//

#include "print_dependency.h"

// Format utilities

// Integer to Hex String
static void UintHex(UINT64 Value, CHAR16 *Buffer){
    const CHAR16 HexDigits[]=u"0123456789ABCDEF";
    for (INTN i=15;i>=0;i--){
        Buffer[i]=HexDigits[Value & 0xF];
        Value>>=4;
    }
    Buffer[16]=L'\0';
}

// Integer to Decimal String
static void UintDec(UINT64 Value, CHAR16*Buffer){
    if (Value==0){
        Buffer[0]=L'0';
        Buffer[1]=L'0';
        return;
    }
    INTN Index=0;
    while(Value>0){
        Buffer[Index++]=L'0'+(Value%10);
        Value/=10;
    }

    for(INTN a=0, b=Index-1; a<b; a++, b--){
        CHAR16 Temp=Buffer[a];
        Buffer[a]=Buffer[b];
        Buffer[b]=Temp;
    }
}

static void ProcessSpecifier(CHAR16 Specifier,VA_LIST *Args,CHAR16 **Pointer, CONST CHAR16 *BufferEnd) {
    switch (Specifier) {
    case L's': { //String
        CHAR16 *String = VA_ARG(*Args, CHAR16*);
        while (*String && *Pointer < BufferEnd) {
            *(*Pointer)++ = *String++;
        }
        break;
    }
    case L'd': { //Decimal
        CHAR16 NumBuf[32];
        UintDec(VA_ARG(*Args, UINT64), NumBuf);
        for (INTN i = 0; NumBuf[i] && *Pointer < BufferEnd; i++) {
            *(*Pointer)++ = NumBuf[i];
        }
        break;
    }
    case L'x': { //Hexadecimal
        CHAR16 HexBuf[17];
        UintHex(VA_ARG(*Args, UINT64), HexBuf);
        for (INTN i = 0; HexBuf[i] && *Pointer < BufferEnd; i++) {
            *(*Pointer)++ = HexBuf[i];
        }
        break;
    }
    case L'c': {
        if (*Pointer < BufferEnd) {
            *(*Pointer)++ = (CHAR16)VA_ARG(*Args, UINTN);
        }
        break;
    }
    default:
        if (*Pointer < BufferEnd) *(*Pointer)++ = L'%';
        if (*Pointer < BufferEnd) *(*Pointer)++ = Specifier;
        break;
    }
}

void Output(EFI_SYSTEM_TABLE *SysTab, const CHAR16 *Format, ...) {
    VA_LIST Args;
    VA_START(Args);

    const UINTN BufferSize = 512;
    CHAR16 *Buffer = AllocatePool(SysTab, BufferSize * sizeof(CHAR16));
    if (!Buffer) return;

    CHAR16 *Pointer = Buffer;
    const CHAR16 *BufferEnd = Buffer + BufferSize - 1;

    while (*Format && Pointer < BufferEnd) {
        if (*Format != L'%') {
            *Pointer++ = *Format++;
            continue;
        }

        // Handle format specifier
        Format++;  // Skip '%'
        if (!*Format) break;  // Prevent overflow on malformed string

        ProcessSpecifier(*Format, &Args, &Pointer, BufferEnd);
        Format++;
    }

    *Pointer = L'\0';
    SysTab->ConsoleOutput->OutputString(SysTab->ConsoleOutput,Buffer);
    FreePool(SysTab, Buffer);
    VA_END(Args);
}

[[noreturn]] void HaltSystem(EFI_SYSTEM_TABLE *SysTab, const CHAR16 *Format, ...){
    VA_LIST Args;
    VA_START(Args);

    Output(SysTab,L"\n%s ",EFI_ERROR_HANDLER);
    Output(SysTab,Format,Args);
    Output(SysTab,L"\nShutting down in 5 seconds.\r\n");

    SysTab->BootServices->Stall(5000000);
    SysTab->RuntimeServices->ResetSytem(EfiResetShutdown,1,0,NULL);

    for(;;)__asm__("hlt");
}
