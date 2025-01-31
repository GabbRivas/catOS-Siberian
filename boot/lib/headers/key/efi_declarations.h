//
// Made by Gab Rivas 30/01/25 22:36
//
// Library consisting of efi define declarations present in the
// UEFI specs
//

#include "efi_data_types.h"

#ifndef EFI_DECLARATIONS_H
#define EFI_DECLARATIONS_H

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

#endif
