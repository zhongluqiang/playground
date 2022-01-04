/**
 * @file 1002.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double coeff[1001] = {0}; // coeff[i]表示指数为i的项的系数
    int K, N;
    double AN;
    int ansK = 0; // A+B 中非零项的个数

    // 多项式A
    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> N >> AN;
        coeff[N] += AN;
    }
    // 多项式B
    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> N >> AN;
        coeff[N] += AN;
        if(fabs(coeff[N]) < 0.1) {
            coeff[N] = 0;
        }
    }

    for(int i = 0; i <= 1000; i++) {
        if(fabs(coeff[i])) {
            ansK++;
        }
    }
    cout << ansK;
    if(ansK > 0) {
        for(int i = 1000; i >= 0; i--) {
            if(fabs(coeff[i])) {
                printf(" %d %.1f", i, coeff[i]);
            }
        }
    }

    return 0;
}