#ifndef GLANG_CLI_OPTION_BUILD_H
#define GLANG_CLI_OPTION_BUILD_H

// base
#include <base/macros.h>
#include <base/vec.h>

enum BuildOptionKind {

    BUILD_OPTION_KIND_ERROR,
    BUILD_OPTION_KIND_HELP,       // -h, --help
    BUILD_OPTION_KIND_VERBOSE     // -v

};

typedef struct BuildOption {

    enum BuildOptionKind kind;
    union {
        const char* error;
    };

} BuildOption;
// build option constructors
CONSTRUCTOR(
    BuildOption*,
    BuildOption,
    enum BuildOptionKind kind
);
VARIANT_CONSTRUCTOR(
    BuildOption*,
    BuildOption,
    error,
    const char* error
);

// parse build option
Vec* parse__BuildOption(const char** options, const Usize options_size);

// build option destructor
DESTRUCTOR(BuildOption, BuildOption* self);

#endif // GLANG_CLI_OPTION_BUILD_H