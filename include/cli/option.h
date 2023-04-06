#ifndef GLANG_CLI_OPTION_H
#define GLANG_CLI_OPTION_H

// base
#include <base/macros.h>
// cli
#include <cli/option/build.h>
#include <cli/option/cc.h>
#include <cli/option/compile.h>
#include <cli/option/cpp.h>
#include <cli/option/init.h>
#include <cli/option/new.h>
#include <cli/option/run.h>
#include <cli/option/test.h>
#include <cli/option/to.h>

enum OptionKind {
    OPTION_KIND_BUILD,
    OPTION_KIND_CC,
    OPTION_KIND_COMPILE,
    OPTION_KIND_CPP,
    OPTION_KIND_INIT,
    OPTION_KIND_NEW,
    OPTION_KIND_RUN,
    OPTION_KIND_TEST,
    OPTION_KIND_TO,
};

typedef struct Option {
    enum OptionKind kind;
    union {
        Vec* build;     // Vec<BuildOption*>*
        Vec* cc;        // Vec<CcOption*>*
        Vec* compile;   // Vec<CompileOption*>*
        Vec* cpp;       // Vec<CppOption*>*
        Vec* init;      // Vec<InitOption*>*
        Vec* new;       // Vec<NewOption*>*
        Vec* run;       // Vec<RunOption*>*
        Vec* test;      // Vec<TestOption*>*
        Vec* to;        // Vec<ToOption*>*
    };
} Option;

// option constructors
inline VARIANT_CONSTRUCTOR(Option, Option, build, Vec* build) {
    return (Option){ .kind = OPTION_KIND_BUILD, .build = build };
}
inline VARIANT_CONSTRUCTOR(Option, Option, cc, Vec* cc) {
    return (Option){ .kind = OPTION_KIND_CC, .cc = cc }; 
}
inline VARIANT_CONSTRUCTOR(Option, Option, compile, Vec* compile) {
    return (Option){ .kind = OPTION_KIND_COMPILE, .compile = compile }; 
}
inline VARIANT_CONSTRUCTOR(Option, Option, cpp, Vec* cpp) {
    return (Option){ .kind = OPTION_KIND_CPP, .cpp = cpp }; 
}
inline VARIANT_CONSTRUCTOR(Option, Option, init, Vec* init) {
    return (Option){ .kind = OPTION_KIND_INIT, .init = init }; 
}
inline VARIANT_CONSTRUCTOR(Option, Option, new, Vec* new) {
    return (Option){ .kind = OPTION_KIND_NEW, .new = new }; 
}
inline VARIANT_CONSTRUCTOR(Option, Option, run, Vec* run) {
    return (Option){ .kind = OPTION_KIND_RUN, .run = run }; 
}
inline VARIANT_CONSTRUCTOR(Option, Option, test, Vec* test) {
    return (Option){ .kind = OPTION_KIND_TEST, .test = test }; 
}
inline VARIANT_CONSTRUCTOR(Option, Option, to, Vec* to) {
    return (Option){ .kind = OPTION_KIND_TO, .to = to }; 
}

// free option type
DESTRUCTOR(Option, Option* self);

#endif // GLANG_CLI_OPTION_H