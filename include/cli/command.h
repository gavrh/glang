#ifndef GLANG_CLI_COMMAND_H
#define GLANG_CLI_COMMAND_H

enum Command {
    COMMAND_BUILD,      // glang build <options>
    COMMAND_CC,         // glang cc <options>
    COMMAND_COMPILE,    // glang compile <options>
    COMMAND_CPP,        // glang cpp <options>
    COMMAND_INIT,       // glang init <options>
    COMMAND_INSTALL,    // glang install <options>
    COMMAND_NEW,        // glang new <options>
    COMMAND_RUN,        // glang run <options>
    COMMAND_TEST,       // glang test <options>
    COMMAND_TO,         // glang to <options>
    COMMAND_HELP,       // glang help
    COMMAND_VERSION,    // glang version
    COMMAND_ERROR
};

#endif // GLANG_CLI_COMMAND_H