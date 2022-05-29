#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct ROOFILE {
    char* self_fn;
    char* prcself_fn;
    FILE* self;
    FILE* prc_self;
    int chars;
} ROOFILE;


FILE* rf(char* filename, char* mode);
FILE* mf(char* filename);
void close_file(ROOFILE* file);
void start(char* filename);