/**
 * @file 1060.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805269312159744
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    vector<int> nums;

    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());

    int ans = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > i+1) {
            ans = i+1;
        }
    }
    cout << ans;

    return 0;
}