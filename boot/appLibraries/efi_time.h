//
// Made by Gab Rivas 26/01/25 00:44
//

#ifndef EFI_TIME_H
#define EFI_TIME_H

#include "efi_base_lib.h"

typedef struct{
    UINT16    Year;              // 1900 - 9999
    UINT8     Month;             // 1 - 12
    UINT8     Day;               // 1 - 31
    UINT8     Hour;              // 0 - 23
    UINT8     Minute;            // 0 - 59
    UINT8     Second;            // 0 - 59
    UINT8     Pad1;
    UINT32    Nanosecond;        // 0 - 999,999,999
    INT16     TimeZone;          // —1440 to 1440 or 2047
    UINT8     Daylight;
    UINT8     Pad2;
} EFI_TIME;

#endif
