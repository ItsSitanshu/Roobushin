#include "include/roobushin.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("[F][ERROR] - Please provide a valid number of arguments\n");
        return -1;
    }
    roo_compile_file(argv[1]);
    return 0;
}