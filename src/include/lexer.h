#ifndef LEXER_H
#define LEXER_H

#include "../include/token.h"
#include "../include/macros.h"

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"


typedef struct LEXER_STRUCT {
    char* src;
    size_t src_size;
    char c;
    unsigned int i;
} lexer_T;

lexer_T* init_lexer(char* src);
void lexer_advance(lexer_T* lexer);
char lexer_peek(lexer_T* lexer, int offset);
token_T* lexer_advance_with(lexer_T* lexer, token_T* token);
token_T* lexer_advance_current(lexer_T* lexer, int type);
void lexer_skip_whitespace(lexer_T* lexer);
token_T* lexer_parse_id(lexer_T* lexer);
token_T* lexer_parse_number(lexer_T* lexer);
token_T* lexer_next_token(lexer_T* lexer);

#endif