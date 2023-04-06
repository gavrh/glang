#include <base/alloc.h>

#ifdef ENV_SAFE
#include <stdio.h>
#include <stdlib.h>

void* ecalloc__Alloc(Usize n, Usize size) {

    // ptr
    void* p = calloc(n, size);

    if (!p) {
        perror("(ecalloc): Try to allocate");
    }

    return p;
}

void* emalloc__Alloc(Usize size) {
    
    // ptr
    void* p = malloc(size);

    if (!p) {
        perror("(emalloc): Try to allocate");
    }

    return p;
};

void* erealloc__Alloc(void* p) {

    // ptr
    void* new_p = malloc(size);

    if (!new_p) {
        perror("(erealloc): Try to allocate");
    }

    return new_p;

};

void efree__Alloc(void* p) {

    if (!p) {
        perror("(efree): Try to free");
    }

    free(p);
    p = NULL;
};

#endif