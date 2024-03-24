// base
#include <base/alloc.h>
#include <base/new.h>
// cli
#include <cli/emit.h>
#include <cli/option/install.h>
// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// convert option in InstallOption struct
inline InstallOption* get__InstallOption(const char* option);

// install option constructors
CONSTRUCTOR(
    InstallOption*,
    InstallOption,
    enum InstallOptionKind kind
) {
    InstallOption* self = glang_malloc(sizeof(InstallOption));

    self->kind = kind;

    return self;
}
VARIANT_CONSTRUCTOR(
    InstallOption*,
    InstallOption,
    error,
    const char* error
) {
    InstallOption* self = glang_malloc(sizeof(InstallOption));

    self->kind = INSTALL_OPTION_KIND_ERROR;
    self->error = error;

    return self;
}
VARIANT_CONSTRUCTOR(
    InstallOption*,
    InstallOption,
    package,
    const char* package
) {
    InstallOption* self = glang_malloc(sizeof(InstallOption));

    self->kind = INSTALL_OPTION_KIND_PACKAGE;
    self->package = package;

    return self;
}

// get install option
InstallOption* get__InstallOption(const char* option) {

    if (!strcmp(option, "-h") || !strcmp(option, "--help"))
        return NEW(InstallOption, INSTALL_OPTION_KIND_HELP);
    else if (!strcmp(option, "-g") || !strcmp(option, "--global"))
        return NEW(InstallOption, INSTALL_OPTION_KIND_GLOBAL);
    else return NEW_VARIANT(InstallOption, error, option);

}

// parse install options
Vec* parse__InstallOption(const char** options, const Usize options_size) {

    Vec* res = NEW(Vec);

    for (Usize i = 0; i < options_size; i++) {
        if (options[i][0] == '-') {
            push__Vec(res, get__InstallOption(options[i]));
        } else {
            EMIT_ERROR("Expected Option");
            EMIT_NOTE("An option must start with `-`");
            EMIT_HELP("Please see the help of the `install` command");
            exit(1);
        }
    }

    return res;

}

// destructor
DESTRUCTOR(InstallOption, InstallOption* self) { glang_free(self); }