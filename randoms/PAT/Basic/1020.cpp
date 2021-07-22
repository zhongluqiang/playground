/**
 * @file 1020.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805301562163200
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N, D;
    vector<double> store;
    vector<double> sell;
    vector<double> price;
    map<double, double, greater<double>> data; // 单价 -> 数量，按单价从大到小排序

    cin >> N >> D;

    store.resize(N);
    sell.resize(N);
    price.resize(N);
    double totalstore = 0;
    double totalsell = 0;

    for(int i = 0; i < N; i++) {
        cin >> store[i];
        totalstore += store[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> sell[i];
        totalsell += sell[i];
    }

    // 测试点3
    if(totalstore <= D) {
        printf("%.2f", totalsell);
        return 0;
    }

    for(int i = 0; i < N; i++) {
        data.insert({(double)sell[i]/store[i], store[i]});
    }

    double ans = 0;
    for(auto &i : data) {
        if(D <= 0) {
            break;
        }
        if(D <= i.second) {
            ans += i.first * D;
            break;
        }

        ans += i.first * i.second;
        D -= i.second;
    }

    printf("%.2f", ans);
    return 0;
}