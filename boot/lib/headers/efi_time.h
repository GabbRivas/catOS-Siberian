//
// Made by Gab Rivas 15:03
//

#ifndef EFI_TIME_H
#define EFI_TIME_H

#include "efi_core.h"

typedef struct{
    UINT16      Year;
    UINT8       Month;
    UINT8       Day;
    UINT8       Hour;
    UINT8       Minute;
    UINT8       Second;
    UINT8       Pad1;
    UINT32      NanoSecond;
    INT16       TimeZone;
    UINT8       Daylight;
    UINT8       Pad2;
} EFI_TIME;

// Bit definitions for daylight
#define EFI_TIME_ADJUST_DAYLIGHT   0x01
#define EFI_TIME_IN_DAYLIGHT       0x02

// Value definition for timezone
#define EFI_UNSPECIFIED_TIMEZONE   0x07FF

#endif
