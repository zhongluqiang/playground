/**
 * @file 1001.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b, sum;
    cin >> a >> b;
    sum = a + b;
    if(sum < 0) {
        printf("-");
        sum = -sum;
    }
    if(sum < 1000) {
        printf("%d", sum);
    } else if(sum < 1000000) {
        printf("%d,",sum / 1000);
        printf("%03d", sum % 1000);
    } else {
        printf("%d,",sum / 1000000);
        printf("%03d,",sum % 1000000 / 1000);
        printf("%03d", sum % 1000);
    }
    return 0;
}