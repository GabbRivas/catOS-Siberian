//
// Made by Gab Rivas 01/02/25 17:10
//

#ifndef EFI_LOCATE_SEARCH_TYPE_H
#define EFI_LOCATE_SEARCH_TYPE_H

#include "../core/efi_core.h"

typedef enum{
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

#endif //EFI_LOCATE_SEARCH_TYPE_H
