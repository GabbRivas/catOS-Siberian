//
// Made by Gab Rivas 31/01/25 23:35
//

#ifndef EFI_SIMPLE_TEXT_INPUT_PROTOCOL_H
#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_H

#include "../core/efi_core.h"
#include "../input/efi_input_key.h"

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID \
 {0x387477c1,0x69c7,0x11d2,\
  {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef EFI_STATUS(EFIAPI *EFI_INPUT_RESET)(
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL       *This,
    IN BOOLEAN                               ExtendedVerification
);

typedef EFI_STATUS(EFIAPI *EFI_INPUT_READ_KEY)(
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL       *This,
    OUT EFI_INPUT_KEY                       *Key
);

#endif
