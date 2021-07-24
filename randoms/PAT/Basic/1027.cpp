/**
 * @file 1027.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805294251491328
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    char c;

    cin >> n >> c;

    int w, k;

    w = 1;
    while((k = (w+1) * (w+1) / 2 - 1) <= n) {
        w += 2;
    }
    w -= 2;
    k = (w+1)*(w+1)/2 - 1;

    for(int i = w; i >= 1; i -= 2) {
        for(int j = 0; j < (w-i)/2; j++) {
            cout << ' ';
        }
        for(int j = 0; j < i; j++) {
            cout << c;
        }
        cout << endl;
    }

    for(int i = 3; i <= w; i += 2) {
        for(int j = 0; j < (w-i)/2; j++) {
            cout << ' ';
        }
        for(int j = 0; j < i; j++) {
            cout << c;

        }
        cout << endl;
    }

    cout << n-k;
}