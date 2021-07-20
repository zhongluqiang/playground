/**
 * @file 1007.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744
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
    int ans = 0;

    cin >> n;
    if(n <= 4) {
        cout << 0;
        return 0;
    }

    // 埃拉托斯特尼筛法
    vector<bool> flag(n+1, true); // flag[0]~flag[n], flag[i]表示i是否是质数
    flag[0] = flag[1] = false;
    for(int i = 2, upperbound = sqrt(n); i <= upperbound; i++) {
        if(flag[i]) {
            for(int j = i*i; j <= n; j += i) {
                flag[j] = false;
            }
        }
    }

    for(int i = 2; i <= n-2; i++) {
        if(flag[i] && flag[i+2]) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}