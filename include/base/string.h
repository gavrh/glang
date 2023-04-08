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

#define PUSH_STR_AND_FREE(self, s) {    \
        push_str__String(self, s);      \
        glang_free(s);                  \
    }

#define APPEND_AND_FREE(self, s) {      \
        append__String(self, s);        \
        FREE(String, s);                \
    }

typedef struct Vec Vec;

typedef struct String
{
    char *buffer;
    Usize len;
    Usize capacity;
} String;

// string constructor
CONSTRUCTOR(String*, String);

// string functions
void    append__String(String* self, const String* other);
String* clone__String(String* self);
String* format__String(char *fmt, ...);
String* from__String(char* buffer);
char    get__String(const String* self, Usize index);
void    grow__String(String* self, Usize new_capacity);
char    pop__String(String* self);
void    push__String(String* self, char item);
void    push_str__String(String* self, char* s);
String* repeat__String(char* s, Usize n);
Vec*    split__String(String* self, char seperator);
String* take_slice__String(String* self, Usize index);
void    ungrow__String(String* self);
inline bool is_empty__String(const String* self) { return self->len == 0; }

// string destructor
DESTRUCTOR(String, String* self);

#endif // GLANG_BASE_STRING_H