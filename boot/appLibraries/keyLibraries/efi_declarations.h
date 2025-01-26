//
// Made by Gab Rivas 24/01/25 23:10
//
// File containing all EFI declarations that might be useful at some point
//

#ifndef EFI_DECLARATIONS_H
#define EFI_DECLARATIONS_H

// UEFI IMAGES

// PE32+ Subsystem type for EFI images
#define EFI_IMAGE_SUBSYSTEM_EFI_APPLICATION          10
#define EFI_IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11
#define EFI_IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER       12
// PE32+ Machine type for EFI images
#define EFI_IMAGE_MACHINE_IA32                       0x014c
#define EFI_IMAGE_MACHINE_IA64                       0x0200
#define EFI_IMAGE_MACHINE_EBC                        0x0EBC
#define EFI_IMAGE_MACHINE_x64                        0x8664
#define EFI_IMAGE_MACHINE_ARMTHUMB_MIXED             0x01C2
#define EFI_IMAGE_MACHINE_AARCH64                    0xAA64
#define EFI_IMAGE_MACHINE_RISCV32                    0x5032
#define EFI_IMAGE_MACHINE_RISCV64                    0x5064
#define EFI_IMAGE_MACHINE_RISCV128                   0x5128
#define EFI_IMAGE_MACHINE_LOONGARCH32                0x6232
#define EFI_IMAGE_MACHINE_LOONGARCH64                0x6264

// EFI_LOAD_OPTION
// All values 0x00000200-0x00001F00 are reserved

#define LOAD_OPTION_ACTIVE                0x00000001
#define LOAD_OPTION_FORCE_RECONNECT       0x00000002
#define LOAD_OPTION_HIDDEN                0x00000008
#define LOAD_OPTION_CATEGORY              0x00001F00

#define LOAD_OPTION_CATEGORY_BOOT         0x00000000
#define LOAD_OPTION_CATEGORY_APP          0x00000100

// Boot manager capabilities
#define EFI_BOOT_OPTION_SUPPORT_KEY         0x00000001
#define EFI_BOOT_OPTION_SUPPORT_APP         0x00000002
#define EFI_BOOT_OPTION_SUPPORT_SYSPREP     0x00000010
#define EFI_BOOT_OPTION_SUPPORT_COUNT       0x00000300

// Boot manager policies
#define EFI_BOOT_MANAGER_POLICY_CONSOLE_GUID \
   { 0xCAB0E94C, 0xE15F, 0x11E3,\
   { 0x91, 0x8D, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }
#define EFI_BOOT_MANAGER_POLICY_NETWORK_GUID \
   { 0xD04159DC, 0xE15F, 0x11E3,\
   { 0xB2, 0x61, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }
#define EFI_BOOT_MANAGER_POLICY_STORAGE_GUID \
   { 0xCD68FE79, 0xD3CB, 0x436E,\
   { 0xA8, 0x50, 0xF4, 0x43, 0xC8, 0x8C, 0xFB, 0x49 } }
#define EFI_BOOT_MANAGER_POLICY_CONNECT_ALL_GUID \
   { 0x113B2126, 0xFC8A, 0x11E3,\
     { 0xBD, 0x6C, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }

// EFI Global Variable
#define EFI_GLOBAL_VARIABLE \
 {0x8BE4DF61,0x93CA,0x11d2,\
   {0xAA,0x0D,0x00,0xE0,0x98,0x03,0x2B,0x8C}}

#endif
