//
// Made by Gab Rivas 25/01/25 23:04
//

#ifndef EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_H
#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_H

#include "efi_base_lib.h"
#include "simple_text_output_mode.h"

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID \
 {0x387477c2,0x69c7,0x11d2,\
  {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS(EFIAPI *EFI_TEXT_RESET)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
    IN BOOLEAN                                   ExtendedVerification
);

typedef EFI_STATUS(EFIAPI *EFI_TEXT_STRING)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
    IN CHAR16                                   *String
);

typedef EFI_STATUS(EFIAPI *EFI_TEXT_TEST_STRING)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
    IN CHAR16                                   *String
);

typedef EFI_STATUS(EFIAPI *EFI_TEXT_QUERY_MODE)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
    IN UINTN                                     ModeNumber,
    OUT UINTN                                   *Columns,
    OUT UINTN                                   *Rows
);

typedef EFI_STATUS(*EFIAPI EFI_TEXT_SET_MODE)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
    IN UINTN                                     ModeNumber
);

typedef EFI_STATUS(EFIAPI *EFI_TEXT_SET_ATTRIBUTE)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
    IN UINTN                                     Attribute
);

typedef EFI_STATUS(EFIAPI *EFI_TEXT_CLEAR_SCREEN)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This
);

typedef EFI_STATUS(EFIAPI *EFI_TEXT_SET_CURSOR_POSITION)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
    IN UINTN                                     Column,
    IN UINTN                                     Row
);

typedef EFI_STATUS(EFIAPI *EFI_TEXT_ENABLE_CURSOR)(
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL          *This,
    IN BOOLEAN                                   Visible
);

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
  EFI_TEXT_RESET                                 Reset;
  EFI_TEXT_STRING                                OutputString;
  EFI_TEXT_TEST_STRING                           TestString;
  EFI_TEXT_QUERY_MODE                            QueryMode;
  EFI_TEXT_SET_MODE                              SetMode;
  EFI_TEXT_SET_ATTRIBUTE                         SetAttribute;
  EFI_TEXT_CLEAR_SCREEN                          ClearScreen;
  EFI_TEXT_SET_CURSOR_POSITION                   SetCursorPosition;
  EFI_TEXT_ENABLE_CURSOR                         EnableCursor;
  SIMPLE_TEXT_OUTPUT_MODE                       *Mode;
};

#endif
