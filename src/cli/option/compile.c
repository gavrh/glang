// base
#include <base/alloc.h>
#include <base/new.h>
// cli
#include <cli/emit.h>
#include <cli/option/compile.h>
// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// convert option in CompileOptione struct
static CompileOption* get__CompileOption(const char* option);

CONSTRUCTOR(
    CompileOption*,
    CompileOption,
    enum CompileOptionKind kind
) {

    CompileOption* self = glang_malloc(sizeof(CompileOption));

    self->kind = kind;

    return self;

}
VARIANT_CONSTRUCTOR(
    CompileOption*,
    CompileOption,
    error,
    const char* error
) {

    CompileOption* self = glang_malloc(sizeof(CompileOption));

    self->kind  = COMPILE_OPTION_KIND_ERROR;
    self->error = error;

    return self;

}
VARIANT_CONSTRUCTOR(
    CompileOption*,
    CompileOption,
    filename,
    const char* filename
) {

    CompileOption* self = glang_malloc(sizeof(CompileOption));

    self->kind     = COMPILE_OPTION_KIND_FILENAME;
    self->filename = filename;

    return self;

}

CompileOption* get__CompileOption(const char* option) {

    if (!strcmp(option, "--dump-ir"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_DUMP_IR);
    else if (!strcmp(option, "--dump-parser"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_DUMP_PARSER);
    else if (!strcmp(option, "--dump-scanner"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_DUMP_TYPECHECK);
    else if (!strcmp(option, "--dump-tc"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_DUMP_TYPECHECK);
    else if (!strcmp(option, "--run-ir"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_RUN_IR);
    else if (!strcmp(option, "--run-parser"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_RUN_PARSER);
    else if (!strcmp(option, "--run-scanner"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_RUN_SCANNER);
    else if (!strcmp(option, "--run-tc"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_RUN_TYPECHECK);
    else if (!strcmp(option, "-h") || !strcmp(option, "--help"))
        return NEW(CompileOption, COMPILE_OPTION_KIND_HELP);
    else return NEW_VARIANT(CompileOption, error, option);

}

Vec* parse__CompileOption(const char** options, const Usize options_size) {

    Vec* res = NEW(Vec);

    for (Usize i = 0; i < options_size; i++) {
        if (options[i][0] == '-') {
            push__Vec(res, get__CompileOption(options[i]));
        } else {
            EMIT_ERROR("Expected Option");
            EMIT_NOTE("An option must start with `-`");
            EMIT_HELP("Please see the help of the `compile` command");
            exit(1);
        }
    }

    return res;

}

DESTRUCTOR(CompileOption, CompileOption* self) { glang_free(self); }