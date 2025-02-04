//
// Made by Gab Rivas 01/02/25
//

#include "../lib/efi.h"
#include "../lib/efi_dependencies.h"

#define BOOT_CONFIG_PATH    L"\\BOOT\\boot.config"
#define MAX_PATH_LEN 128

typedef struct {
    CHAR16 SecondStage;
    CHAR16 FallbackStage;
    UINTN  TriggerSelection;
} BOOT_CONFIG;

EFI_STATUS efiApi(IN EFI_HANDLE ImgHdl, IN EFI_SYSTEM_TABLE *SysTab){
    InitApplicationServices(SysTab);

    Sys->ConsoleOutput->ClearScreen(Sys->ConsoleOutput); //Debug purposes for clarity

    EFI_FILE_PROTOCOL   *Root;
    EFI_STATUS Status=FileOpenRoot(&Root);
    if(EFI_ERROR(Status)){
        Print(L"Unable to open root volume, check volume integrity.\n\r");
    }

    EFI_FILE_PROTOCOL   *File;
    Status=FileOpen(Root, BOOT_CONFIG_PATH, &File);
    if(EFI_ERROR(Status)){
        Print(L"%s\n\r",EFI_ERROR_HANDLER);
        Print(L"   Unable to retrieve %s\n\r",BOOT_CONFIG_PATH);
        Print(L"   Check file integrity, volume integrity and file existance.\n\r");
    }



    while(1); //Debug purposes loop;
    return 0;
}
