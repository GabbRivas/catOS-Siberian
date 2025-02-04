//
// Made by Gab Rivas 02/02/25
//

#ifndef EFI_STATUS_CODES_H
#define EFI_STATUS_CODES_H

#define EFI_WARN_HEADER         0x00000000000000

#define EFI_LAOD_ERROR              1
#define EFI_INVALID_PARAMETER       2
#define EFI_UNSUPPORTED             3
#define EFI_BAD_BUFFER_SIZE         4
#define EFI_BUFFER_TOO_SMALL        5
#define EFI_NOT_READY               6
#define EFI_DEVICE_ERROR            7
#define EFI_WRITE_PROTECTED         8
#define EFI_OUT_OF_RESOURCES        9
#define EFI_VOLUME_CORRUPTED        10
#define EFI_VOLUME_FULL             11
#define EFI_NO_MEDIA                12
#define EFI_MEDIA_CHANGED           13
#define EFI_NOT_FOUND               14
#define EFI_ACCESS_DENIED           15
#define EFI_NO_RESPONSE             16
#define EFI_NO_MAPPING              17
#define EFI_TIMEOUT                 18
#define EFI_NOT_STARTED             19
#define EFI_ALREADY_STARTED         20
#define EFI_ABORTED                 21
#define EFI_ICMP_ERROR              22
#define EFI_TFTP_ERROR              23
#define EFI_PROTOCOL_ERROR          24
#define EFI_INCOMPATIBLE_VERSION    25
#define EFI_SECURITY_VIOLATION      26
#define EFI_CRC_ERROR               27
#define EFI_END_OF_MEDIA            28
#define EFI_END_OF_FILE             31
#define EFI_INVALID_LANGUAGE        32
#define EFI_COMPROMISED_DATA        33
#define EFI_IP_ADDRESS_CONFLICT     34
#define EFI_HTTP_ERROR              35

#define EFI_WARN_UNKNOWN_GLYPH      (EFI_WARN_HEADER|1)
#define EFI_WARN_DELETE_FAILURE     (EFI_WARN_HEADER|2)
#define EFI_WARN_WRITE_FAILURE      (EFI_WARN_HEADER|3)
#define EFI_WARN_BUFFER_TOO_SMALL   (EFI_WARN_HEADER|4)
#define EFI_WARN_STALE_DATA         (EFI_WARN_HEADER|5)
#define EFI_WARN_FILE_SYSTEM        (EFI_WARN_HEADER|6)
#define EFI_WARN_RESET_REQUIRED     (EFI_WARN_HEADER|7)

#endif
