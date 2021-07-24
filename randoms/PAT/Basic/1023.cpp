/**
 * @file 1023.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums;
    int n;

    for(int i = 0; i < 10; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            nums.push_back(i);
        }
    }

    sort(nums.begin(), nums.end());

    if(nums[0] != 0) {
        for(auto &i : nums) {
            cout << i;
        }
        return 0;
    }

    for(size_t i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            continue;
        }
        swap(nums[i], nums[0]);
        break;
    }
    for(auto &i : nums) {
        cout << i;
    }
    return 0;
}