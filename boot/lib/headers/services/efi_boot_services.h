//
// Made by Gab Rivas 01/02/25 16:39
//

#ifndef EFI_BOOT_SERVICES_H
#define EFI_BOOT_SERVICES_H

#include "../memory/efi_allocate_type.h"
#include "../core/efi_core.h"
#include "../protocols/efi_device_path_protocol.h"
#include "../services/efi_event_notify.h"
#include "../core/efi_interface_type.h"
#include "../services/efi_locate_search_type.h"
#include "../memory/efi_memory_descriptor.h"
#include "../memory/efi_memory_type.h"
#include "../protocols/efi_open_protocol_information_entry.h"
#include "../core/efi_table_header.h"
#include "../time/efi_timer_delay.h"

// Event Services
typedef EFI_STATUS(EFIAPI *EFI_CREATE_EVENT)(
    IN UINT32                                   Type,
    IN EFI_TPL                                  NotifyTPL,
    IN EFI_EVENT_NOTIFY                         NotifyFunction OPTIONAL,
    IN VOID                                    *NotifyContext OPTIONAL,
    OUT EFI_EVENT                              *Event
);

typedef EFI_STATUS(EFIAPI *EFI_CREATE_EVENT_EX)(
    IN UINT32                                   Type,
    IN EFI_TPL                                  NotifyTPL,
    IN EFI_EVENT_NOTIFY                         NotifyFunction OPTIONAL,
    IN CONST VOID                               *NotifyContext OPTIONAL,
    IN CONST EFI_GUID                           *EventGroup OPTIONAL,
    OUT EFI_EVENT                               *Event
);

typedef EFI_STATUS(EFIAPI *EFI_CLOSE_EVENT)(
    IN EFI_EVENT                                Event
);

typedef EFI_STATUS(EFIAPI *EFI_SIGNAL_EVENT)(
    IN EFI_EVENT                                Event
);

typedef EFI_STATUS(EFIAPI *EFI_WAIT_FOR_EVENT)(
    IN UINTN                                    NumberOfEvents,
    IN EFI_EVENT                               *Event,
    OUT UINTN                                  *Index
);

typedef EFI_STATUS(EFIAPI *EFI_CHECK_EVENT)(
    IN EFI_EVENT                                Event
);

// Time Services
typedef EFI_STATUS(EFIAPI *EFI_SET_TIMER)(
    IN EFI_EVENT                                Event,
    IN EFI_TIMER_DELAY                          Type,
    IN UINT64                                   TriggerTime
);

// Task Priority Services
typedef EFI_TPL(EFIAPI *EFI_RAISE_TPL)(
    IN EFI_TPL                                  NewTPL
);

typedef VOID(EFIAPI *EFI_RESTORE_TPL)(
    IN EFI_TPL                                  OldTPL
);

// Paging memory Services
typedef EFI_STATUS(EFIAPI *EFI_ALLOCATE_PAGES)(
    IN EFI_ALLOCATE_TYPE                        Type,
    IN EFI_MEMORY_TYPE                          MemoryType,
    IN UINTN                                    Pages,
    IN OUT EFI_PHYSICAL_ADDRESS                *Memory
);

typedef EFI_STATUS(EFIAPI *EFI_FREE_PAGES)(
    IN EFI_PHYSICAL_ADDRESS                     Memory,
    IN UINTN                                    Pages
);

// Memory Services
typedef EFI_STATUS(EFIAPI *EFI_GET_MEMORY_MAP)(
    IN OUT UINTN                               *MemoryMapSize,
    OUT EFI_MEMORY_DESCRIPTOR                  *MemoryMap,
    OUT UINTN                                  *DescriptorSize,
    OUT UINT32                                 *DescriptorVersion
);

// Pool Memory Services
typedef EFI_STATUS(EFIAPI *EFI_ALLOCATE_POOL)(
    IN EFI_MEMORY_TYPE                          PoolType,
    IN UINTN                                    Size,
    OUT VOID                                  **Buffer
);

typedef EFI_STATUS(EFIAPI *EFI_FREE_POOL)(
    IN VOID                                    *Buffer
);

// Protocol Services
typedef EFI_STATUS(EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE)(
    IN OUT EFI_HANDLE                          *Handle,
    IN EFI_GUID                                *Protocol,
    IN EFI_INTERFACE_TYPE                       InterfaceType,
    IN VOID                                    *Interface
);

typedef EFI_STATUS(EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE)(
    IN EFI_HANDLE                               Handle,
    IN EFI_GUID                                *Protocol,
    IN VOID                                    *Interface
);

typedef EFI_STATUS(EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE)(
    IN EFI_HANDLE                               Handle,
    IN EFI_GUID                                *Protocol,
    IN VOID                                    *OldInterface,
    IN VOID                                    *NewInterface
);

