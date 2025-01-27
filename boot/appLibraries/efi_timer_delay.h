//
// Made by Gab Rivas 25/01/25 23:32
//

#ifndef EFI_TIMER_DELAY_H
#define EFI_TIMER_DELAY_H

#include "efi_base_lib.h"

typedef enum {
   TimerCancel,
   TimerPeriodic,
   TimerRelative
} EFI_TIMER_DELAY;

#endif
