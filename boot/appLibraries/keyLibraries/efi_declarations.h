//
// Made by Gab Rivas 24/01/25 23:10
//
// File containing all EFI declarations that might be useful at some point
//

#ifndef EFI_DECLARATIONS_H
#define EFI_DECLARATIONS_H

#include "efi_data_types.h"

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

// EFI KEY STATE

#define EFI_SHIFT_STATE_VALID          0x80000000
#define EFI_RIGHT_SHIFT_PRESSED        0x00000001
#define EFI_LEFT_SHIFT_PRESSED         0x00000002
#define EFI_RIGHT_CONTROL_PRESSED      0x00000004
#define EFI_LEFT_CONTROL_PRESSED       0x00000008
#define EFI_RIGHT_ALT_PRESSED          0x00000010
#define EFI_LEFT_ALT_PRESSED           0x00000020
#define EFI_RIGHT_LOGO_PRESSED         0x00000040
#define EFI_LEFT_LOGO_PRESSED          0x00000080
#define EFI_MENU_KEY_PRESSED           0x00000100
#define EFI_SYS_REQ_PRESSED            0x00000200

//*****************************************************
// EFI_KEY_TOGGLE_STATE
//*****************************************************
typedef UINT8 EFI_KEY_TOGGLE_STATE;

#define EFI_TOGGLE_STATE_VALID 0x80
#define EFI_KEY_STATE_EXPOSED 0x40
#define EFI_SCROLL_LOCK_ACTIVE 0x01
#define EFI_NUM_LOCK_ACTIVE 0x02
#define EFI_CAPS_LOCK_ACTIVE 0x04

// SIMPLE TEXT OUTPUT PROTOCOL

//******************************************************
// UNICODE DRAWING CHARACTERS
//******************************************************

#define BOXDRAW_HORIZONTAL             0x2500
#define BOXDRAW_VERTICAL               0x2502
#define BOXDRAW_DOWN_RIGHT             0x250c
#define BOXDRAW_DOWN_LEFT              0x2510
#define BOXDRAW_UP_RIGHT               0x2514
#define BOXDRAW_UP_LEFT                0x2518
#define BOXDRAW_VERTICAL_RIGHT         0x251c
#define BOXDRAW_VERTICAL_LEFT          0x2524
#define BOXDRAW_DOWN_HORIZONTAL        0x252c
#define BOXDRAW_UP_HORIZONTAL          0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL    0x253c

#define BOXDRAW_DOUBLE_HORIZONTAL      0x2550
#define BOXDRAW_DOUBLE_VERTICAL        0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE      0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT      0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT      0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE       0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT       0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT       0x2557

#define BOXDRAW_UP_RIGHT_DOUBLE        0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT        0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT        0x255a
#define BOXDRAW_UP_LEFT_DOUBLE         0x255b
#define BOXDRAW_UP_DOUBLE_LEFT         0x255c
#define BOXDRAW_DOUBLE_UP_LEFT         0x255d

#define BOXDRAW_VERTICAL_RIGHT_DOUBLE  0x255e
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT  0x255f
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT  0x2560

#define BOXDRAW_VERTICAL_LEFT_DOUBLE   0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT   0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT   0x2563

#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE 0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL 0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL 0x2566

#define BOXDRAW_UP_HORIZONTAL_DOUBLE   0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL   0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL   0x2569

#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256a
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256b
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256c

//******************************************************
// EFI Required Block Elements Code Chart
//******************************************************

#define BLOCKELEMENT_FULL_BLOCK        0x2588
#define BLOCKELEMENT_LIGHT_SHADE       0x2591

//******************************************************
// EFI Required Geometric Shapes Code Chart
//******************************************************

#define GEOMETRICSHAPE_UP_TRIANGLE     0x25b2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE  0x25ba
#define GEOMETRICSHAPE_DOWN_TRIANGLE   0x25bc
#define GEOMETRICSHAPE_LEFT_TRIANGLE   0x25c4

//******************************************************
// EFI Required Arrow shapes
//******************************************************

#define ARROW_UP                       0x2191
#define ARROW_DOWN                     0x2193

// MORE EFI SIMPLE TEXT OUTPUT PROTOCOL

//*******************************************************
// Attributes
//*******************************************************
#define EFI_BLACK                              0x00
#define EFI_BLUE                               0x01
#define EFI_GREEN                              0x02
#define EFI_CYAN                               0x03
#define EFI_RED                                0x04
#define EFI_MAGENTA                            0x05
#define EFI_BROWN                              0x06
#define EFI_LIGHTGRAY                          0x07
#define EFI_BRIGHT                             0x08
#define EFI_DARKGRAY (EFI_BLACK | EFI_BRIGHT)  0x08
#define EFI_LIGHTBLUE                          0x09
#define EFI_LIGHTGREEN                         0x0A
#define EFI_LIGHTCYAN                          0x0B
#define EFI_LIGHTRED                           0x0C
#define EFI_LIGHTMAGENTA                       0x0D
#define EFI_YELLOW                             0x0E
#define EFI_WHITE                              0x0F


