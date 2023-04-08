#ifndef GLANG_BASE_MACROS_H
#define GLANG_BASE_MACROS_H

#define ENV_DEBUG
#undef  ENV_DEBUG

#define ENV_INSTALL
#undef  ENV_INSTALL

#define ENV_LOCAL
#undef  ENV_LOCAL

#define ENV_SAFE
#undef  ENV_SAFE

#if defined(__GNUC__) && !defined(__clang_major__)
#define GCC_VERSION \
    (__GNUC__ * 1000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#elif defined(__clang_major__)
#define CLANG_VERSION \
    (__clang_major__ * 1000 + __clang_minor__ * 100 + __clang_patchlevel__)
#elif defined(_MSC_VER)
#define MSVC_VERSION _MSC_VER
#else
#error \
  "unknown compiler, please add a support for this compiler or open issue at 'https://github.com/ArthurPV/lily/tree/main'."
#endif

// pointers and memory
#define PTR_SIZE sizeof(void*)
#define FREE_BUFFER_ITEMS(b, l, t)      \
    for (Usize x1 = 0; x1 < l; x1++) {  \
        __free__##t(b[x1]);             \
    }
#define FREE_BUFFER_ITEMS_2(b, l, t)    \
    for (Usize x2 = 0; x2 < l; x2++) {  \
    }
#define CAST(type, expr) ((type)(expr))

// (struct) constructor / destructor / variants
#define CONSTRUCTOR(type, name, ...) type __new__##name(__VA_ARGS__)
#define VARIANT_CONSTRUCTOR(type, name, variant, ...) type __new__##name##__##variant(__VA_ARGS__)
#define DESTRUCTOR(name, ...) void __free__##name(__VA_ARGS__)
#define VARIANT_DESTRUCTOR(name, variant, ...) void __free__##name##__##variant(__VA_ARGS__)


#define TEST(type, name, ...) type name##__Test__(__VA_ARGS__)
#define CALL_TEST(name, ...) name##__Test__(__VA_ARGS__)

#define DBG(msg) {                                              \
        printf("DEBUG: %s (%s:%d)\n", msg, __FILE__, __LINE__); \
        exit(1);                                                \
    }

#define TODO(msg) {                                            \
        printf("TODO: %s (%s:%d)\n", msg, __FILE__, __LINE__); \
        exit(1);                                               \
    }

#define FAILED(msg) {                                            \
        printf("FAILED: %s (%s:%d)\n", msg, __FILE__, __LINE__); \
        exit(1);                                                 \
    }

#define UNREACHABLE(msg) {                                            \
        printf("UNREACHABLE: %s (%s:%d)\n", msg, __FILE__, __LINE__); \
        exit(1);                                                      \
    }

#endif // GLANG_BASE_MACROS_H