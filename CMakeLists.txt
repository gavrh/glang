cmake_minimum_required(VERSION 3.24)
project(glang C)

# cmake standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# platform
if (WIN32)
    set(PLATFORM_WINDOWS true)
else()
    set(PLATFORM_WINDOWS false)

    # other
    add_compile_options(-Wall -03 -fdiagnostics-color=always)
endif()
if (UNIX)
    set(PLATFORM_UNIX true)
else()
    set(PLATFORM_UNIX false)
endif()

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# LLVM
find_package(LLVM CONFIG REQUIRED)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

# Base
set(BASE_SRC

    src/base/alloc.c
    src/base/atof.c
    src/base/atoi.c
    src/base/color.c
    src/base/file.c
    src/base/format.c
    src/base/hash_map.c
    src/base/hash_set.c
    src/base/itoa.c
    src/base/optional.c
    src/base/stack.c
    src/base/str.c  
    src/base/string.c
    src/base/test.c
    src/base/vec.c

)

# CLI
set(CLI_SRC

    src/cli/option.c
    src/cli/parse_command.c
    src/cli/parse_config.c
        # /config
        # /option
        src/cli/option/add.c
        src/cli/option/bench.c
        src/cli/option/build.c
        src/cli/option/cc.c
        src/cli/option/check.c
        src/cli/option/clean.c
        src/cli/option/compile.c
        src/cli/option/cpp.c
        src/cli/option/init.c
        src/cli/option/install.c
        src/cli/option/new.c
        src/cli/option/publish.c
        src/cli/option/remove.c
        src/cli/option/run.c
        src/cli/option/search.c
        src/cli/option/test.c
        src/cli/option/to.c
        src/cli/option/uninstall.c
        src/cli/option/update.c

)

# Command
set(COMMAND_SRC

    src/command/run/run.c

)


# Core
set(CORE_SRC

    # GLANG #
    src/core/g/analysis.c
    src/core/g/ast.c 
    src/core/g/checked.c
    src/core/g/error.c
    src/core/g/ir.c 
    src/core/g/package.c
    src/core/g/parser.c
    src/core/g/precompile.c
    src/core/g/preparser.c
    src/core/g/scanner.c
    src/core/g/token.c
    src/core/g/visibility.c
    src/core/g/warning.c
        # /ast
        src/core/g/ast/data_type.c
        src/core/g/ast/decl.c
        src/core/g/ast/expr.c
        src/core/g/ast/field_object.c
        src/core/g/ast/field.c
        src/core/g/ast/generic_param.c
        src/core/g/ast/impl_param.c
        src/core/g/ast/inherit_param.c
        src/core/g/ast/pattern.c
        src/core/g/ast/stmt.c
        src/core/g/ast/variant.c
            # /body
            src/core/g/ast/body/class.c
            src/core/g/ast/body/enum_object.c
            src/core/g/ast/body/fun.c
            src/core/g/ast/body/record_object.c
            src/core/g/ast/body/trait.c
            # /decl
            src/core/g/ast/decl/alias.c
            src/core/g/ast/decl/attribute.c
            src/core/g/ast/decl/class.c
            src/core/g/ast/decl/constant.c
            src/core/g/ast/decl/enum_object.c
            src/core/g/ast/decl/enum.c
            src/core/g/ast/decl/fun.c
            src/core/g/ast/decl/method.c
            src/core/g/ast/decl/prototype.c
            src/core/g/ast/decl/record_object.c
            src/core/g/ast/decl/record.c
            src/core/g/ast/decl/trait.c
            src/core/g/ast/decl/type.c
            # /expr
            src/core/g/ast/expr/access.c
            src/core/g/ast/expr/array.c
            src/core/g/ast/expr/binary.c
            src/core/g/ast/expr/call.c
            src/core/g/ast/expr/cast.c
            src/core/g/ast/expr/literal.c
            src/core/g/ast/expr/tuple.c
            src/core/g/ast/expr/unary.c
            # /pattern
            src/core/g/ast/pattern/array.c
            src/core/g/ast/pattern/as.c
            src/core/g/ast/pattern/exception.c
            src/core/g/ast/pattern/literal.c
            src/core/g/ast/pattern/name.c
            src/core/g/ast/pattern/range.c
            src/core/g/ast/pattern/record_call.c
            src/core/g/ast/pattern/tuple.c
            src/core/g/ast/pattern/variant_call.c
            # /stmt
            src/core/g/ast/stmt/asm.c
            src/core/g/ast/stmt/await.c
            src/core/g/ast/stmt/block.c
            src/core/g/ast/stmt/break.c
            src/core/g/ast/stmt/defer.c
            src/core/g/ast/stmt/drop.c
            src/core/g/ast/stmt/for.c
            src/core/g/ast/stmt/if.c
            src/core/g/ast/stmt/match.c
            src/core/g/ast/stmt/next.c
            src/core/g/ast/stmt/return.c
            src/core/g/ast/stmt/try.c
            src/core/g/ast/stmt/variable.c
            src/core/g/ast/stmt/while.c
        # /checked
        # /ir
        src/core/g/ir/cc.c
        src/core/g/ir/cpp.c
        src/core/g/ir/js.c
        src/core/g/ir/llvm.c
            # /cc
            src/core/g/ir/cc/builder.c
            src/core/g/ir/cc/generator.c
                # /generator
            # /cpp
            src/core/g/ir/cpp/builder.c
            src/core/g/ir/cpp/generator.c
                # /generator
            # /llvm
            src/core/g/ir/llvm/generator.c
            src/core/g/ir/llvm/linker.c
                # /generator
        # /package
        src/core/g/package/default_path.c
        src/core/g/package/dependency_tree.c
        src/core/g/package/library.c
        src/core/g/package/package.c

    # CC #
    src/core/cc/error.c
    src/core/cc/token.c
    src/core/cc/warning.c

    # CPP #
    src/core/cpp/error.c
    src/core/cpp/warning.c

    # SHARED #
    src/core/shared/cursor.c
    src/core/shared/diagnostic.c
    src/core/shared/location.c
    src/core/shared/source.c

)


# glang libs
add_library(g_base STATIC ${BASE_SRC})
target_include_directories(g_base PUBLIC include)

add_library(g_cli STATIC ${CLI_SRC})
target_link_libraries(g_cli g_base)

#add_library(g_command STATIC ${COMMMAND_SRC})
#target_link_libraries(g_command g_base g_cli g_core)

add_library(g_core STATIC ${CORE_SRC})
target_link_libraries(g_core g_base LLVM)
target_include_directories(g_core PUBLIC lib/local)

# exec & libs
add_executable(${PROJECT_NAME} src/bin/main.c)
target_link_libraries(${PROJECT_NAME}

    g_base
    g_cli

)
