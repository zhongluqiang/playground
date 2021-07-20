/**
 * @file 1005.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

static vector<int> do_callatz(int n) {
    vector<int> v;
    while(n != 1) {
        if(n & 0x1) {
            n = (n*3+1) >> 1;
        } else {
            n >>= 1;
        }
        v.push_back(n);
    }
    return v;
}

int main() {
    int n;
    set<int> nums;
    vector<int> flag(101); // flag[i]表示数字i是否可被推导
    vector<int> ans;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.insert(num);
    }

    for(const auto &i : nums) {
        if(flag[i]) {
            continue;
        }
        vector<int> child = do_callatz(i);
        for(auto c : child) {
            if(c > 100) {
                continue; // 计算过程中可能产生大于100的数字
            }
            flag[c] = 1;
        }
    }

    for(auto it = nums.rbegin(); it != nums.rend(); it++) {
        if(!flag[*it]) {
            ans.push_back(*it);
        }
    }
    cout << ans[0];
    for(size_t i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    return 0;
}