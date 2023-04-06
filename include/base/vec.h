#ifndef GLANG_BASE_VEC_H
#define GLANG_BASE_VEC_H

// base
#include <base/macros.h>
#include <base/types.h>
#include <base/string.h>
// c
#include <stdbool.h>

typedef String String;

typedef struct Vec {
    void** buffer;
    Usize len;
    Usize capacity;
    Usize default_capacity;
} Vec;
// vector constructor
CONSTRUCTOR(Vec*, Vec);

// vector functions
void append__Vec(Vec* self, const Vec *other);          // append two vectors
Vec* from__Vec(void** buffer, Usize len);               // construct vector type with default buffer items
void* get__Vec(const Vec* self, Usize index);           // get item from vector
void grow__Vec(Vec* self, Usize new_capacity);          // grow vector buffer
Vec* init__Vec(Usize len, ...);                         // initialize vector
void insert__Vec(Vec* self, void* item, Usize index);   // insert and item into vector at n index
String* join__Vec(const Vec* self, char c);             // join each item with c param
void* last__Vec(const Vec* self);                       // get last item of vector
void* pop__Vec(Vec* self);                              // remove last item from vector
void push__Vec(Vec* self, void* item);                  // push item to vector buffer
void* remove__Vec(Vec* self, Usize index);              // remove item from vector buffer and n index
void reverse__Vec(Vec* self);                           // reverse vector buffer
void ungrow__Vec(Vec* self);                            // ungrow vector buffer

// vector destructor
DESTRUCTOR(Vec, Vec* self);


#endif // GLANG_BASE_VEC_H