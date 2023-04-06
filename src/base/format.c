#include <base/alloc.h>
#include <base/format.h>
#include <base/itoa.h>
#include <base/macros.h>
#include <base/new.h>
#include <base/string.h>
#include <base/types.h>

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUSH_STR(s)                                       \
    res = glang_realloc(res, buffer_size + strlen(s) + 1); \
    for (Usize j = 0; s[j++];) {                          \
        res[buffer_size] = s[j - 1];                      \
        res[++buffer_size] = '\0';                        \
    }

#define PUSH_INT(d, base)             \
    char* d_s = itoa__Int32(d, base); \
    PUSH_STR(d_s);                    \
    glang_free(d_s);

char* format(const char* fmt, ...) {
    va_list vl;
    char* res = glang_malloc(1);
    Usize buffer_size = 0;
    Usize len = strlen(fmt);

    res[0] = '\0';
    va_start(vl, fmt);

    for (Usize i = 0; i < len;) {
        switch (fmt[i]) {
            case '{':
                switch (fmt[i + 1]) {
                    case 's': {
                        char* s = va_arg(vl, char*);

                        PUSH_STR(s);

                        if (fmt[i + 2] == 'a') {
                            glang_free(s);
                            i += 3;
                        } else
                            i += 2;

                        break;
                    }
                    case 'd': {
                        int d = va_arg(vl, int);

                        switch (fmt[i + 2]) {
                            case ':':
                                switch (fmt[i + 3]) {
                                    case 'b': {
                                        PUSH_INT(d, 2);

                                        break;
                                    }
                                    case 'o': {
                                        PUSH_INT(d, 8);

                                        break;
                                    }
                                    case 'x': {
                                        PUSH_INT(d, 16);

                                        break;
                                    }
                                    default:
                                        FAILED("unknown specifier");
                                }

                                i += 4;

                                break;
                            default: {
                                PUSH_INT(d, 10);

                                i += 2;
                            }
                        }

                        break;
                    }
                    case 'f':
                        // TODO: use ftoa function instead sprintf
                        switch (fmt[i + 2]) {
                            case '.':
                                TODO("add more precision option");
                                break;
                            default: {
                                Float64 f = va_arg(vl, Float64);
                                char s[24];

                                sprintf(s, "%f", f);

                                PUSH_STR(s);

                                i += 2;

                                break;
                            }
                        }
                        break;
                    case 'c': {
                        char c = va_arg(vl, int);
                        res = glang_realloc(res, buffer_size + 2);

                        res[buffer_size] = c;
                        res[++buffer_size] = '\0';

                        i += 2;

                        break;
                    }
                    case 'b': {
                        bool b = va_arg(vl, int);

                        if (b) {
                            res = glang_realloc(res, buffer_size + 5);

                            res[buffer_size++] = 't';
                            res[buffer_size++] = 'r';
                            res[buffer_size++] = 'u';
                            res[buffer_size++] = 'e';
                            res[buffer_size] = '\0';
                        } else {
                            res = glang_realloc(res, buffer_size + 6);
                            ;

                            res[buffer_size++] = 'f';
                            res[buffer_size++] = 'a';
                            res[buffer_size++] = 'l';
                            res[buffer_size++] = 's';
                            res[buffer_size++] = 'e';
                            res[buffer_size] = '\0';
                        }

                        i += 2;

                        break;
                    }
                    case 'p':
                        break;
                    case 'u': {
                        int d = va_arg(vl, unsigned int);

                        switch (fmt[i + 2]) {
                            case ':':
                                switch (fmt[i + 3]) {
                                    case 'b': {
                                        PUSH_INT(d, 2);

                                        break;
                                    }
                                    case 'o': {
                                        PUSH_INT(d, 8);

                                        break;
                                    }
                                    case 'x': {
                                        PUSH_INT(d, 16);

                                        break;
                                    }
                                    default:
                                        FAILED("unknown specifier");
                                }

                                i += 4;

                                break;
                            default: {
                                PUSH_INT(d, 10);

                                i += 2;
                            }
                        }

                        break;
                    }
                    case 'S': {
                        String* s = va_arg(vl, String* );

                        res = glang_realloc(res, buffer_size + s->len + 1);
                        buffer_size += s->len;

                        strcat(res, s->buffer);

                        if (fmt[i + 2] == 'r') {
                            FREE(String, s);
                            i += 3;
                        } else {
                            i += 2;
                        }

                        break;
                    }
                    case '{':
                        res = glang_realloc(res, buffer_size + 2);
                        res[buffer_size] = '{';
                        res[++buffer_size] = '\0';

                        i += 1;

                        break;
                    default:
                        FAILED("unknown specifier");
                }

                if ((fmt[i - 2] != '{' && fmt[i - 1] != '{') && fmt[i] != '}') {
                    FAILED("expected `}`");
                } else
                    i++;

                break;
            default:
                res = glang_realloc(res, buffer_size + 2);
                res[buffer_size] = fmt[i];
                res[++buffer_size] = '\0';
                i++;
        }
    }

    va_end(vl);

    return res;
}