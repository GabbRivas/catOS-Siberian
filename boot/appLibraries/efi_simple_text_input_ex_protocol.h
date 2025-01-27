//
// Made by Gab Rivas 25/01/25 10:33
//

#ifndef EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL_H
#define EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL_H

#include "efi_base_lib.h"
#include "efi_key_data.h"
#include "efi_key_notify.h"
#include "keyLibraries/efi_data_types.h"

#define EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL_GUID \
 {0xdd9e7534, 0x7762, 0x4698, \
  {0x8c, 0x14, 0xf5, 0x85, 0x17, 0xa6, 0x25, 0xaa}}

typedef struct _EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL;

typedef EFI_STATUS(EFIAPI *EFI_INPUT_RESET_EX)(
    IN EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL        *This,
    IN BOOLEAN                                   ExtendedVerification
);

typedef EFI_STATUS(EFIAPI *EFI_INPUT_READ_KEY_EX)(
    IN EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL        *This,
    OUT EFI_KEY_DATA                            *KeyData
);

typedef EFI_STATUS(EFIAPI *EFI_SET_STATE)(
    IN EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL        *This,
    IN EFI_KEY_TOGGLE_STATE                     *KeyToggleState
);

typedef EFI_STATUS(EFIAPI *EFI_REGISTER_KEYSTROKE_NOTIFY)(
    IN EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL        *This,
    IN EFI_KEY_DATA                             *KeyData,
    IN EFI_KEY_NOTIFY_FUNCTION                   KeyNotificationFunction,
    OUT VOID                                   **NotifyHandle
);

typedef EFI_STATUS(EFIAPI *EFI_UNREGISTER_KEYSTROKE_NOTIFY)(
    IN EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL        *This,
    IN VOID                                     *NotificationHandle
);

struct _EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL{
    EFI_INPUT_RESET_EX                           Reset;
    EFI_INPUT_READ_KEY_EX                        ReadKeyStrokeEx;
    EFI_EVENT                                    WaitForKeyEx;
    EFI_SET_STATE                                SetState;
    EFI_REGISTER_KEYSTROKE_NOTIFY                RegisterKeyNotify;
    EFI_UNREGISTER_KEYSTROKE_NOTIFY              UnregisterKeyNotify;
};

#endif
