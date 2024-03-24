#ifndef GLANG_CLI_OPTION_INIT_H
#define GLANG_CLI_OPTION_INIT_H

// base
#include <base/macros.h>
#include <base/vec.h>

enum InitOptionKind {

    INIT_OPTION_KIND_ERROR,
    INIT_OPTION_KIND_HELP,      // -h, --help
    INIT_OPTION_KIND_NAME,
    INIT_OPTION_KIND_TYPE_LIB,  // -l, --lib
    INIT_OPTION_KIND_TYPE_EXE   // -e, --exe

};

typedef struct InitOption {

    enum InitOptionKind kind;
    union {
        const char* error;
        const char* name;
    };

} InitOption;
// build option constructors
CONSTRUCTOR(
    InitOption*,
    InitOption,
    enum InitOptionKind kind
);
VARIANT_CONSTRUCTOR(
    InitOption*,
    InitOption,
    error,
    const char* error
);
VARIANT_CONSTRUCTOR(
    InitOption*,
    InitOption,
    name,
    const char* name
);

// parse build option
Vec* parse__InitOption(const char** options, const Usize options_size);

// build option destructor
DESTRUCTOR(InitOption, InitOption* self);

#endif // GLANG_CLI_OPTION_INIT_H