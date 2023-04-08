// base
#include <base/alloc.h>
#include <base/new.h>
// cli
#include <cli/option/run.h>
// c
#include <stdlib.h>
#include <string.h>

// convert option in run option struct
static RunOption* get__RunOption(const char* option);

// run option constructors
CONSTRUCTOR(
    RunOption*,
    RunOption,
    enum RunOptionKind kind
) {
    RunOption* self = glang_malloc(sizeof(RunOption));

    self->kind = kind;

    return self;
}
VARIANT_CONSTRUCTOR(
    RunOption*,
    RunOption,
    error,
    const char* error
) {
    RunOption* self = glang_malloc(sizeof(RunOption));

    self->kind = RUN_OPTION_KIND_ERROR;
    self->error = error;

    return self;
}
VARIANT_CONSTRUCTOR(
    RunOption*,
    RunOption,
    filename,
    const char* filename
) {
    RunOption* self = glang_malloc(sizeof(RunOption));

    self->kind = RUN_OPTION_KIND_FILENAME;
    self->filename = filename;

    return self;
}

RunOption* get__RunOption(const char* option) {

    if (!strcmp(option, "-h") || !strcmp(option, "--help"))
        return NEW(RunOption, RUN_OPTION_KIND_HELP);
    else 
        return NEW_VARIANT(RunOption, error, option);

}

// parse run option
Vec* parse__RunOption(const char** options, const Usize options_size) {

    Vec* res = NEW(Vec);

    for (Usize i = 0; i < options_size; i++) {
        if (options[i][0] == '-') {
            push__Vec(res, get__RunOption(options[i]));
        } else {
            push__Vec(res, NEW_VARIANT(RunOption, filename, options[i]));
        }
    }

    return res;

}

// run option destructor
DESTRUCTOR(RunOption, RunOption* self) { glang_free(self); }