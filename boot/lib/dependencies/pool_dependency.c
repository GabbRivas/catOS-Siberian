//
// Made by Gab Rivas 02/02/25 11:05
//

#include "pool_dependency.h"

void *AllocatePool(EFI_SYSTEM_TABLE *SysTab, UINTN Size){
    void *Buffer = NULL;

    EFI_STATUS Status=SysTab->BootServices->AllocatePool(EfiLoaderData, Size, &Buffer);
    if (EFI_ERROR(Status)){
        SysTab->ConsoleOutput->OutputString(SysTab->ConsoleOutput,L"[ERROR HANDLER] EFI Memory Allocation failed.");
    }

    return Buffer;
}

void FreePool(EFI_SYSTEM_TABLE *SysTab, void *Buffer){
    EFI_STATUS Status = SysTab->BootServices->FreePool(Buffer);
    if (EFI_ERROR(Status)){
        SysTab->ConsoleOutput->OutputString(SysTab->ConsoleOutput,L" [ERROR HANDLER] Unable to free memory pool.");
    }
}
