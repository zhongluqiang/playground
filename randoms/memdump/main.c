#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>
#include <unistd.h>

#include "memdump.h"

static void usage(void) {
    printf("Usage: ./memdump file [2|8|10|16]\n");
    printf("example: ./memdump data.bin 16\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        usage();
        return -1;
    }

    struct stat s;
    assert(!stat(argv[1], &s));
    printf("size:%ld\n", s.st_size);
    unsigned char *p = malloc(s.st_size);
    assert(p);
    FILE *fp = fopen(argv[1], "r");
    assert(fp);
    fread(p, s.st_size, 1, fp);
    fclose(fp);
    memdump(p, s.st_size, atoi(argv[2]));
    free(p);
    return 0;
}