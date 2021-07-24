/**
 * @file 1026.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805295203598336
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
using namespace std;

static int round_div(int x, int y) {
    int div = x / y;
    int left = x % y;
    if(left*2 < y) {
        return div;
    } else {
        return div+1;
    }
}

int main() {
    int C1, C2;
    
    cin >> C1 >> C2;

    int seconds = round_div((C2 - C1), 100);

    printf("%02d:%02d:%02d", seconds/3600, seconds%3600 / 60, seconds % 60);

    return 0;
}