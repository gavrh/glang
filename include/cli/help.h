#ifndef GLANG_CLI_HELP_H
#define GLANG_CLI_HELP_H

#include <cli/version.h>

#define BUILD_HELP                               \
    "Usage: glang build [options] [FILENAME]\n\n" \
    "Options:\n\n"                               \
    "  -h, --help      Print build's help"

#define CC_HELP                               \
    "Usage: glang cc [options] [FILENAME]\n\n" \
    "Options:\n\n"                            \
    "  -h, --help      Print cc's help"

#define COMPILE_HELP                               \
    "Usage: glang compile [options] [FILENAME]\n\n" \
    "Options:\n\n"                                 \
    "  --dump-scanner  Dump scanner output\n"      \
    "  --dump-parser   Dump parser output\n"       \
    "  --dump-tc       Dump typecheck output\n"    \
    "  --run-scanner   Run only the scanner\n"     \
    "  --run-parser    Run only the parser\n"      \
    "  --run-tc        Run only the typecheck\n"   \
    "  -h, --help      Print compile's help\n"

#define CPP_HELP                               \
    "Usage: glang c++ [options] [FILENAME]\n\n" \
    "Options:\n\n"                             \
    "  -h, --help      Print c++'s help"

#define INIT_HELP                           \
    "Usage: glang init [options] [PATH]\n\n" \
    "Options:\n\n"                          \
    "  -h, --help      Print init's help"

#define INSTALL_HELP                            \
    "Usage: glang install [options] [PATH]\n\n" \
    "Options:\n\n"                              \
    "  -h, --help      Print install's help"

#define NEW_HELP                           \
    "Usage: glang new [options] [NAME]\n\n" \
    "Options:\n\n"                         \
    "  -h, --help      Print new's help"

#define RUN_HELP                               \
    "Usage: glang run [options] [FILENAME]\n\n" \
    "Options:\n\n"                             \
    "  -h, --help      Print run's help"

#define TEST_HELP                               \
    "Usage: glang test [options] [FILENAME]\n\n" \
    "Options:\n\n"                              \
    "  -h, --help      Print test's help"

#define TO_HELP                               \
    "Usage: glang to [options] [FILENAME]\n\n" \
    "Options:\n\n"                            \
    "  -h, --help      Print to's help"

#define HELP                                       \
    "Usage: glang [command] [options]\n\n"          \
    "Commands:\n\n"                                \
    "  build           Build project\n"            \
    "  cc              C compiler\n"               \
    "  c++             C++ compiler\n"             \
    "  compile         Compile file\n"             \
    "  help            Print help command usage\n" \
    "  init            Init project\n"             \
    "  new             New project\n"              \
    "  run             Run file\n"                 \
    "  to              Transpile to...\n"          \
    "  version         Print version\n\n"          \
    "General Options:\n\n"                         \
    "  -h, --help      Print help command usage\n" \
    "  -v, --version   Print version"

#define DEFAULT_HELP                                                                                        \
        "glang <command>\n\n"                                                                               \
                                                                                                            \
        "Commands:\n\n"                                                                                     \
                                                                                                            \
        "   build, b    Compile the current project\n"                                                      \
        "   check, c    Analyze the current project and report erros, but don't build object files\n"       \
        "   clean       Remove the binary directory\n"                                                      \
        "   doc, d      Build this project's and its dependencies' documentation\n"                         \
        "   new         Create new glang project\n"                                                         \
        "   init        Create new glang project in an existing directory\n"                                \
        "   add         Add bundle to manifest file\n"                                                      \
        "   remove      Remove bunlde from manifest file\n"                                                 \
        "   run, r      Run a binary or example of the local project\n"                                     \
        "   test, t     Run the test\n"                                                                     \
        "   bench       Run the test\n"                                                                     \
        "   update      Update dependencies list in manfiest file\n"                                        \
        "   search      Search registry for bundles\n"                                                      \
        "   publish     Bundle and upload this project to the registry\n"                                   \
        "   install     Install a Glang binary. Default location is $HOME/.glang/bin\n"                     \
        "   uninstall   Uninstall the Glang binary\n\n"                                                     \
                                                                                                            \
        "See 'glang help <command>' for more information on a specific command.\n\n"                        \
                                                                                                            \
        "glang@" GLANG_VERSION " (" OS_NAME " " ARCH_NAME ")\n"                                             \

#endif // GLANG_CLI_HELP_H