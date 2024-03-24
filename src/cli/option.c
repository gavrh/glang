// base
#include <base/new.h>
// cli
#include <cli/option.h>
// c
#include <stdio.h>
#include <stdlib.h>

// Free Option type (OPTION_KIND_BUILD).
static VARIANT_DESTRUCTOR(Option, build, Option self);

// Free Option type (OPTION_KIND_CC).
static VARIANT_DESTRUCTOR(Option, cc, Option self);

// Free Option type (OPTION_KIND_COMPILE).
static VARIANT_DESTRUCTOR(Option, compile, Option self);

// Free Option type (OPTION_KIND_CPP).
static VARIANT_DESTRUCTOR(Option, cpp, Option self);

// Free Option type (OPTION_KIND_INIT).
static VARIANT_DESTRUCTOR(Option, init, Option self);

// Free Option type (OPTION_KIND_NEW).
static VARIANT_DESTRUCTOR(Option, new, Option self);

// Free Option type (OPTION_KIND_RUN).
static VARIANT_DESTRUCTOR(Option, run, Option self);

// Free Option type (OPTION_KIND_TEST).
static VARIANT_DESTRUCTOR(Option, test, Option self);

// Free Option type (OPTION_KIND_TO).
static VARIANT_DESTRUCTOR(Option, to, Option self);

VARIANT_DESTRUCTOR(Option, add, Option self) {
    FREE_BUFFER_ITEMS(self.add->buffer, self.add->len, BuildOption);
    FREE(Vec, self.add);
}
VARIANT_DESTRUCTOR(Option, build, Option self) {
    FREE_BUFFER_ITEMS(self.build->buffer, self.build->len, BuildOption);
    FREE(Vec, self.build);
}
VARIANT_DESTRUCTOR(Option, cc, Option self) {
    FREE_BUFFER_ITEMS(self.cc->buffer, self.cc->len, RunOption);
    FREE(Vec, self.cc);
}
VARIANT_DESTRUCTOR(Option, compile, Option self) {
    FREE_BUFFER_ITEMS(self.compile->buffer, self.compile->len, CompileOption);
    FREE(Vec, self.compile);
}
VARIANT_DESTRUCTOR(Option, cpp, Option self) {
    FREE_BUFFER_ITEMS(self.cpp->buffer, self.cpp->len, RunOption);
    FREE(Vec, self.cpp);
}
VARIANT_DESTRUCTOR(Option, init, Option self) {
    FREE_BUFFER_ITEMS(self.init->buffer, self.init->len, InitOption);
    FREE(Vec, self.init);
}
// VARIANT_DESTRUCTOR(Option, install, Option self) {
//     FREE_BUFFER_ITEMS(self.install->buffer, self.install->len, InstallOption);
//     FREE(Vec, self.install);
// }
VARIANT_DESTRUCTOR(Option, new, Option self) {
    FREE_BUFFER_ITEMS(self.new->buffer, self.new->len, RunOption);
    FREE(Vec, self.new);
}
VARIANT_DESTRUCTOR(Option, run, Option self) {
    FREE_BUFFER_ITEMS(self.run->buffer, self.run->len, RunOption);
    FREE(Vec, self.run);
}
VARIANT_DESTRUCTOR(Option, test, Option self) {
    FREE_BUFFER_ITEMS(self.test->buffer, self.test->len, RunOption);
    FREE(Vec, self.test);
}
VARIANT_DESTRUCTOR(Option, to, Option self) {
    FREE_BUFFER_ITEMS(self.to->buffer, self.to->len, RunOption);
    FREE(Vec, self.to);
}

DESTRUCTOR(Option, Option self) {
    switch (self.kind) {
        case OPTION_KIND_BUILD:
            FREE_VARIANT(Option, build, self);
            break;
        case OPTION_KIND_CC:
            FREE_VARIANT(Option, cc, self);
            break;
        case OPTION_KIND_COMPILE:
            FREE_VARIANT(Option, compile, self);
            break;
        case OPTION_KIND_CPP:
            FREE_VARIANT(Option, cpp, self);
            break;
        case OPTION_KIND_INIT:
            FREE_VARIANT(Option, init, self);
            break;
        case OPTION_KIND_NEW:
            FREE_VARIANT(Option, new, self);
            break;
        case OPTION_KIND_RUN:
            FREE_VARIANT(Option, run, self);
            break;
        case OPTION_KIND_TEST:
            FREE_VARIANT(Option, test, self);
            break;
        case OPTION_KIND_TO:
            FREE_VARIANT(Option, to, self);
            break;
        default:
            UNREACHABLE("unknown variant");
    }
}