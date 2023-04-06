// base
#include <base/alloc.h>
#include <base/new.h>
// cli
#include <cli/emit.h>
#include <cli/option/build.h>
// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// convert option in BuildOption struct
static BuildOption* get__BuildOption(const char* option);

CONSTRUCTOR(
    BuildOption*, 
    BuildOption, 
    enum BuildOptionKind kind
) {

    BuildOption* self = glang_malloc(sizeof(BuildOption));

    self->kind = kind;

    return self;

}

VARIANT_CONSTRUCTOR(
    BuildOption*,
    BuildOption,
    error,
    const char* error
) {

    BuildOption* self = glang_malloc(sizeof(BuildOption));

    self->kind = BUILD_OPTION_KIND_ERROR;
    self->error = error;

    return self;

}

BuildOption* get__BuildOption(const char* option) {

    if (!strcmp(option, "-h") || !strcmp(option, "--help"))
        return NEW(BuildOption, BUILD_OPTION_KIND_HELP)
    else if (!strcmp(option, "-v"))
        return NEW(BuildOption, BUILD_OPTION_KIND_VERBOSE)
    else return NEW_VARIANT(BuildOption, error, option);

}

Vec* parse__BuildOption(const char** options, const Usize options_size) {

    Vec* res = NEW(Vec);

    for (Usize i = 0; i < options_size; i++) {
        if (options[i][0] == '-') {
            push__Vec(res, get__BuildOption(options[i]));
        } else {
            EMIT_ERROR("Expected Option");
            EMIT_NOTE("An option must start with `-`");
            EMIT_HELP("Please see the help of the `build` command");
            exit(1);
        }
    }

    return res;

}

DESTRUCTOR(BuildOption, BuildOption* self) { glang_free(self); }