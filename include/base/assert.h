#ifndef GLANG_BASE_ASSERT_H
#define GLANG_BASE_ASSERT_H

#define ASSERT_EQ(a, b)                                                \
    do {                                                               \
        if (a != b) {                                                  \
            printf("ASSERT_EQ failed: (%s:%d)\n", __FILE__, __LINE__); \
            exit(1);                                                   \
        }                                                              \
    } while (0)

#define ASSERT_NE(a, b)                                                 \
    do {                                                                \
        if (a == b) {                                                   \
            printf("ASSERT_NEQ failed: (%s:%d)\n", __FILE__, __LINE__); \
            exit(1);                                                    \
        }                                                               \
    } while (0)

#define ASSERT(a)                                                   \
    do {                                                            \
        if (!(a)) {                                                 \
            printf("ASSERT failed: (%s:%d)\n", __FILE__, __LINE__); \
            exit(1);                                                \
        }                                                           \
    } while (0)

#endif // GLANG_BASE_ASSERT_H