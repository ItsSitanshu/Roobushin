#ifndef IO_H
#define IO_H

#ifndef _GNU_SOURCE
    #define _GNU_SOURCE
#endif

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

char* roo_rf(const char* filename);

#endif