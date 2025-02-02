//
// Made by Gab Rivas 01/02/25
//

#ifndef EFI_TIMER_DELAY_H
#define EFI_TIMER_DELAY_H

#include "efi_core.h"

typedef enum {
    TimerCancel,
    TimerPeriodic,
    TimerRelative
} EFI_TIMER_DELAY;

#endif //EFI_TIMER_DELAY_H
