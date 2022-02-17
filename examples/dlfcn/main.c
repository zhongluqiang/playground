#define _GNU_SOURCE
#include <dlfcn.h>

#include <stdio.h>
#include <string.h>

int func(int a, int b) {
    Dl_info info;
    memset(&info, 0, sizeof(info));

    // void *pc = 0;

    // __asm__(
    //     "mov %0, pc\n"
    //     : "=r"(pc)
    //     :
    //     :);
    // printf("pc:%p\n", pc);
    // dladdr(pc, &info);
    dladdr(func, &info);
    if (info.dli_fname && info.dli_saddr) {
        printf("dli_fname:%s\n", info.dli_fname);
        printf("dli_fbase:%p\n", info.dli_fbase);
        printf("dli_sname:%s\n", info.dli_sname);
        printf("dli_saddr:%p\n", info.dli_saddr);
    }
    return 0;
}

int main() {
    Dl_info info;
    memset(&info, 0, sizeof(info));

    dladdr(main, &info);
    if (info.dli_fname && info.dli_saddr) {
        printf("dli_fname:%s\n", info.dli_fname);
        printf("dli_fbase:%p\n", info.dli_fbase);
        printf("dli_sname:%s\n", info.dli_sname);
        printf("dli_saddr:%p\n", info.dli_saddr);
    }

    func(1, 2);

    return 0;
}