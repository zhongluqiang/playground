/**
 * @file 1045.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805278589960192
 * @version 0.1
 * @date 2021-07-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    int nums[100001]     = {0};
    int maxleft[100001]  = {0};
    int minright[100001] = {0};
    set<int> ans;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    };

    maxleft[0]      = nums[0]; // maxleft[i]表示i左边最大的数
    minright[n - 1] = nums[n - 1]; // minright[i]表示i右边最小的数

    for (int i = 1; i <= n - 1; i++) {
        maxleft[i] = max(maxleft[i - 1], nums[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        minright[i] = min(minright[i + 1], nums[i + 1]);
    }

    for(int i = 0; i < n; i++) {
        if(maxleft[i] <= nums[i] && minright[i] >= nums[i]) {
            ans.insert(nums[i]);
        }
    }
    
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++) {
        if(it == ans.begin()) {
            cout << *it;
        } else {
            cout << " " << *it;
        }
    }
    
    cout << endl; // 这里要有一个换行，否则测试点2不通过，原因是0个输出也要独占一行

    return 0;
}