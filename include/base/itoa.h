#ifndef GLANG_BASE_ITOA_H
#define GLANG_BASE_ITOA_H

#include <base/types.h>

// 8 bit integer to string
char* itoa__Int8(Int8 v, int base);
// 8 bit unsigned integer to string
char* itoa__Uint8(Uint8 v, int base);
// 16 bit integer to string
char* itoa__Int16(Int16 v, int base);
// 16 bit unsigned integer to string
char* itoa__Uint16(Uint16 v, int base);
// 32 bit integer to string
char* itoa__Int32(Int32 v, int base);
// 32 bit unsigned integer to string
char* itoa__Uint32(Uint32 v, int base);
// 64 bit integer to string
char* itoa__Int64(Int64 v, int base);
// 64 bit unsigned integer to string
char* itoa__Uint64(Uint64 v, int base);

#endif // GLANG_BASE_ITOA_H