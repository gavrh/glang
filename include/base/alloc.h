#ifndef GLANG_BASE_ALLOC_H
#define GLANG_BASE_ALLOC_H

#include <base/macros.h>
#include <base/types.h>

#ifndef ENV_SAFE
#include <stdlib.h>
#endif

#ifdef ENV_SAFE

// safe calloc function
void* ecalloc__Alloc(Usize n, Usize size);

// safe malloc function
void* emalloc__Alloc(Usize size);

// safe realloc function
void* erealloc__Alloc(void* p, Usize size);

// safe free function
void efree__Alloc(void* p);

#endif

#ifdef ENV_SAFE
#define glang_calloc(n, size) ecalloc__Alloc(n, size)
#define glang_malloc(size) emalloc__Alloc(size)
#define glang_realloc(p, size) erealloc__Alloc(p, size)
#define glang_free(p) efree__Alloc(p)
#else
#define glang_calloc(n, size) calloc(n, size)
#define glang_malloc(size) malloc(size)
#define glang_realloc(p, size) realloc(p, size)
#define glang_free(p) free(p)
#endif

#endif // GLANG_BASE_ALLOC_H