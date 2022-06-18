#ifndef ROOBUSHIN_H
#define ROOBUSHIN_H

#include "token.h"
#include "lexer.h"
#include "macros.h"
#include "io.h"

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

void roo_compile(char* src);
void roo_compile_file(const char* filename);

#endif