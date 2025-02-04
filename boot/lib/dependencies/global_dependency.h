//
// Made by Gab Rivas 03/02/25 15:40
//

#ifndef GLOBAL_DEPENDENCY_H
#define GLOBAL_DEPENDENCY_H

#include "../efi.h"

// Declare GUIDS:
extern EFI_GUID EfiBootManagerPolicyProtocolGUID;
extern EFI_GUID EfiDevicePathProtocolGUID;
extern EFI_GUID EfiSimpleFileSystemProtocolGUID;
extern EFI_GUID EfiSimpleTextInputExProtocolGUID;
extern EFI_GUID EfiSimpleTextInputProtocolGUID;
extern EFI_GUID EfiSimpleTextOutputProtocolGUID;
extern EFI_GUID EfiFileInfoID;

// Declaring of all global variables
extern EFI_SYSTEM_TABLE         *Sys;
extern EFI_BOOT_SERVICES        *Bsvc;
extern EFI_RUNTIME_SERVICES     *Rsvc;

VOID InitApplicationServices(EFI_SYSTEM_TABLE *SysTab);

#endif
