#ifndef GLANG_CLI_HELP_H
#define GLANG_CLI_HELP_H

#include <cli/version.h>

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
        "glang@" GLANG_VERSION " (" OS_NAME " " ARCH_NAME ")"                                               \

#endif // GLANG_CLI_HELP_H