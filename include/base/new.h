#ifndef GLANG_BASE_OPTION_NEW_H
#define GLANG_BASE_OPTION_NEW_H

#define NEW(name, ...) __new__##name(__VA_ARGS__)
#define NEW_VARIANT(name, variant, ...) __new__##name##__##variant(__VA_ARGS__)
#define FREE(name, ...) __free__##name(__VA_ARGS__)
#define FREE_VARIANT(name, variant, ...) __free__##name##__##variant(__VA_ARGS__)

#endif // GLANG_BASE_OPTION_NEW_H