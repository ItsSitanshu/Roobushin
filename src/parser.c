#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "parser.h"


FILE* rf(char* filename, char* mode) {
    FILE* fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("Couldn't open filename '%s'\n", filename);
        exit(-1);
    }
    return fp;
}

FILE* mf(char* filename) {
    FILE* fp = fopen(filename, "a+");
    return fp;
}

void close_file(ROOFILE* file) {
    fclose(file->self);
    // fclose(file->prc_self);
}

void start(char* filename) {
    ROOFILE* file = malloc(sizeof(ROOFILE));
    file->self_fn = filename;
    // file->prcself_fn = strcat(filename, ".prc");
    file->self = rf(file->self_fn, "r");
    // file->prc_self = mf(file->prcself_fn);
    int _chars;
    while ((fgetc(file->self)) != EOF) {
		_chars++; // number of chars in the read file obj
	}
    file->chars = _chars;
    printf("%d\n", file->chars);
    close_file(file);
}