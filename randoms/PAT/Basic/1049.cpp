/**
 * @file 1049.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805275792359424
 * @version 0.1
 * @date 2021-07-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
    int n;
    double num;
    // double ans = 0;
    ll ans = 0;

    cin >> n;
    int count = 1;
    for(int i = 0; i < n; i++) {
        cin >> num;
        // ans += num * (n-i) * count;
        ans += (ll)(num * 1000 * (n-i) * count);
        count++;
    }
    // printf("%.2f", ans);
    printf("%.2f", ans/1000.0);

    return 0;
}