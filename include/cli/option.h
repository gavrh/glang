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
    OPTION_KIND_ADD,
    OPTION_KIND_BENCH,
    OPTION_KIND_BUILD,
    OPTION_KIND_CC,
    OPTION_KIND_CHECK,
    OPTION_KIND_CLEAN,
    OPTION_KIND_COMPILE,
    OPTION_KIND_CPP,
    OPTION_KIND_INIT,
    OPTION_KIND_INSTALL,
    OPTION_KIND_NEW,
    OPTION_KIND_PUBLISH,
    OPTION_KIND_REMOVE,
    OPTION_KIND_RUN,
    OPTION_KIND_SEARCH,
    OPTION_KIND_TEST,
    OPTION_KIND_TO,
    OPTION_KIND_UNINSTALL,
    OPTION_KIND_UPDATE
};

typedef struct Option {
    enum OptionKind kind;
    union {
        Vec* add;       // Vec<AddOption*>*
        Vec* bench;     // Vec<BenchOption*>*
        Vec* build;     // Vec<BuildOption*>*
        Vec* cc;        // Vec<CcOption*>*
        Vec* check;     // Vec<CheckOption*>*
        Vec* clean;     // Vec<CleanOption*>*
        Vec* compile;   // Vec<CompileOption*>*
        Vec* cpp;       // Vec<CppOption*>*
        Vec* init;      // Vec<InitOption*>*
        Vec* install;   // Vec<InstallOption*>*
        Vec* new;       // Vec<NewOption*>*
        Vec* publish;   // Vec<PublishOption*>*
        Vec* remove;    // Vec<RemoveOption*>*
        Vec* run;       // Vec<RunOption*>*
        Vec* search;    // Vec<SearchOption*>*
        Vec* test;      // Vec<TestOption*>*
        Vec* to;        // Vec<ToOption*>*
        Vec* uninstall; // Vec<UninstallOption*>*
        Vec* update;    // Vec<UpdateOption*>*
    };
} Option;

// option constructors
static inline VARIANT_CONSTRUCTOR(Option, Option, build, Vec* build) {
    return (Option){ .kind = OPTION_KIND_BUILD, .build = build };
}
static inline VARIANT_CONSTRUCTOR(Option, Option, cc, Vec* cc) {
    return (Option){ .kind = OPTION_KIND_CC, .cc = cc }; 
}
static inline VARIANT_CONSTRUCTOR(Option, Option, compile, Vec* compile) {
    return (Option){ .kind = OPTION_KIND_COMPILE, .compile = compile }; 
}
static inline VARIANT_CONSTRUCTOR(Option, Option, cpp, Vec* cpp) {
    return (Option){ .kind = OPTION_KIND_CPP, .cpp = cpp }; 
}
static inline VARIANT_CONSTRUCTOR(Option, Option, init, Vec* init) {
    return (Option){ .kind = OPTION_KIND_INIT, .init = init }; 
}
static inline VARIANT_CONSTRUCTOR(Option, Option, new, Vec* new) {
    return (Option){ .kind = OPTION_KIND_NEW, .new = new }; 
}
static inline VARIANT_CONSTRUCTOR(Option, Option, run, Vec* run) {
    return (Option){ .kind = OPTION_KIND_RUN, .run = run }; 
}
static inline VARIANT_CONSTRUCTOR(Option, Option, test, Vec* test) {
    return (Option){ .kind = OPTION_KIND_TEST, .test = test }; 
}
static inline VARIANT_CONSTRUCTOR(Option, Option, to, Vec* to) {
    return (Option){ .kind = OPTION_KIND_TO, .to = to }; 
}

// free option type
DESTRUCTOR(Option, Option self);

#endif // GLANG_CLI_OPTION_H