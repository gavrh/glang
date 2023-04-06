#ifndef GLANG_BASE_FORMAT_H
#define GLANG_BASE_FORMAT_H

/**
 *
 * @brief Format string.
 *
 * List of format specifiers:
 * - {s}: String
 * - {sa}: String allocated (free after use)
 * - {d:b}: Integer (binary)
 * - {d:o}: Integer (octal)
 * - {d:x}: Integer (hex)
 * - {d}: Integer
 * - {f}: Float
 * - {c}: Char
 * - {b}: Boolean
 * - {p}: Pointer
 * - {u}: Unsigned
 * - {u:b}: Unsigned (binary)
 * - {u:o}: Unsigned (octal)
 * - {u:x}: Unsigned (hex)
 * - {u}: Unsigned
 * - {S}: Dynamic String (base/string.h)
 * - {Sr}: Raw dynamic string (free it after use) (base/string.h)
 */
char* format(const char *fmt, ...);

#endif // GLANG_BASE_FORMAT_H