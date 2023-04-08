#ifndef GLANG_CORE_G_TOKEN_H
#define GLANG_CORE_G_TOKEN_H

// base
#include <base/macros.h>
#include <base/string.h>
#include <base/types.h>
#include <base/vec.h>
// core
#include <core/shared/location.h>


enum GlangTokenKind {

    GLANG_TOKEN_KIND_AMPERSAND_EQ,
    GLANG_TOKEN_KIND_AMPERSAND,
    GLANG_TOKEN_KIND_ARROW,
    GLANG_TOKEN_KIND_AT,
    GLANG_TOKEN_KIND_BANG,
    GLANG_TOKEN_KIND_BAR_EQ,
    GLANG_TOKEN_KIND_BAR_R_SHIFT,
    GLANG_TOKEN_KIND_BAR,
    GLANG_TOKEN_KIND_COLON_COLON,
    GLANG_TOKEN_KIND_COLON_DOLLAR,
    GLANG_TOKEN_KIND_COLON_EQ,
    GLANG_TOKEN_KIND_COLON,
    GLANG_TOKEN_KIND_COMMA,
    GLANG_TOKEN_KIND_COMMENT_BLOCK,
    #ifdef ENV_DEBUG
    GLANG_TOKEN_KIND_COMMENT_DEBUG,
    #endif
    GLANG_TOKEN_KIND_COMMENT_DOC,
    GLANG_TOKEN_KIND_COMMENT_LINE,
    GLANG_TOKEN_KIND_DOLLAR,
    GLANG_TOKEN_KIND_DOT_DOT_DOT,
    GLANG_TOKEN_KIND_DOT_DOT,
    GLANG_TOKEN_KIND_DOT_INTERROGATION,
    GLANG_TOKEN_KIND_DOT_STAR,
    GLANG_TOKEN_KIND_DOT,
    GLANG_TOKEN_KIND_EOF,
    GLANG_TOKEN_KIND_EQ_EQ,
    GLANG_TOKEN_KIND_EQ,
    GLANG_TOKEN_KIND_FAT_ARROW,
    GLANG_TOKEN_KIND_HASHTAG,
    GLANG_TOKEN_KIND_HAT_EQ,
    GLANG_TOKEN_KIND_HAT,
    GLANG_TOKEN_KIND_IDENTIFIER_DOLLAR,
    GLANG_TOKEN_KIND_IDENTIFIER_MACRO,
    GLANG_TOKEN_KIND_IDENTIFIER_NORMAL,
    GLANG_TOKEN_KIND_IDENTIFIER_OPERATOR,
    GLANG_TOKEN_KIND_INTERROGATION,
    GLANG_TOKEN_KIND_INVERSE_ARROW,
    GLANG_TOKEN_KIND_KEYWORD_ALIAS,
    GLANG_TOKEN_KIND_KEYWORD_AND,
    GLANG_TOKEN_KIND_KEYWORD_AS,
    GLANG_TOKEN_KIND_KEYWORD_ASM,
    GLANG_TOKEN_KIND_KEYWORD_ASYNC,
    GLANG_TOKEN_KIND_KEYWORD_AWAIT,
    GLANG_TOKEN_KIND_KEYWORD_BEGIN,
    GLANG_TOKEN_KIND_KEYWORD_BREAK,
    GLANG_TOKEN_KIND_KEYWORD_CAST,
    GLANG_TOKEN_KIND_KEYWORD_CATCH,
    GLANG_TOKEN_KIND_KEYWORD_CLASS,
    GLANG_TOKEN_KIND_KEYWORD_COMPTIME,
    GLANG_TOKEN_KIND_KEYWORD_DEFER,
    GLANG_TOKEN_KIND_KEYWORD_DO,
    GLANG_TOKEN_KIND_KEYWORD_DROP,
    GLANG_TOKEN_KIND_KEYWORD_ELIF,
    GLANG_TOKEN_KIND_KEYWORD_ELSE,
    GLANG_TOKEN_KIND_KEYWORD_END,
    GLANG_TOKEN_KIND_KEYWORD_ENUM,
    GLANG_TOKEN_KIND_KEYWORD_ERROR,
    GLANG_TOKEN_KIND_KEYWORD_FALSE,
    GLANG_TOKEN_KIND_KEYWORD_FOR,
    GLANG_TOKEN_KIND_KEYWORD_FUN,
    GLANG_TOKEN_KIND_KEYWORD_GET,
    GLANG_TOKEN_KIND_KEYWORD_GLOBAL,
    GLANG_TOKEN_KIND_KEYWORD_IF,
    GLANG_TOKEN_KIND_KEYWORD_IMPL,
    GLANG_TOKEN_KIND_KEYWORD_IMPORT,
    GLANG_TOKEN_KIND_KEYWORD_IN,
    GLANG_TOKEN_KIND_KEYWORD_INCLUDE,
    GLANG_TOKEN_KIND_KEYWORD_INHERIT,
    GLANG_TOKEN_KIND_KEYWORD_IS,
    GLANG_TOKEN_KIND_KEYWORD_MACRO,
    GLANG_TOKEN_KIND_KEYWORD_MATCH,
    GLANG_TOKEN_KIND_KEYWORD_MODULE,
    GLANG_TOKEN_KIND_KEYWORD_MUT,
    GLANG_TOKEN_KIND_KEYWORD_NEXT,
    GLANG_TOKEN_KIND_KEYWORD_NIL,
    GLANG_TOKEN_KIND_KEYWORD_NONE,
    GLANG_TOKEN_KIND_KEYWORD_NOT,
    GLANG_TOKEN_KIND_KEYWORD_object,
    GLANG_TOKEN_KIND_KEYWORD_OBJECT,
    GLANG_TOKEN_KIND_KEYWORD_OR,
    GLANG_TOKEN_KIND_KEYWORD_PACKAGE,
    GLANG_TOKEN_KIND_KEYWORD_PUB,
    GLANG_TOKEN_KIND_KEYWORD_RAISE,
    GLANG_TOKEN_KIND_KEYWORD_RECORD,
    GLANG_TOKEN_KIND_KEYWORD_REF,
    GLANG_TOKEN_KIND_KEYWORD_REQ,
    GLANG_TOKEN_KIND_KEYWORD_RETURN,
    GLANG_TOKEN_KIND_KEYWORD_self,
    GLANG_TOKEN_KIND_KEYWORD_SELF,
    GLANG_TOKEN_KIND_KEYWORD_SET,
    GLANG_TOKEN_KIND_KEYWORD_TEST,
    GLANG_TOKEN_KIND_KEYWORD_TRACE,
    GLANG_TOKEN_KIND_KEYWORD_TRAIT,
    GLANG_TOKEN_KIND_KEYWORD_TRUE,
    GLANG_TOKEN_KIND_KEYWORD_TRY,
    GLANG_TOKEN_KIND_KEYWORD_TYPE,
    GLANG_TOKEN_KIND_KEYWORD_UNDEF,
    GLANG_TOKEN_KIND_KEYWORD_UNSAFE,
    GLANG_TOKEN_KIND_KEYWORD_USE,
    GLANG_TOKEN_KIND_KEYWORD_VAL,
    GLANG_TOKEN_KIND_KEYWORD_WHEN,
    GLANG_TOKEN_KIND_KEYWORD_WHILE,
    GLANG_TOKEN_KIND_KEYWORD_XOR,
    GLANG_TOKEN_KIND_L_BRACE,
    GLANG_TOKEN_KIND_L_HOOK,
    GLANG_TOKEN_KIND_L_PAREN,
    GLANG_TOKEN_KIND_L_SHIFT_EQ,
    GLANG_TOKEN_KIND_L_SHIFT_L_SHIFT_EQ,
    GLANG_TOKEN_KIND_L_SHIFT_L_SHIFT,
    GLANG_TOKEN_KIND_L_SHIFT,
    GLANG_TOKEN_KIND_LITERAL_BYTE,
    GLANG_TOKEN_KIND_LITERAL_BYTES,
    GLANG_TOKEN_KIND_LITERAL_CHAR,
    GLANG_TOKEN_KIND_LITERAL_FLOAT,
    GLANG_TOKEN_KIND_LITERAL_INT_2,
    GLANG_TOKEN_KIND_LITERAL_INT_8,
    GLANG_TOKEN_KIND_LITERAL_INT_10,
    GLANG_TOKEN_KIND_LITERAL_INT_16,
    GLANG_TOKEN_KIND_LITERAL_STRING,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_FLOAT32,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_FLOAT64,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_INT16,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_INT32,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_INT64,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_INT8,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_ISIZE,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_UINT16,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_UINT32,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_UINT64,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_UINT8,
    GLANG_TOKEN_KIND_LITERAL_SUFFIX_USIZE,
    GLANG_TOKEN_KIND_MINUS_EQ,
    GLANG_TOKEN_KIND_MINUS_MINUS_EQ,
    GLANG_TOKEN_KIND_MINUS_MINUS,
    GLANG_TOKEN_KIND_MINUS,
    GLANG_TOKEN_KIND_NOT_EQ,
    GLANG_TOKEN_KIND_PERCENTAGE_EQ,
    GLANG_TOKEN_KIND_PERCENTAGE,
    GLANG_TOKEN_KIND_PLUS_EQ,
    GLANG_TOKEN_KIND_PLUS_PLUS_EQ,
    GLANG_TOKEN_KIND_PLUS_PLUS,
    GLANG_TOKEN_KIND_PLUS,
    GLANG_TOKEN_KIND_R_BRACE,
    GLANG_TOKEN_KIND_R_HOOK,
    GLANG_TOKEN_KIND_R_PAREN,
    GLANG_TOKEN_KIND_R_SHIFT_EQ,
    GLANG_TOKEN_KIND_R_SHIFT_R_SHIFT_EQ,
    GLANG_TOKEN_KIND_R_SHIFT_R_SHIFT,
    GLANG_TOKEN_KIND_R_SHIFT,
    GLANG_TOKEN_KIND_SEMICOLON,
    GLANG_TOKEN_KIND_SLASH_EQ,
    GLANG_TOKEN_KIND_SLASH,
    GLANG_TOKEN_KIND_STAR_EQ,
    GLANG_TOKEN_KIND_STAR_STAR_EQ,
    GLANG_TOKEN_KIND_STAR_STAR,
    GLANG_TOKEN_KIND_STAR,
    GLANG_TOKEN_KIND_WAVE_EQ,
    GLANG_TOKEN_KIND_WAVE,
    GLANG_TOKEN_KIND_XOR_EQ
};

