/**
 * @file 1010.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> polynomial;
    vector<int> ans;

    int n;
    while(cin >> n) {
        polynomial.push_back(n);
    }

    int coe, exp;
    size_t pos = 0;
    while(pos < polynomial.size()) {
        coe = polynomial[pos];
        exp = polynomial[pos+1];
        pos += 2;

        if(exp == 0) {
            break;
        }
        
        ans.push_back(coe * exp);
        ans.push_back(exp - 1);
    }

    if(ans.empty()) {
        cout << "0 0";
    } else {
        cout << ans[0];
        for(size_t i = 1; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
    }
    return 0;
}