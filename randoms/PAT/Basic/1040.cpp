/**
 * @file 1040.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;


int main() {
    string pat;
    long long ans = 0;
    int countp = 0, counta = 0, countt = 0;

    cin >> pat;
    for(int i = 0; i < pat.size(); i++) {
        if(pat[i] == 'A') counta++;
        if(pat[i] == 'T') countt++;
    }

    for(int i = 0; i < pat.size(); i++) {
        if(pat[i] == 'A') {
            ans += countp * countt;
        } else if(pat[i] == 'T') {
            countt--;
        } else {
            countp++;
        }
    }
    cout << ans % 1000000007;
    return 0;
}