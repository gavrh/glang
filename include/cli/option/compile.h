#ifndef GLANG_CLI_OPTION_COMPILE_H
#define GLANG_CLI_OPTION_COMPILE_H

// base
#include <base/macros.h>
#include <base/vec.h>

enum CompileOptionKind {

    COMPILE_OPTION_KIND_DUMP_IR,          // --dump-ir
    COMPILE_OPTION_KIND_DUMP_PARSER,      // --dump-parser
    COMPILE_OPTION_KIND_DUMP_SCANNER,     // --dump-scanner
    COMPILE_OPTION_KIND_DUMP_TYPECHECK,   // --dump-tc
    COMPILE_OPTION_KIND_ERROR,
    COMPILE_OPTION_KIND_FILENAME,
    COMPILE_OPTION_KIND_HELP,             // -h, --help
    COMPILE_OPTION_KIND_RUN_IR,           // --run-ir
    COMPILE_OPTION_KIND_RUN_PARSER,       // --run-parser
    COMPILE_OPTION_KIND_RUN_SCANNER,      // --run-scanner
    COMPILE_OPTION_KIND_RUN_TYPECHECK     // --run-tc

};

typedef struct CompileOption {

    enum CompileOptionKind kind;
    union {
        const char* error;
        const char* filename;
    };

} CompileOption;
// compile option constructors
CONSTRUCTOR(
    CompileOption*,
    CompileOption,
    enum CompileOptionKind kind
);
VARIANT_CONSTRUCTOR(
    CompileOption*,
    CompileOption,
    error,
    const char* error
);
VARIANT_CONSTRUCTOR(
    CompileOption*,
    CompileOption,
    filename,
    const char* filename
);

// parse compile option
Vec* parse__CompileOption(const char** options, const Usize options_size);

// compile option destructor
DESTRUCTOR(CompileOption, CompileOption* self);

#endif // GLANG_CLI_OPTION_COMPILE_H