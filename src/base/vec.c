// base
#include <base/alloc.h>
#include <base/assert.h>
#include <base/macros.h>
#include <base/new.h>
#include <base/string.h>
#include <base/vec.h>
// c
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// vector constructor
CONSTRUCTOR(Vec*, Vec) {
    Vec* self = glang_malloc(sizeof(Vec));

    self->buffer            = NULL;
    self->len               = 0;
    self->capacity          = 0;
    self->default_capacity  = 4;

    return self;
}

void append__Vec(Vec* self, const Vec* other) {
    for (Usize i = 0; i < other->len; i++) {
        push__Vec(self, other->buffer[i]);
    }
}

Vec* from__Vec(void**buffer, Usize len) {
    Vec* self = glang_malloc(sizeof(Vec));

    self->default_capacity = len;
    self->len = len;
    self->capacity = len * 2;
    self->buffer = glang_malloc(PTR_SIZE * self->capacity);

    for (Usize i = len; i--;) {
        self->buffer[i] = buffer[i];
    }

    return self;
}

void* get__Vec(const Vec* self, Usize index) {
    ASSERT(index < self->len);

    return self->buffer[index];
}

void grow__Vec(Vec* self, Usize new_capacity) {
    ASSERT(new_capacity >= self->capacity);

    self->buffer = glang_realloc(self->buffer, PTR_SIZE * new_capacity);
    self->capacity = new_capacity;
}

Vec*  init__Vec(Usize len, ...) {
    Vec* self = NEW(Vec);
    va_list vl;

    va_start(vl, len);

    for (Usize i = 0; i < len; i++) {
        push__Vec(self, va_arg(vl, void* ));
    }

    va_end(vl);

    return self;
}

void insert__Vec(Vec* self, void* item, Usize index) {
    ASSERT(index < self->len);

    void* move = self->buffer[index];

    self->buffer[index] = item;

    for (Usize i = index + 1; i < self->len; i++) {
        void* tmp_move = move;
        move = self->buffer[i];

        self->buffer[i] = tmp_move;
    }

    push__Vec(self, move);
}

String* join__Vec(const Vec* self, char c) {
    String* res = NEW(String);

    for (Usize i = 0; i < self->len; i++) {
        push_str__String(res, CAST(String* , self->buffer[i])->buffer);

        if (i != self->len - 1) {
            push__String(res, c);
        }
    }

    return res;
}

void* last__Vec(const Vec* self) {
    ASSERT(self->len > 0);

    return self->buffer[self->len - 1];
}

void* pop__Vec(Vec* self) {
    ASSERT(self->len > 0);

    void* item = self->buffer[--self->len];

    ungrow__Vec(self);

    return item;
}

void push__Vec(Vec* self, void* item) {
    if (!self->capacity)
        grow__Vec(self, self->default_capacity);
    else if (self->len == self->capacity)
        grow__Vec(self, self->capacity * 2);

    self->buffer[self->len++] = item;
}

void* remove__Vec(Vec* self, Usize index) {
    ASSERT(index < self->len);

    void* item = self->buffer[index];
    self->len -= 1;

    // Align the rest of the buffer
    for (Usize i = index; i < self->len; i++) {
        self->buffer[i] = self->buffer[i + 1];
    }

    ungrow__Vec(self);

    return item;
}

void reverse__Vec(Vec* self) {
    Usize i = 0;
    Usize j = self->len - 1;

    while (i < j) {
        void* tmp = self->buffer[i];
        self->buffer[i] = self->buffer[j];
        self->buffer[j] = tmp;

        i++;
        j--;
    }
}

void ungrow__Vec(Vec* self) {
    if (self->len <= self->capacity / 2) {
        self->capacity /= 2;
        self->buffer = glang_realloc(self->buffer, PTR_SIZE * self->capacity);
    }
}

DESTRUCTOR(Vec, Vec* self)
{
    if (self->buffer) {
        glang_free(self->buffer);
    }

    glang_free(self);
}