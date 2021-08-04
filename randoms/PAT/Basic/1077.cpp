/**
 * @file 1077.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805262303477760
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    double score, score1, score2;
    int tmp;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        score1 = score2 = 0;
        nums.clear();
        cin >> tmp;
        score1 = tmp;
        for(int j = 0; j < n-1; j++) {
            cin >> tmp;
            if(tmp >= 0 && tmp <= m) {
                nums.push_back(tmp);
            }
        }
        sort(nums.begin(), nums.end());
        for(int k = 1; k < nums.size()-1; k++) {
            score2 += nums[k];
        }
        score2 = (double)score2 / (nums.size()-2);
        score = (score1 + score2) / 2;
        printf("%d\n", (int)(score+0.5));
    }
    return 0;
}