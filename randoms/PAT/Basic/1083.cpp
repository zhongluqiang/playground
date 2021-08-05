/**
 * @file 1083.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805260780945408
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    vector<int> nums(n);
    
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        nums[i] = abs(tmp - i - 1);
    }

    sort(nums.begin(), nums.end(), greater<int>());

    int p1, p2;
    p1 = p2 = 0;
    while (p1 < nums.size())
    {
        p2 = p1;
        while(p2 < nums.size() && nums[p2] == nums[p1]) {
            p2++;
        }
        if(p2 - p1 > 1) {
            cout << nums[p1] << " " << p2 - p1 << endl;
        }
        p1 = p2;
    }
    
    return 0;
}