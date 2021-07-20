/**
 * @file 1008.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808
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
    int N, M; //N个数，循环右移M位
    vector<int> nums;

    cin >> N >> M;
    M %= N;
    
    nums.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + M);
    reverse(nums.begin() + M, nums.end());

    cout << nums[0];
    for(size_t i = 1; i < nums.size(); i++) {
        cout << " " << nums[i];
    }

    return 0;
}