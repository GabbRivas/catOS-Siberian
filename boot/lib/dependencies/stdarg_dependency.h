//
// Made by Gab Rivas 16/01/25 16:38
//
// STDARG dependency for string formatting and others
//

#ifndef STDARG_DEPENDENCY_H
#define STDARG_DEPENDENCY_H

typedef __builtin_va_list   va_list;

#define va_start(v,l)       __builtin_va_start(v,l)
#define va_end(v)           __builtin_va_end(v)
#define va_arg(v,l)         __builtin_va_arg(v,l)
#define va_copy(d,s)        __builtin_va_copy(d,s)

#endif
