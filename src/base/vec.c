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
    Vec* self;
}