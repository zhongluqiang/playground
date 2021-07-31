/**
 * @file 1063.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805267860930560
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cmath>
using namespace std;

int main() {
    int n;
    long double a, b;
    long double ans = __LDBL_MIN__;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        ans = max(ans, sqrt(a*a + b*b));
    }

    printf("%.2Lf\n", ans);
    return 0;
}