//
// Made by Gab Rivas 01/02/25
//

#include "../lib/efi.h"
#include "../lib/efi_dependencies.h"

EFI_STATUS efiApi(IN EFI_HANDLE ImgHdl, IN EFI_SYSTEM_TABLE *SysTab){
    (void)ImgHdl;

    Output(SysTab, L"[Boot Manager] EFI app Loaded.");

    Output(SysTab, L"");

    while(1); //Infinite loop to debug

    return 0;
}
