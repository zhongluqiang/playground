/**
 * @file 1070.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805264706813952
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int nums[10001] = {0};
    long double ans[10001];
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(begin(nums), begin(nums) + n);

    ans[0] = nums[0];
    for(int i = 1; i < n; i++) {
        ans[i] = (nums[i] + ans[i-1]) / 2.0; 
    }
    printf("%d\n", (int)ans[n-1]);
    return 0;
}