#define EFI_BACKGROUND_BLACK                   0x00
#define EFI_BACKGROUND_BLUE                    0x10
#define EFI_BACKGROUND_GREEN                   0x20
#define EFI_BACKGROUND_CYAN                    0x30
#define EFI_BACKGROUND_RED                     0x40
#define EFI_BACKGROUND_MAGENTA                 0x50
#define EFI_BACKGROUND_BROWN                   0x60
#define EFI_BACKGROUND_LIGHTGRAY               0x70
//
// Macro to accept color values in their raw form to create
// a value that represents both a foreground and background
// color in a single byte.
// For Foreground, and EFI_\* value is valid from EFI_BLACK(0x00)
// to EFI_WHITE (0x0F).
// For Background, only EFI_BLACK, EFI_BLUE, EFI_GREEN,
// EFI_CYAN, EFI_RED, EFI_MAGENTA, EFI_BROWN, and EFI_LIGHTGRAY
// are acceptable.
//
// Do not use EFI_BACKGROUND_xxx values with this macro.
//#define EFI_TEXT_ATTR(Foreground,Background) \
((Foreground) | ((Background) << 4))

// EFI_EVENT

//******************************************************
// Event Types
//******************************************************
// These types can be "ORed" together as needed - for example,
// EVT_TIMER might be "Ored" with EVT_NOTIFY_WAIT or
// EVT_NOTIFY_SIGNAL.
#define EVT_TIMER                            0x80000000
#define EVT_RUNTIME                          0x40000000

#define EVT_NOTIFY_WAIT                      0x00000100
#define EVT_NOTIFY_SIGNAL                    0x00000200

#define EVT_SIGNAL_EXIT_BOOT_SERVICES        0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE    0x60000202

// EFI EVENT GROUPS
#define EFI_EVENT_GROUP_EXIT_BOOT_SERVICES \
 {0x27abf055, 0xb1b8, 0x4c26, 0x80, 0x48, 0x74, 0x8f, 0x37,\
 0xba, 0xa2, 0xdf}}

#define EFI_EVENT_GROUP_BEFORE_EXIT_BOOT_SERVICES \
  { 0x8be0e274, 0x3970, 0x4b44, { 0x80, 0xc5, 0x1a, 0xb9, 0x50, 0x2f, 0x3b, 0xfc } }

#define EFI_EVENT_GROUP_VIRTUAL_ADDRESS_CHANGE \
  {0x13fa7698, 0xc831, 0x49c7, 0x87, 0xea, 0x8f, 0x43, 0xfc,\
  0xc2, 0x51, 0x96}

#define EFI_EVENT_GROUP_MEMORY_MAP_CHANGE \
 {0x78bee926, 0x692f, 0x48fd, 0x9e, 0xdb, 0x1, 0x42, 0x2e, \
 0xf0, 0xd7, 0xab}

#define EFI_EVENT_GROUP_READY_TO_BOOT \
 {0x7ce88fb3, 0x4bd7, 0x4679, 0x87, 0xa8, 0xa8, 0xd8, 0xde,\
 0xe5,0xd, 0x2b}

#define EFI_EVENT_GROUP_AFTER_READY_TO_BOOT \
  { 0x3a2a00ad, 0x98b9, 0x4cdf, { 0xa4, 0x78, 0x70, 0x27, 0x77, \
  0xf1, 0xc1, 0xb } }

#define EFI_EVENT_GROUP_RESET_SYSTEM \
  { 0x62da6a56, 0x13fb, 0x485a, { 0xa8, 0xda, 0xa3, 0xdd, 0x79, 0x12, 0xcb, 0x6b} }

// TPL
//******************************************************
// Task Priority Levels
//******************************************************
#define TPL_APPLICATION    4
#define TPL_CALLBACK       8
#define TPL_NOTIFY         16
#define TPL_HIGH_LEVEL     31

// EFI MEMORY DESCRIPTOR
//******************************************************
// Memory Attribute Definitions
//******************************************************
// These types can be "ORed" together as needed.
#define EFI_MEMORY_UC              0x0000000000000001
#define EFI_MEMORY_WC              0x0000000000000002
#define EFI_MEMORY_WT              0x0000000000000004
#define EFI_MEMORY_WB              0x0000000000000008
#define EFI_MEMORY_UCE             0x0000000000000010
#define EFI_MEMORY_WP              0x0000000000001000
#define EFI_MEMORY_RP              0x0000000000002000
#define EFI_MEMORY_XP              0x0000000000004000
#define EFI_MEMORY_NV              0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE   0x0000000000010000
#define EFI_MEMORY_RO              0x0000000000020000
#define EFI_MEMORY_SP              0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO      0x0000000000080000
#define EFI_MEMORY_HOT_PLUGGABLE   0x0000000000100000
#define EFI_MEMORY_RUNTIME         0x8000000000000000
#define EFI_MEMORY_ISA_VALID       0x4000000000000000
#define EFI_MEMORY_ISA_MASK        0x0FFFF00000000000

// BOOT SERVICES OPEN PROTOCOL
#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL   0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL         0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL        0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER  0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER            0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE            0x00000020

//******************************************************
// EFI_OPTIONAL_PTR
//******************************************************
#define EFI_OPTIONAL_PTR          0x00000001


#endif
