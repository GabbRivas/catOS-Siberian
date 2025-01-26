//
// Made by Gab Rivas 25/01/25 14:20
//

#ifndef EFI_BOOT_MANAGER_POLICY_PROTOCOL_H
#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_H

#include "efi_base_lib.h"
#include "efi_device_path_protocol.h"

#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_REVISION 0x00010000
#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_GUID \
  { 0xFEDF8E0C, 0xE147, 0x11E3,\
  { 0x99, 0x03, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }

  typedef struct _EFI_BOOT_MANAGER_POLICY_PROTOCOL EFI_BOOT_MANAGER_POLICY_PROTOCOL;

  typedef EFI_STATUS(EFIAPI *EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_PATH)(
      IN EFI_BOOT_MANAGER_POLICY_PROTOCOL           *This,
      IN EFI_DEVICE_PATH_PROTOCOL                   *DevicePath,
      IN BOOLEAN                                     Recursive
  );

  typedef EFI_STATUS(EFIAPI *EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_CLASS)(
      IN EFI_BOOT_MANAGER_POLICY_PROTOCOL           *This,
      IN EFI_GUID                                   *Class
  );

  struct _EFI_BOOT_MANAGER_POLICY_PROTOCOL{
      UINT64                                            Revision;
      EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_PATH       ConnectDevicePath;
      EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_CLASS      ConnectDeviceClass;
  };

#endif
