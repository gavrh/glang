// base
#include <base/macros.h>
#include <base/new.h>
#include <base/platform.h>
// cli
#include <cli/emit.h>
#include <cli/help.h>
#include <cli/parse_command.h>
#include <cli/parse_config.h>
// command
// llvm
// c
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char** argv) {

    if (argc > 1) { 

      const char* command = argv[1];

#ifdef MSVC_VERSION
      Vec* options = NEW(Vec); // Vec<char*>*

      // 1. Get the rest of argv
      for (int i = 2; i < argc; i++)
        push__Vec(options, argv[i]);

      // 2. Parse comand
      const ParseCommand parse_command =
        NEW(ParseCommand, command, (const char**)options->buffer, argc - 2);
#else
      char* options[argc - 2];

      // 1. Get the rest of argv
      for (int i = argc; i >= 2; --i)
          options[argc - i - 1] = argv[i];

      // 2. Parse comand
      const ParseCommand parse_command =
        NEW(ParseCommand, command, (const char**)options, argc - 2);
#endif

        // options
        const Option option = run__ParseCommand(&parse_command);
        // parse config

        // switch through kinds
        switch (option.kind) {

          case OPTION_KIND_BUILD: printf("Command was 'build'\n"); break;
          case OPTION_KIND_CC: break;
          case OPTION_KIND_COMPILE: printf("Command was 'compile'\n"); break;
          case OPTION_KIND_CPP: break;
          case OPTION_KIND_INIT: break;
          case OPTION_KIND_NEW: break;
          case OPTION_KIND_RUN: printf("Command was 'run'\n"); break;
          case OPTION_KIND_TEST: break;
          case OPTION_KIND_TO: break;

        }

        // free
        #ifdef MSVC_VERSION
          FREE(Vec, options);
        #endif
        FREE(Option, option);

    } else printf("%s", DEFAULT_HELP);

    return 0;
}