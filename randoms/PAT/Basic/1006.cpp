/**
 * @file 1006.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805318855278592
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string ans;

    cin >> n;
    if(n <= 0 || n >= 1000) {
        return 0;
    }

    int hundreds = n / 100;
    int tens = n % 100 / 10;
    int units = n % 10;

    ans = string(hundreds, 'B') + string(tens, 'S');
    // if(units == 0) {
    //     ans.push_back('0');
    // }
    for(int i = 1; i <= units; i++) {
        ans.push_back('0' + i);
    }
    cout << ans;
    
    return 0;
}