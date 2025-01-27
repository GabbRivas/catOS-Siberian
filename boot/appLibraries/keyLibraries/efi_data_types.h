//
// Made by Gab Rivas 24/01/25 23:12
//
// Defines data types: UINT, INT, BOOLEAN, UINTN, INTN, TRUE, FALSE
// Defines crucial efi data types: EFI_HANDLE, EFI_EVENT, EFI_LBA, EFI_TPL
// Parameter modifiers: IN, OUT, OPTIONAL, CONST
// Defined UEFI basic calling conventions: EFIAPI
// EFI_GUID
// EFI_SUCESS and EFI_ERROR
//

#ifndef EFI_DATA_TYPES_H
#define EFI_DATA_TYPES_H

// Data Types

typedef void                VOID;

// UINT
typedef unsigned char       UINT8;
typedef unsigned short      UINT16;
typedef unsigned int        UINT32;
typedef unsigned long long  UINT64;
typedef __uint128_t         UINT128;

// INT
typedef signed char         INT8;
typedef signed short        INT16;
typedef signed int          INT32;
typedef signed long long    INT64;
typedef __int128_t          INT128;

// CHARACTERS
typedef UINT8               CHAR8;
typedef UINT16              CHAR16;

// EFI_GUID
typedef struct{
    UINT32                  Data1;
    UINT16                  Data2;
    UINT16                  Data3;
    UINT8                   Data4[8];
} EFI_GUID;

// BOOLEAN
typedef UINT8               BOOLEAN;

#ifndef TRUE
#define TRUE                ((BOOLEAN)1)
#endif

#ifndef FALSE
#define FALSE               ((BOOLEAN)0)
#endif

// NULL
#ifndef NULL
#define NULL                ((VOID *)0)
#endif

// Architecture dependant values
#ifdef __x86_64__
typedef UINT64              UINTN;
typedef INT64               INTN;
#elif defined(__i386__)
typedef UINT32              UINTN;
typedef INT32               INTN;
#else
#error Architecture is invalid
#endif

// Crucial Data Types
typedef void*               EFI_HANDLE;
typedef void*               EFI_EVENT;
typedef UINT64              EFI_STATUS;
typedef UINT64              EFI_LBA;
typedef UINTN               EFI_TPL;
typedef UINT64              EFI_PHYSICAL_ADDRESS;
typedef UINT64              EFI_VIRTUAL_ADDRESS;

// Parameter modifiers
#define IN
#define OUT
#define OPTIONAL
#define CONST               const

// Calling Conventions
#if defined(__GNUC__)||defined(__clang__)
#define EFIAPI __attribute__((ms_abi))
#elif defined(_MSC_VER)
#define EFIAPI __cdecl
#else
#error Compiler is EFIAPI unsupported
#endif

// Network types
typedef struct {
    unsigned char Addr[32]; // 32-byte MAC address
} EFI_MAC_ADDRESS;

typedef struct{
    unsigned char Addr[4];
} EFI_IPv4_ADDRESS;

typedef struct{
    unsigned char Addr[16];
} EFI_IPv6_ADDRESS;

typedef union {
    EFI_IPv4_ADDRESS    v4;
    EFI_IPv6_ADDRESS    v6;
} EFI_IP_ADDRESS;

// EFI_SUCESS and EFI_ERROR
#define EFI_SUCCESS  ((EFI_STATUS)0)         // Success code
#define EFI_ERROR(x) (((EFI_STATUS)(x)) < 0) // Check for error codes

#endif //EFI_DATA_TYPES_H
