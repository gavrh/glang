#ifndef GLANG_CLI_EMIT_H
#define GLANG_CLI_EMIT_H

#define EMIT_HELP(msg) printf("\x1b[33mhelp\x1b[0m: %s\n", msg)

#define EMIT_ERROR(msg) printf("\x1b[31merror\x1b[0m: %s\n", msg)

#define EMIT_NOTE(msg) printf("\x1b[31mnote\x1b[0m: %s\n", msg)

#endif // GLANG_CLI_EMIT_H