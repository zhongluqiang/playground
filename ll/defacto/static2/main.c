#include <stdio.h>

extern void test(void);
extern int a;
extern int b;

int main() {
    test();
    printf("a=%d, b=%d\n", a, b);
    return 0;
}