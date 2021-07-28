/**
 * @file 1053.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805273284165632
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    double e;
    int d;
    vector<vector<double>> data; // data[i]是第i户的用电统计
    int maybe = 0, must = 0;

    int k;
    double tmp;
    vector<double> nums;

    cin >> n >> e >> d;
    for(int i = 0; i < n; i++) {
        nums.clear();
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> tmp;
            nums.push_back(tmp);
        }
        data.push_back(nums);
    }

    for(auto &v : data) {
        int size = v.size();
        int count = 0;
        for(auto i : v) {
            if(i < e) {
                count++;
            }
        }
        if(count > size / 2) {
            maybe++;
            if(size > d) {
                must++;
                maybe--;
            }
        }
    }
    printf("%.1f%% %.1f%%\n", (double)maybe/n*100, (double)must/n*100);
    return 0;
}