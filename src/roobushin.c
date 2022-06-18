#include "include/token.h"
#include "include/lexer.h"
#include "include/macros.h"
#include "include/io.h"

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

void roo_compile(char* src) {
    lexer_T* lexer = init_lexer(src);
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