#ifndef GLANG_CORE_TOKEN_H
#define GLANG_CORE_TOKEN_H


// token types
typedef enum TokenType {

    // important
    END_OF_FILE,
    IDENTIFER,
    TYPE,
    // assigners
    FUNCTION,       // fn
    STRUCT,         // struct
    CLASS,          // class
    ENUM,           // enum
    TYPEDEF,        // type
    // operands
    IF,             // 
    ELSE,
    THEN,
    DO,
    END,
    WHILE,
    // keywords
    RETURN,
    NIL,
    TRUE,
    FALSE,
    // mono-symbols
    EQUAL,          // =
    COLON,          // :
    SEMICOLON,      // ;
    BANG,           // !
    SHARP,          // #
    AROBASE,        // @
    DOLLAR,         // $
    CARET,          // ^
    AMPERSAND,      // &
    ASTERISK,       // *
    PAREN_L,        // (
    PAREN_R,        // )
    BRACE_L,        // [
    BRACE_R,        // ]
    BRACKET_L,      // {
    BRACKET_R,      // }
    DASH,           // -
    UNDERSCORE,     // _
    PLUS,           // +
    PIPE,           // |
    BCKSLASH,       /* \ */
    FWDSLASH,       // /
    QUOTE,          // "
    APSOTROPHE,     // '
    ACUTE,          // `
    TILDE,          // ~
    LESSER,         // <
    GREATER,        // >
    COMMA,          // ,
    PERIOD,         // .
    QUESTION,       // ?
    // di-symbols
    EQUALS,         // ==
    NOT_EQUALS,     // !=
    PLS_EQUALS,     // +=
    MIN_EQUALS,     // -=
    MUL_EQUALS,     // *=
    DIV_EQUALS,     // /=
    PLUS_PLUS,      // ++
    MIN_MIN,        // --
    AND_OP,         // &&
    OR_OP,          // ||

} TokenType;

// token struct
typedef struct Token {

    // Token(TokenType type, const char* value);

    TokenType   type;
    const char* value;
    int         line;
    int         index;



} Token;

// token list struct
typedef struct TokenList {

    Token**     tokens;

    // TokenList&  addToken(Token tok);
    // TokenList&  removeToken(int index);

} TokenList;


#endif // GLANG_CORE_TOKEN_H