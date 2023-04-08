#ifndef GLANG_CORE_SHARED_LOCATION_H
#define GLANG_CORE_SHARED_LOCATION_H

// base
#include <base/macros.h>
#include <base/types.h>

typedef struct Location {
    const char* filename;
    Usize       start_line;
    Usize       end_line;
    Usize       start_column;
    Usize       end_column;
} Location;

#endif // GLANG_CORE_SHARED_LOCATION_H