typedef struct GlangToken {

    enum GlangTokenKind kind;
    // Location location;
    union {
        #ifdef ENV_DEBUG
        String* comment_debug;
        #endif
        String* comment_doc;
        String* identifier_dollar;
        String* identifier_macro;
        String* identifier_normal;
        String* identifier_operator;
        Uint8   literal_byte;
        Uint8   literal_bytes;
        char    literal_char;
        String* literal_float;
        String* literal_int_2;
        String* literal_int_8;
        String* literal_int_10;
        String* literal_int_16;
        String* literal_string;
        Float32 literal_suffix_float32;
        Float64 literal_suffix_float64;
        Int16   literal_suffix_int16;
        Int32   literal_suffix_int32;
        Int64   literal_suffix_int64;
        Int8    literal_suffix_int8;
        Isize   literal_suffix_isize;
        Uint16  literal_suffix_uint16;
        Uint32  literal_suffix_uint32;
        Uint64  literal_suffix_uint64;
        Uint8   literal_suffix_uint8;
        Usize   literal_suffix_usize;
    };

} GlangToken;

// glang token constructor
CONSTRUCTOR(GlangToken*, GlangToken, enum GlangTokenKind kind, Location location);

// glang token variants
#ifdef ENV_DEBUG
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, comment_debug, Location location, String* comment_debug);
#endif
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, comment_doc, Location location, String* comment_doc);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, identifier_dollar, Location location, String* identifier_dollar);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, identifier_macro, Location location, String* identifier_macro);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, identifier_normal, Location location, String* identifier_normal);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, identifier_operator, Location location, String* identifier_operator);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_byte, Location location, Uint8 literal_byte);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_bytes, Location location, Uint8 literal_bytes);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_char, Location location, char literal_char);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_float, Location location, String* literal_float);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_int_2, Location location, String* literal_int_2);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_int_8, Location location, String* literal_int_8);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_int_10, Location location, String* literal_int_10);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_int_16, Location location, String* literal_int_16);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_string, Location location, String* literal_string);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_float32, Location location, Float32 literal_suffix_float32);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_float64, Location location, Float64 literal_suffix_float64);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_int16, Location location, Int16 literal_suffix_int16);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_int32, Location location, Int32 literal_suffix_int32);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_int64, Location location, Int64 literal_suffix_int64);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_int8, Location location, Int8 literal_suffix_int8);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_isize, Location location, Isize literal_suffix_isize);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_uint16, Location location, Uint16 literal_suffix_uint16);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_uint32, Location location, Uint32 literal_suffix_uint32);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_uint64, Location location, Uint64 literal_suffix_uint64);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_uint8, Location location, Uint8 literal_suffix_uint8);
VARIANT_CONSTRUCTOR(GlangToken*, GlangToken, literal_suffix_usize, Location location, Usize literal_suffix_usize);

// glang token functions
#ifdef ENV_DEBUG
IMPL_FOR_DEBUG(to_string, GlangTokenKind, enum GlangTokenKind self);
#endif
#ifdef ENV_DEBUG
char* IMPL_FOR_DEBUG(to_string, GlangToken, const GlangToken* self);
#endif
#ifdef ENV_DEBUG
void IMPL_FOR_DEBUG(debug, GlangToken, const GlangToken* self);
#endif
GlangToken* clone__GlangToken(const GlangToken* self);

// free glang token
DESTRUCTOR(GlangToken, GlangToken* self);


#endif // GLANG_CORE_G_TOKEN_H