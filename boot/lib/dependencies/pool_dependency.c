//
// Made by Gab Rivas 02/02/25 11:05
//

#include "pool_dependency.h"

EFI_STATUS AllocatePool(UINTN Size, VOID **Buffer){
    return Bsvc->AllocatePool(EfiLoaderData,Size,Buffer);
}

VOID FreePool(VOID *Buffer){
    if(Buffer){
        Bsvc->FreePool(Buffer);
    }
}
