//
// Made by Gab Rivas 26/01/25 11:37
//

#ifndef EFI_SYSTEM_TABLE_H
#define EFI_SYSTEM_TABLE_H

#include "efi_base_lib.h"
#include "efi_configuration_table.h"
#include "efi_runtime_services.h"
#include "efi_table_header.h"
#include "efi_simple_text_input_protocol.h"
#include "efi_simple_text_output_protocol.h"
#include "efi_boot_services.h"
#include "keyLibraries/efi_data_types.h"

typedef struct {
    EFI_TABLE_HEADER                    Header;
    CHAR16                             *FirmwareVendor;
    UINT32                              FirmwareRevision;
    EFI_HANDLE                          ConsoleInputHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL     *ConsoleInput;
    EFI_HANDLE                          ConsoleOutputHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL    *ConsoleOutput;
    EFI_HANDLE                          StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL    *StandardError;
    EFI_RUNTIME_SERVICES               *RuntimeServices;
    EFI_BOOT_SERVICES                  *BootServices;
    UINTN                               NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE            *ConfigurationTable;

} EFI_SYSTEM_TABLE;

#endif
