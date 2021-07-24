/**
 * @file 1030.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805291311284224
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
    int N, p;
    vector<uint64_t> nums;
    
    cin >> N >> p;

    nums.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int ans = -1;
    int i, j, tmp = 0;
    uint64_t limit;
    for(i = 0; i < nums.size(); i++) {
        limit = nums[i] * p;
        for(j = tmp; j < nums.size(); j++) {
            if(nums[j] > limit) {
                break;
            }
            ans = max(ans, j - i + 1);
        }
        tmp = j;
    }
    cout << ans;

    return 0;
}