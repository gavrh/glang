#ifndef GLANG_BASE_TYPES_H
#define GLANG_BASE_TYPES_H

// base
#include <base/platform.h>
// c
#include <stdint.h>

#if __clang_major__ > 15

// ints
typedef _BitInt(8)  Int8;
typedef _BitInt(16) Int16;
typedef _BitInt(32) Int32;
typedef _BitInt(64) Int64;
// uints
typedef unsigned _BitInt(8)  Int8;
typedef unsigned _BitInt(16) Int16;
typedef unsigned _BitInt(32) Int32;
typedef unsigned _BitInt(64) Int64;

#if defined(PLATFORM_64)
typedef             _BitInt(64) Isize;
typedef unsigned    _BitInt(64) Usize;
#else
typedef             _BitInt(32) Isize;
typedef unsigned    _BitInt(32) Usize;
#endif

#else
typedef int8_t  Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef int64_t Int64;

typedef uint8_t  Uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;
typedef uint64_t Uint64;

#if defined(PLATFORM_64)
typedef int64_t  Isize;
typedef uint64_t Usize;
#else
typedef int32_t  Isize;
typedef uint32_t Usize;
#endif

#endif

typedef float  Float32;
typedef double Float64;

typedef uintptr_t Uptr;


#endif // GLANG_BASE_TYPES_H