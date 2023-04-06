#ifndef GLANG_CLI_OPTION_RUN_H
#define GLANG_CLI_OPTION_RUN_H

// base
#include <base/macros.h>
#include <base/vec.h>

enum RunOptionKind {

    RUN_OPTION_KIND_ERROR,
    RUN_OPTION_KIND_FILENAME,
    RUN_OPTION_KIND_HELP,       // -h, --help

};

typedef struct RunOption {

    enum RunOptionKind kind;
    union {
        const char* error;
        const char* filename;
    };

} RunOption;
// run option constructors
CONSTRUCTOR(
    RunOption*,
    RunOption,
    enum RunOptionKind kind
);
VARIANT_CONSTRUCTOR(
    RunOption*,
    RunOption,
    error,
    const char* error
);
VARIANT_CONSTRUCTOR(
    RunOption*,
    RunOption,
    filename,
    const char* filename
);

// parse run option
Vec* parse__RunOption(const char** options, const Usize options_size);

// run option destructor
DESTRUCTOR(RunOption, RunOption* self);

#endif // GLANG_CLI_OPTION_RUN_H