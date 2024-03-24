#ifndef GLANG_CLI_OPTION_INSTALL_H
#define GLANG_CLI_OPTION_INSTALL_H

// base
#include <base/macros.h>
#include <base/vec.h>


// install option kinds
enum InstallOptionKind {

    INSTALL_OPTION_KIND_ERROR,
    INSTALL_OPTION_KIND_HELP,
    INSTALL_OPTION_KIND_PACKAGE,
    INSTALL_OPTION_KIND_GLOBAL,     // -g, --global

};

// install option struct
typedef struct InstallOption {

    enum InstallOptionKind kind;
    union {
        const char* error;
        const char* package;
    };

} InstallOption;

// install option constructors
CONSTRUCTOR(
    InstallOption*,
    InstallOption,
    enum InstallOptionKind kind
);
VARIANT_CONSTRUCTOR(
    InstallOption*,
    InstallOption,
    error,
    const char* error
);
VARIANT_CONSTRUCTOR(
    InstallOption*,
    InstallOption,
    package,
    const char* package
);

// parse install options
Vec* parse__InstallOption(const char** options, const Usize options_size);

#endif // GLANG_CLI_OPTION_INSTALL_H