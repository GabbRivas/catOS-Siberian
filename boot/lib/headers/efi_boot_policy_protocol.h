/*
 * Made by Gab Rivas 31/01/25 12:50
 *
 * EFI Boot Manager Policy Protocol
 */

#ifndef EFI_BOOT_POLICY_PROTOCOL_H
#define EFI_BOOT_POLICY_PROTOCOL_H

#include "efi_core.h"
#include "efi_device_path_protocol.h"

// Protocol revision
#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_REVISION 0x00010000

// Protocol GUID
#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_GUID \
  { 0xFEDF8E0C, 0xE147, 0x11E3, \
    { 0x99, 0x03, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }

// Forward declaration of the protocol structure
typedef struct _EFI_BOOT_POLICY_PROTOCOL EFI_BOOT_MANAGER_POLICY_PROTOCOL;

// Function pointer types
typedef EFI_STATUS(EFIAPI *EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_PATH)(
    IN EFI_BOOT_MANAGER_POLICY_PROTOCOL *This,
    IN EFI_DEVICE_PATH_PROTOCOL         *DevicePath,
    IN BOOLEAN                          Recursive
);

typedef EFI_STATUS(EFIAPI *EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_CLASS)(
    IN EFI_BOOT_MANAGER_POLICY_PROTOCOL *This,
    IN EFI_GUID                         *Class
);

// Protocol Structure
struct _EFI_BOOT_POLICY_PROTOCOL {
    UINT64                                         Revision;
    EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_PATH    ConnectDevicePath;
    EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_CLASS   ConnectDeviceClass;
};

// BOOT MANAGER CAPABILITIES
#define EFI_BOOT_OPTION_SUPPORT_KEY         0x00000001
#define EFI_BOOT_OPTION_SUPPORT_APP         0x00000002
#define EFI_BOOT_OPTION_SUPPORT_SYSPREP     0x00000010
#define EFI_BOOT_OPTION_SUPPORT_COUNT       0x00000300

#define EFI_BOOT_MANAGER_POLICY_CONSOLE_GUID \
   { 0xCAB0E94C, 0xE15F, 0x11E3, \
   { 0x91, 0x8D, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }

#define EFI_BOOT_MANAGER_POLICY_NETWORK_GUID \
   { 0xD04159DC, 0xE15F, 0x11E3, \
   { 0xB2, 0x61, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }

#define EFI_BOOT_MANAGER_POLICY_STORAGE_GUID \
   { 0xCD68FE79, 0xD3CB, 0x436E, \
   { 0xA8, 0x50, 0xF4, 0x43, 0xC8, 0x8C, 0xFB, 0x49 } }

#define EFI_BOOT_MANAGER_POLICY_CONNECT_ALL_GUID \
   { 0x113B2126, 0xFC8A, 0x11E3, \
   { 0xBD, 0x6C, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }

#endif // EFI_BOOT_POLICY_PROTOCOL_H