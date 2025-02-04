//
// Made by Gab Rivas 02/02/25
//

#include "file_dependency.h"

EFI_STATUS FileOpenRoot(EFI_FILE_PROTOCOL **Root){
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Volume;
    EFI_STATUS Status=Bsvc->LocateProtocol(&EfiSimpleFileSystemProtocolGUID,NULL,(VOID**)&Volume);
    if (EFI_ERROR(Status)){
        Print(L"Unable to use LocateProtocol service.");
        return Status;
    }
    return Volume->OpenVolume(Volume,Root);
}

EFI_STATUS FileOpen(EFI_FILE_PROTOCOL *Directory, CHAR16 *Path, EFI_FILE_PROTOCOL **File){
    return Directory->Open(Directory,File,Path,EFI_FILE_MODE_READ,0);
}

EFI_STATUS FileGetSize(EFI_FILE_PROTOCOL *File, UINTN *Size){
    EFI_FILE_INFO   *Info;
    UINTN           InfoSize=0;

    EFI_STATUS Status=File->GetInfo(File,&EfiFileInfoID,&InfoSize,NULL);
    if(Status!=EFI_BUFFER_TOO_SMALL){
        Print(L"File GetInfo: Expected EFI_BUFFER_TOO_SMALL (%x) got: %x\r\n",EFI_BUFFER_TOO_SMALL,Status);
        return Status;
    };

    Status=AllocatePool(InfoSize, (VOID**)&Info);
    if(EFI_ERROR(Status)) {
        return Status;
    }

    Status=File->GetInfo(File, &EfiFileInfoID, &InfoSize, Info);
    if(EFI_ERROR(Status)){
        Print(L"Couldn't retrieve\n\r");
        FreePool(Info);
        return Status;
    }

    *Size=Info->FileSize;
    FreePool(Info);
    return EFI_SUCCESS;
}

EFI_STATUS FileRead(EFI_FILE_PROTOCOL *File, UINTN *Size, VOID **Buffer){
    EFI_STATUS Status = FileGetSize(File, Size);
    if(EFI_ERROR(Status)){
        return Status;
    }
    Status=AllocatePool(*Size, *Buffer);
    if(EFI_ERROR(Status)) return Status;

    return File->Read(File,Size,*Buffer);
}

EFI_STATUS FileClose(EFI_FILE_PROTOCOL *File){
    return File->Close(File);
}
