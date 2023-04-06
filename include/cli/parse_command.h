#ifndef GLANG_CLI_PARSE_COMMAND_H
#define GLANG_CLI_PARSE_COMMAND_H

#include <base/macros.h>
#include <base/types.h>

#include <cli/command.h>
#include <cli/option.h>

typedef struct ParseCommand {

    const char* command;
    const char** options;
    const Usize options_size;
    enum  Command command_kind;

} ParseCommand;
// parse command constructor
CONSTRUCTOR(ParseCommand, ParseCommand, const char* command, const char** options, const Usize options_size);

// run parse command
Option run__ParseCommand(const ParseCommand* self);

#endif // GLANG_CLI_PARSE_COMMAND_H