typedef EFI_STATUS(EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY)(
    IN EFI_GUID                                *Protocol,
    IN EFI_EVENT                                Event,
    OUT VOID                                  **Registration
);

typedef EFI_STATUS(EFIAPI *EFI_LOCATE_HANDLE)(
    EFI_LOCATE_SEARCH_TYPE                      SearchType,
    IN EFI_GUID                                *Protocol OPTIONAL,
    IN VOID                                    *SearchKey OPTIONAL,
    IN OUT UINTN                               *BufferSize,
    OUT EFI_HANDLE                             *Buffer
);

typedef EFI_STATUS(EFIAPI *EFI_HANDLE_PROTOCOL)(
    IN EFI_HANDLE                               Handle,
    IN EFI_GUID                                *Protocol,
    OUT VOID                                  **Interface
);

typedef EFI_STATUS(EFIAPI *EFI_LOCATE_DEVICE_PATH)(
    IN EFI_GUID                                *Protocol,
    IN OUT EFI_DEVICE_PATH_PROTOCOL           **DevicePath,
    OUT EFI_HANDLE                              *Device
);

typedef EFI_STATUS(EFIAPI *EFI_OPEN_PROTOCOL)(
    IN EFI_HANDLE                               Handle,
    IN EFI_GUID                                *Protocol,
    OUT VOID                                  **Interface,
    IN EFI_HANDLE                               AgentHandle,
    IN EFI_HANDLE                               ControllerHandle,
    IN UINT32                                   Attributes
);

typedef EFI_STATUS(EFIAPI *EFI_CLOSE_PROTOCOL)(
    IN EFI_HANDLE                               Handle,
    IN EFI_GUID                                *Protocol,
    IN EFI_HANDLE                               AgentHandle,
    IN EFI_HANDLE                               ControllerHandle
);

typedef EFI_STATUS(EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION)(
    IN EFI_HANDLE                               Handle,
    IN EFI_GUID                                *Protocol,
    OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY   **EntryBuffer,
    OUT UINTN                                  *EntryCount
);

typedef EFI_STATUS(EFIAPI *EFI_CONNECT_CONTROLLER)(
    IN EFI_HANDLE                               ControllerHandle,
    IN EFI_HANDLE                              *DriverImageHandle OPTIONAL,
    IN EFI_DEVICE_PATH_PROTOCOL                *RemainingDevicePath OPTIONAL,
    IN BOOLEAN                                  Recursive
);

typedef EFI_STATUS(EFIAPI *EFI_DISCONNECT_CONTROLLER)(
    IN EFI_HANDLE                               ControllerHandle,
    IN EFI_HANDLE                               DriverImageHandle OPTIONAL,
    IN EFI_HANDLE                               ChildHandle OPTIONAL
);

typedef EFI_STATUS(EFIAPI *EFI_PROTOCOLS_PER_HANDLE)(
    IN EFI_HANDLE                               Handle,
    OUT EFI_GUID                             ***ProtocolBuffer,
    OUT UINTN                                  *ProtocolBufferCount
);

typedef EFI_STATUS(EFIAPI *EFI_LOCATE_HANDLE_BUFFER)(
    IN EFI_LOCATE_SEARCH_TYPE                   SearchType,
    IN EFI_GUID                                *Protocol OPTIONAL,
    IN VOID                                    *SearchKey OPTIONAL,
    OUT UINTN                                  *NoHandles,
    OUT EFI_HANDLE                            **Buffer
);

typedef EFI_STATUS(EFIAPI *EFI_LOCATE_PROTOCOL)(
    IN EFI_GUID                                 *Protocol,
    IN VOID                                     *Registration OPTIONAL,
    OUT VOID                                   **Interface
);

typedef EFI_STATUS(EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES)(
    IN OUT EFI_HANDLE                           *Handle,
    ...
);

