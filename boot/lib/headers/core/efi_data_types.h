//
// Made by Gab Rivas 30/01/25 22:29
//
// Library compressing all of the EFI data types
//

#ifndef EFI_DATA_TYPES_H
#define EFI_DATA_TYPES_H

#if defined(__x86_64__) || defined(__aarch64__)
    #define EFI64BIT
#else
    #error "Unsupported architecture"
#endif

// Basic integer types
typedef signed char             INT8;
typedef signed short            INT16;
typedef signed int              INT32;
typedef signed long long        INT64;

typedef unsigned char           UINT8;
typedef unsigned short          UINT16;
typedef unsigned int            UINT32;
typedef unsigned long long      UINT64;

// Compiler-specific 128-bit types
#if defined(__GNUC__) || defined(__clang__)
    typedef __int128            INT128;
    typedef unsigned __int128   UINT128;
#else
    #error "128-bit integers not supported by compiler"
#endif

// Architecture-dependent native types
#ifdef EFI64BIT
    typedef INT64               INTN;
    typedef UINT64              UINTN;
    #define EFI_MAX_BIT         0x8000000000000000  // Most significant bit for 64-bit
#else
    typedef INT32               INTN;
    typedef UINT32              UINTN;
    #define EFI_MAX_BIT         0x80000000          // Most significant bit for 32-bit
#endif

// Character types
typedef char                    CHAR8;
typedef UINT16                  CHAR16;

// Special types
typedef void                    VOID;
typedef VOID*                   EFI_HANDLE;
typedef VOID*                   EFI_EVENT;
typedef UINT64                  EFI_LBA;
typedef UINTN                   EFI_TPL;
typedef UINTN                   EFI_STATUS;

// Network address types
#pragma pack(push, 1)
typedef struct {
    UINT8 Addr[32];
} EFI_MAC_ADDRESS;

typedef struct {
    UINT8 Addr[4];
} EFI_IPv4_ADDRESS;

typedef struct {
    UINT8 Addr[16];
} EFI_IPv6_ADDRESS;

typedef union {
    EFI_IPv4_ADDRESS v4;
    EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;
#pragma pack(pop)

// GUID structure
#pragma pack(push, 1)
typedef struct {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8  Data4[8];
} EFI_GUID;
#pragma pack(pop)

// Calling convention
#if defined(_MSC_VER)
    #define EFIAPI __cdecl
#elif defined(__GNUC__) || defined(__clang__)
    #define EFIAPI __attribute__((ms_abi))
#else
    #error "Unsupported compiler"
#endif

// Type modifiers
#define IN
#define OUT
#define OPTIONAL
#define CONST const

// Bit manipulation
#define EFI_BIT(bit)            (1ULL << (bit))
#define EFI_BITMASK(width)      ((1ULL << (width)) - 1)

// Boolean type
typedef UINT8 BOOLEAN;
#define TRUE  1
#define FALSE 0
#define NULL  ((VOID*)0)

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

#define EFI_ERROR(code) ((code) > 0)
#define EFI_SUCCESS     0
#define EFI_LOAD_ERROR  0x80000001
#define EFI_INVALID_KEY 0x80000002

// Compile-time size validation
_Static_assert(sizeof(INT8) == 1, "INT8 size mismatch");
_Static_assert(sizeof(UINT8) == 1, "UINT8 size mismatch");
_Static_assert(sizeof(INT16) == 2, "INT16 size mismatch");
_Static_assert(sizeof(UINT16) == 2, "UINT16 size mismatch");
_Static_assert(sizeof(INT32) == 4, "INT32 size mismatch");
_Static_assert(sizeof(UINT32) == 4, "UINT32 size mismatch");
_Static_assert(sizeof(INT64) == 8, "INT64 size mismatch");
_Static_assert(sizeof(UINT64) == 8, "UINT64 size mismatch");
_Static_assert(sizeof(EFI_GUID) == 16, "EFI_GUID size mismatch");
_Static_assert(sizeof(EFI_HANDLE) == sizeof(void*), "EFI_HANDLE size mismatch");

#endif // EFI_DATA_TYPES_H
