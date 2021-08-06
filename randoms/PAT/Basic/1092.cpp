/**
 * @file 1092.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1071785779399028736
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;
    vector<int> sum(n, 0);
    int tmp;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> tmp;
            sum[j] += tmp;
        }
    }
    int ans = *max_element(sum.begin(), sum.end());
    cout << ans << endl;
    bool first = true;
    for(int i = 0; i < n; i++) {
        if(sum[i] == ans) {
            if(first) {
                cout << i+1;
                first = false;
            } else {
                cout << " " << i+1;
            }
        }
    }
    return 0;
}