typedef EFI_STATUS(EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(
    IN EFI_HANDLE                                Handle,
    ...
);

typedef EFI_STATUS(EFIAPI *EFI_IMAGE_LOAD)(
    IN BOOLEAN                                   BootPolicy,
    IN EFI_HANDLE                                ParentImageHandle,
    IN EFI_DEVICE_PATH_PROTOCOL                 *DevicePath OPTIONAL,
    IN VOID                                     *SourceBuffer OPTIONAL,
    IN UINTN                                     SourceSize,
    OUT EFI_HANDLE                              *ImageHandle
);

typedef EFI_STATUS(EFIAPI *EFI_IMAGE_START)(
    IN EFI_HANDLE                                ImageHandle,
    OUT UINTN                                   *ExitDataSize,
    OUT CHAR16                                 **ExitData OPTIONAL
);

typedef EFI_STATUS(EFIAPI *EFI_IMAGE_UNLOAD)(
    IN EFI_HANDLE                                ImageHandle
);

typedef EFI_STATUS(EFIAPI *EFI_EXIT)(
    IN EFI_HANDLE                                ImageHandle,
    IN EFI_STATUS                                ExitStatus,
    IN UINTN                                     ExitDataSize,
    IN CHAR16                                   *ExitData OPTIONAL
);

typedef EFI_STATUS(EFIAPI *EFI_EXIT_BOOT_SERVICES)(
    IN EFI_HANDLE                                ImageHandle,
    IN UINTN                                     MapKey
);

typedef EFI_STATUS(EFIAPI *EFI_SET_WATCHDOG_TIMER)(
    IN UINTN                                     Timeout,
    IN UINT64                                    WatchdogCode,
    IN UINTN                                     DataSize,
    IN CHAR16                                   *WatchdogData OPTIONAL
);

typedef EFI_STATUS(EFIAPI *EFI_STALL)(
    IN UINTN                                     Microseconds
);

typedef EFI_STATUS(EFIAPI *EFI_COPY_MEM)(
    IN VOID                                     *Destination,
    IN VOID                                     *Source,
    IN UINTN                                     Length
);

typedef EFI_STATUS(EFIAPI *EFI_SET_MEM)(
    IN VOID                                     *Buffer,
    IN UINTN                                     Size,
    IN UINT8                                     Value
);

typedef EFI_STATUS(EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT)(
    OUT UINT64                                  *Count
);

typedef EFI_STATUS(EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE)(
    IN EFI_GUID                                 *GUID,
    IN VOID                                     *Table
);

typedef EFI_STATUS(EFIAPI *EFI_CALCULATE_CRC32)(
    IN VOID                                     *Data,
    IN UINTN                                     DataSize,
    OUT UINT32                                  *CRC32
);

typedef struct {
    EFI_TABLE_HEADER                                Header;

    // TPL
    EFI_RAISE_TPL                                   RaiseTPL;
    EFI_RESTORE_TPL                                 RestoreTPL;

    // Mem Svcs
    EFI_ALLOCATE_PAGES                              AllocatePages;
    EFI_FREE_PAGES                                  FreePages;
    EFI_GET_MEMORY_MAP                              GetMemoryMap;
    EFI_ALLOCATE_POOL                               AllocatePool;
    EFI_FREE_POOL                                   FreePool;

    // Event & Timer svcs
    EFI_CREATE_EVENT                                CreateEvent;
    EFI_SET_TIMER                                   SetTimer;
    EFI_WAIT_FOR_EVENT                              WaitForEvent;
    EFI_SIGNAL_EVENT                                SignalEvent;
    EFI_CLOSE_EVENT                                 CloseEvent;
    EFI_CHECK_EVENT                                 CheckEvent;

    // Protocol Handler Svcs
    EFI_INSTALL_PROTOCOL_INTERFACE                  InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE                ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE                UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL                             HandleProtocol;
    VOID                                            *Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY                    RegisterProtocolNotify;
    EFI_LOCATE_HANDLE                               LocateHandle;
    EFI_LOCATE_DEVICE_PATH                          LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE                 InstallConfigurationTable;

    // Image Services
    EFI_IMAGE_LOAD                                  LoadImage;
    EFI_IMAGE_START                                 StartImage;
    EFI_EXIT                                        Exit;
    EFI_IMAGE_UNLOAD                                UnloadImage;
    EFI_EXIT_BOOT_SERVICES                          ExitBootServices;

    // Misc
    EFI_GET_NEXT_MONOTONIC_COUNT                    GetNextMonotonicCount;
    EFI_STALL                                       Stall;
    EFI_SET_WATCHDOG_TIMER                          SetWatchdogTimer;

    // Driver Support
    EFI_CONNECT_CONTROLLER                          ConnectController;
    EFI_DISCONNECT_CONTROLLER                       DisconnectController;

    // Open and Close Protocols svcs
    EFI_OPEN_PROTOCOL                               OpenProtocol;
    EFI_CLOSE_PROTOCOL                              CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION                   OpenProtocolInformation;

    // Lib Services
    EFI_PROTOCOLS_PER_HANDLE                        ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER                        LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL                             LocateProtocol;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES      InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES      UninstallMultipleProtocolInterfaces;

    EFI_CALCULATE_CRC32                             CalculateCRC32;

    // Misc Svcs
    EFI_COPY_MEM                                    CopyMem;
    EFI_SET_MEM                                     SetMem;
    EFI_CREATE_EVENT_EX                             CreateEventEx;
} EFI_BOOT_SERVICES;

#endif //EFI_BOOT_SERVICES_H
