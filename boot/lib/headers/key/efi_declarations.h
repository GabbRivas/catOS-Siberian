//
// Made by Gab Rivas 30/01/25 22:36
//
// Library consisting of efi define declarations present in the
// UEFI specs
//

#ifndef EFI_DECLARATIONS_H
#define EFI_DECLARATIONS_H

#include "efi_data_types.h"

// PE32+ Subsystem types for EFI images
#define EFI_IMAGE_SUBSYSTEM_EFI_APPLICATION          10  // EFI application
#define EFI_IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11  // Boot service driver
#define EFI_IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER       12  // Runtime driver

// PE32+ Machine types for EFI images
#define EFI_IMAGE_MACHINE_IA32                       0x014c  // IA-32
#define EFI_IMAGE_MACHINE_IA64                       0x0200  // IA-64
#define EFI_IMAGE_MACHINE_EBC                        0x0EBC  // EFI Byte Code
#define EFI_IMAGE_MACHINE_x64                        0x8664  // x86-64
#define EFI_IMAGE_MACHINE_ARMTHUMB_MIXED             0x01C2  // ARM (mixed Thumb/ARM)
#define EFI_IMAGE_MACHINE_AARCH64                    0xAA64  // AArch64
#define EFI_IMAGE_MACHINE_RISCV32                    0x5032  // RISC-V 32-bit
#define EFI_IMAGE_MACHINE_RISCV64                    0x5064  // RISC-V 64-bit
#define EFI_IMAGE_MACHINE_RISCV128                   0x5128  // RISC-V 128-bit
#define EFI_IMAGE_MACHINE_LOONGARCH32                0x6232  // LoongArch 32-bit
#define EFI_IMAGE_MACHINE_LOONGARCH64                0x6264  // LoongArch 64-bit

// Global Variable GUID
#define EFI_GLOBAL_VARIABLE \
  {0x8BE4DF61, 0x93CA, 0x11d2, \
   {0xAA, 0x0D, 0x00, 0xE0, 0x98, 0x03, 0x2B, 0x8C}}

// Removable media file names for different architectures
#define EFI_REMOVABLE_MEDIA_FILE_NAME_IA32         L"\\EFI\\BOOT\\BOOTIA32.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_IA64         L"\\EFI\\BOOT\\BOOTIA64.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_X64          L"\\EFI\\BOOT\\BOOTX64.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_ARM          L"\\EFI\\BOOT\\BOOTARM.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64      L"\\EFI\\BOOT\\BOOTAA64.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_RISCV64      L"\\EFI\\BOOT\\BOOTRISCV64.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_LOONGARCH64  L"\\EFI\\BOOT\\BOOTLOONGARCH64.EFI"

#endif // EFI_DECLARATIONS_H