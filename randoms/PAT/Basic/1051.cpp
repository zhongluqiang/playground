/**
 * @file 1051.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805274496319488
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cstdio>
#include <cmath>

int main() {
    long double r1, p1, r2, p2;
    
    scanf("%Lf %Lf %Lf %Lf", &r1, &p1, &r2, &p2);

    long double real = r1 * r2 * cos(p1 + p2);
    long double imag = r1 * r2 * sin(p1 + p2);

    if(fabsl(real) < 0.005) {
        printf("0");
    } else {
        printf("%.2Lf", real);
    }

    if(fabsl(imag) < 0.005) {
        printf("+0.00");
    } else if(imag < 0) {
        printf("%.2Lfi", imag);
    } else {
        printf("+%.2Lfi", imag);
    }
    printf("\n");
    return 0;
}