/**
 * @file 1008.cpp
 * @author midlane.top
 * @brief 1008 Elevator
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int N, nums[100];
    int ans = 0;
    int start = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    ans += N * 5; // 每层楼固定停留5秒
    for(int i = 0; i < N; i++) {
        int cur = nums[i];
        if(cur == start) {
            continue;
        }
        if(cur > start) {
            ans += (cur - start) * 6; // 上楼
        } else {
            ans += (start - cur) * 4; // 下楼
        }
        start = cur;
    }
    cout << ans;
    return 0;
}