//
// Made by Gab Rivas 01/01/25 14:53
//

#ifndef EFI_RUNTIME_SERVICES_H
#define EFI_RUNTIME_SERVICES_H

#include "../capsule/efi_capsule_header.h"
#include "../core/efi_core.h"
#include "../memory/efi_memory_descriptor.h"
#include "../core/efi_reset_type.h"
#include "../core/efi_table_header.h"
#include "../time/efi_time.h"
#include "../time/efi_time_capabilities.h"

typedef struct _EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

// Variable Functions
typedef EFI_STATUS(EFIAPI *EFI_GET_VARIABLE)(
    IN CHAR16                   *VariableName,
    IN EFI_GUID                 *VendorGUID,
    OUT UINT32                  *Attributes OPTIONAL,
    IN OUT UINTN                *DataSize,
    OUT VOID                    *Data OPTIONAL
);

typedef EFI_STATUS(EFIAPI *EFI_GET_NEXT_VARIABLE_NAME)(
    IN OUT UINTN                *VariableNameSize,
    IN OUT CHAR16               *VariableName,
    IN OUT EFI_GUID             *VendorGUID
);

typedef EFI_STATUS(EFIAPI *EFI_SET_VARIABLE)(
    IN CHAR16                   *VariableName,
    IN EFI_GUID                 *VendorGUID,
    IN UINT32                    Attributes,
    IN UINTN                     DataSize,
    IN VOID                     *Data
);

typedef EFI_STATUS(EFIAPI *EFI_QUERY_VARIABLE_INFO)(
    IN UINT32                    Attributes,
    OUT UINT64                  *MaximumVariableStorageSize,
    OUT UINT64                  *RemainingVariableStorageSize,
    OUT UINT64                  *MaximumVariableSize
);

// Time Functions
typedef EFI_STATUS(EFIAPI *EFI_GET_TIME)(
    OUT EFI_TIME                *Time,
    OUT EFI_TIME_CAPABILITIES   *Capabilities OPTIONAL
);

typedef EFI_STATUS(EFIAPI *EFI_SET_TIME)(
    IN EFI_TIME                 *Time
);

typedef EFI_STATUS(EFIAPI *EFI_GET_WAKEUP_TIME)(
    OUT BOOLEAN                 *Enabled,
    OUT BOOLEAN                 *Pending,
    OUT EFI_TIME                *Time
);

typedef EFI_STATUS(EFIAPI *EFI_SET_WAKEUP_TIME)(
    IN BOOLEAN                   Enable,
    IN EFI_TIME                 *Time OPTIONAL
);

// Virtual Memory Services
typedef EFI_STATUS(EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP)(
    IN UINTN                     MemoryMapSize,
    IN UINTN                     DescriptorSize,
    IN UINT32                    DescriptorVersion,
    IN EFI_MEMORY_DESCRIPTOR    *VirtualMap
);

typedef EFI_STATUS(EFIAPI *EFI_CONVERT_POINTER)(
    IN UINTN                     DebugDisposition,
    IN VOID                    **Address
);

// Miscellaneous Functions
typedef VOID(EFIAPI *EFI_RESET_SYSTEM)(
    IN EFI_RESET_TYPE            ResetType,
    IN EFI_STATUS                ResetStatus,
    IN UINTN                     DataSize,
    IN VOID                     *ResetData OPTIONAL
);

typedef EFI_STATUS(EFIAPI *EFI_GET_NEXT_MONO_C)(
    OUT UINT32                  *HighCount
);

typedef EFI_STATUS(EFIAPI *EFI_UPDATE_CAPSULE)(
    IN EFI_CAPSULE_HEADER      **CapsuleHeaderArray,
    IN UINTN                     CapsuleCount,
    IN EFI_PHYSICAL_ADDRESS      ScatterGatherList OPTIONAL
);

typedef EFI_STATUS(EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES)(
    IN EFI_CAPSULE_HEADER     **CapsuleHeaderArray,
    IN UINTN                    CapsuleCount,
    OUT UINT64                 *MaximumCapsuleSize,
    OUT EFI_RESET_TYPE         *ResetType
);

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

struct _EFI_RUNTIME_SERVICES{
    EFI_TABLE_HEADER                Header;

    // Time Services
    EFI_GET_TIME                    GetTime;
    EFI_SET_TIME                    SetTime;
    EFI_GET_WAKEUP_TIME             GetWakeupTime;
    EFI_SET_WAKEUP_TIME             SetWakeupTime;

    // Virtual Memory Services
    EFI_GET_VARIABLE                GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME      GetNextVariableName;
    EFI_SET_VARIABLE                SetVariable;

    // Misc Services
    EFI_GET_NEXT_MONO_C             GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM                ResetSytem;

    // UEFI 2.0 Capsule Svcs
    EFI_UPDATE_CAPSULE              UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES  QueryCapsuleCapabilities;

    // Misc UEFI 2.0 Svcs
    EFI_QUERY_VARIABLE_INFO         QueryVariableInfo;
};

// Var Attributes
#define EFI_VARIABLE_NON_VOLATILE                           0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS                     0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS                         0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD                  0x00000008
// Reserved
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS  0x00000020
#define EFI_VARIABLE_APPEND_WRITE                           0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS          0x00000080

#endif
