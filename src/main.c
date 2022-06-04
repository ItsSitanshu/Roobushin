// Roobushin Copyright (C) 2022 Sitanshu Shrestha(bit.ly/sitanshu) / GNU General Public License
#include "stdio.h"
#include "stdlib.h"

#include "all.h"

int main(int argc, char * argv[]) {
    if (argc < 2) {
        printf("Too few arguments were passed.");
    };
    start(argv[1]);
    return 0;
}