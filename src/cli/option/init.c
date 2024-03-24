// base
#include <base/alloc.h>
#include <base/new.h>
// cli
#include <cli/emit.h>
#include <cli/option/init.h>
// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// convert option in InitOption struct
static InitOption* get__InitOption(const char* option);

// init option constructors
CONSTRUCTOR(
    InitOption*,
    InitOption,
    enum InitOptionKind kind
) {
    InitOption* self = glang_malloc(sizeof(InitOption));

    self->kind = kind;

    return self;
}
VARIANT_CONSTRUCTOR(
    InitOption*,
    InitOption,
    error,
    const char* error
) {
    InitOption* self = glang_malloc(sizeof(InitOption));

    self->kind = INIT_OPTION_KIND_ERROR;
    self->error = error;

    return self;

}
VARIANT_CONSTRUCTOR(
    InitOption*,
    InitOption,
    name,
    const char* name
) {
    InitOption* self = glang_malloc(sizeof(InitOption));

    self->kind = INIT_OPTION_KIND_NAME;
    self->name = name;

    return self;
}

InitOption* get__InitOption(const char* option) {

    if (!strcmp(option, "-h") || !strcmp(option, "--help"))
        return NEW(InitOption, INIT_OPTION_KIND_HELP);
    else if (!strcmp(option, "-e") || !strcmp(option, "--exe"))
        return NEW(InitOption, INIT_OPTION_KIND_TYPE_EXE);
        else if (!strcmp(option, "-l") || !strcmp(option, "--lib"))
        return NEW(InitOption, INIT_OPTION_KIND_TYPE_LIB);
    else return NEW_VARIANT(InitOption, error, option);

}

// parse build option
Vec* parse__InitOption(const char** options, const Usize options_size) {

    Vec* res = NEW(Vec);

    for (Usize i = 0; i < options_size; i++) {
        if (options[i][0] == '-') {
            push__Vec(res, get__InitOption(options[i]));
        } else {
            EMIT_ERROR("Expected Option");
            EMIT_NOTE("An option must start with `-`");
            EMIT_HELP("Please see the help of the `init` command");
            exit(1);
        }
    }

    return res;

}

// build option destructor
DESTRUCTOR(InitOption, InitOption* self) { glang_free(self); }