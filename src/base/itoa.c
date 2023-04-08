// base
#include <base/alloc.h>
#include <base/itoa.h>
#include <base/macros.h>
// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __itoa__(v, base)                                   \
    char* buffer = glang_malloc(1);                          \
    int buffer_size = 0;                                    \
    if (v == 0) {                                           \
        buffer = glang_realloc(buffer, buffer_size + 2);     \
        buffer[buffer_size] = '0';                          \
        buffer[++buffer_size] = '\0';                       \
        return buffer;                                      \
    }                                                       \
    buffer[0] = '\0';                                       \
    int is_neg = 0;                                         \
    if (v < 0) {                                            \
        is_neg = 1;                                         \
        v = -v;                                             \
    }                                                       \
    if (base == 10) {                                       \
        while (v > 0) {                                     \
            buffer = glang_realloc(buffer, buffer_size + 2); \
            buffer[buffer_size] = (v % 10) + '0';           \
            buffer[++buffer_size] = '\0';                   \
            v /= 10;                                        \
        }                                                   \
    } else if (base == 2) {                                 \
        while (v > 0) {                                     \
            buffer = glang_realloc(buffer, buffer_size + 2); \
            buffer[buffer_size] = (v % 2) + '0';            \
            buffer[++buffer_size] = '\0';                   \
            v /= 2;                                         \
        }                                                   \
    } else if (base == 8) {                                 \
        while (v > 0) {                                     \
            buffer = glang_realloc(buffer, buffer_size + 2); \
            buffer[buffer_size] = (v % 8) + '0';            \
            buffer[++buffer_size] = '\0';                   \
            v /= 8;                                         \
        }                                                   \
    } else if (base == 16) {                                \
        while (v > 0) {                                     \
            buffer = glang_realloc(buffer, buffer_size + 2); \
            int n = (v % 16) + '0';                         \
            buffer[buffer_size] = n > '9' ? n + 7 : n;      \
            buffer[++buffer_size] = '\0';                   \
            v /= 16;                                        \
        }                                                   \
    } else {                                                \
        UNREACHABLE("unknown base");                        \
    }                                                       \
    if (is_neg) {                                           \
        buffer = glang_realloc(buffer, buffer_size + 2);     \
        buffer[buffer_size] = '-';                          \
        buffer[++buffer_size] = '\0';                       \
        v = -v;                                             \
    }                                                       \
    for (int i = 0; i < buffer_size / 2; i++) {             \
        char tmp = buffer[i];                               \
        buffer[i] = buffer[buffer_size - i - 1];            \
        buffer[buffer_size - i - 1] = tmp;                  \
    }                                                       \
    return buffer

#define GET_MIN_INT_VALUE(x)              \
    int size = strlen(x);                 \
    char* buffer = glang_malloc(size + 1); \
    for (int i = size; i--;) {            \
        buffer[i] = x[i];                 \
    }                                     \
    buffer[size] = '\0';                  \
    return buffer

// 8 bit integer to string
char* itoa__Int8(Int8 v, int base) {

    if (v == INT8_MIN) {
        switch (base) {
            case 2: {
                GET_MIN_INT_VALUE("-10000000");
            }
            case 8: {
                GET_MIN_INT_VALUE("-200");
            }
            case 10: {
                GET_MIN_INT_VALUE("-128");
            }
            case 16: {
                GET_MIN_INT_VALUE("-80");
            }
            default:
                UNREACHABLE("unknown base");
        }
    }

    __itoa__(v, base);

}
// 8 bit unsigned integer to string
char* itoa__Uint8(Uint8 v, int base) { __itoa__(v, base); }
// 16 bit integer to string
char* itoa__Int16(Int16 v, int base) {

    if (v == INT16_MIN) {
        switch (base) {
            case 2: {
                GET_MIN_INT_VALUE("-1000000000000000");
            }
            case 8: {
                GET_MIN_INT_VALUE("100000");
            }
            case 10: {
                GET_MIN_INT_VALUE("32768");
            }
            case 16: {
                GET_MIN_INT_VALUE("8000");
            }
            default:
                UNREACHABLE("unknown base");
        }
    }

    __itoa__(v, base);

}
// 16 bit unsigned integer to string
char* itoa__Uint16(Uint16 v, int base) { __itoa__(v, base); }
// 32 bit integer to string
char* itoa__Int32(Int32 v, int base) {

    if (v == INT32_MIN) {
        switch (base) {
            case 2: {
                GET_MIN_INT_VALUE("-10000000000000000000000000000000");
            }
            case 8: {
                GET_MIN_INT_VALUE("20000000000");
            }
            case 10: {
                GET_MIN_INT_VALUE("-2147483628");
            }
            case 16: {
                GET_MIN_INT_VALUE("-80000000");
            }
            default:
                UNREACHABLE("unknown base");
        }
    }

    __itoa__(v, base);

}
// 32 bit unsigned integer to string
char* itoa__Uint32(Uint32 v, int base) { __itoa__(v, base); }
// 64 bit integer to string
char* itoa__Int64(Int64 v, int base) {

    if (v == INT64_MIN) {
        switch (base) {
            case 2: {
                GET_MIN_INT_VALUE("-1000000000000000000000000000000000000000000000000000000000000000");
            }
            case 8: {
                GET_MIN_INT_VALUE("-1000000000000000000000");
            }
            case 10: {
                GET_MIN_INT_VALUE("-9223372036854775808");
            }
            case 16: {
                GET_MIN_INT_VALUE("-8000000000000000");
            }
            default:
                UNREACHABLE("unknown base");
        }
    }

    __itoa__(v, base);

}
// 64 bit unsigned integer to string
char* itoa__Uint64(Uint64 v, int base) { __itoa__(v, base); }