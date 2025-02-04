//
// Made by Gab Rivas 01/02/25
//

#include "../lib/efi.h"
#include "../lib/efi_dependencies.h"

#define BOOT_CONFIG_PATH    L"\\BOOT\\boot.config"

typedef struct {
    CHAR16 *SecondStage;
    CHAR16 *FallbackStage;
    UINTN  TriggerSelection;
} BOOT_CONFIG;

EFI_STATUS efiApi(EFI_SYSTEM_TABLE *SysTab, EFI_HANDLE ImageHandle){

    while (1); //Debug purposes
    return 0;
}
