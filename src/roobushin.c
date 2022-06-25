#include "include/token.h"
#include "include/lexer.h"
#include "include/parser.h"
#include "include/macros.h"
#include "include/io.h"

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

void roo_compile(char* src) {
    lexer_T* lexer = init_lexer(src);
    parser_T* parser = init_parser(lexer);
    AST_T* root = parser_parse(parser);
    token_T* tok = 0;

    while ((tok = lexer_next_token(lexer))->type != TOKEN_EOF) {
        printf("%s\n", token_to_str(tok));
    }
}

void roo_compile_file(const char* filename) {
    char* src = roo_rf(filename);
    printf("[DBG][ROO] SOURCE:\n%s\n======================[]======================\n", src);
    roo_compile(src);
    free(src);
}