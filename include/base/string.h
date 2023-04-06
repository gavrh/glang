#ifndef GLANG_BASE_STRING_H
#define GLANG_BASE_STRING_H

// base
#include <base/macros.h>
#include <base/types.h>
// c
#include <stdbool.h>

#ifdef ENV_DEBUG
#define DEBUG_STRING(self, res)          \
    push_str__String(res, "\"");         \
    push_str__String(res, self->buffer); \
    push_str__String(res, "\"");
#endif

#define STRING_DEFAULT_CAPACITY 4

#define PUSH_STR_AND_FREE(self, s) \
    {                              \
        push_str__String(self, s); \
        glang_free(s);             \
    }

#define APPEND_AND_FREE(self, s) \
    {                            \
        append__String(self, s); \
        FREE(String, s);         \
    }

typedef struct Vec Vec;

typedef struct String
{
    char *buffer;
    Usize len;
    Usize capacity;
} String;

#endif // GLANG_BASE_STRING_H