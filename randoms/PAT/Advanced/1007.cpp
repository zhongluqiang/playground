/**
 * @file 1007.cpp
 * @author midlane.top
 * @brief 1007 Maximum Subsequence Sum
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int K, nums[10001], sum[10001], ans = -1, head, tail;

    // 输入数组并计算前缀和，注意数组nums和前缀和数组sum都是从下标1开始存储有效数据
    cin >> K;
    for(int i = 1; i <= K; i++) {
        cin >> nums[i];
    }
    sum[0] = 0;
    for(int i = 1; i <= K; i++) {
        sum[i] = sum[i-1] + nums[i];
    }

    // 从小到大枚举序列的结束位置
    // 在固定结束位置的前提下，从0开始枚举sum[lowest]，如果sum[end]-sum[lowest]，则更新当前结果，
    // 每次计算时，如果sum[end]比sum[lowest]还要小，那么在移动end的同时，lowest也要更新为end，
    // 因为sum[lowest]要永远指向end之前的前缀和最小位置
    int lowest = 0;
    for(int end = 1; end <= K; end++) {
        if(sum[end] - sum[lowest] > ans) {
            ans = sum[end] - sum[lowest];
            head = nums[lowest+1];
            tail = nums[end];
        }
        if(sum[lowest] > sum[end]) lowest = end;
    }
    if(ans == -1) {
        cout << 0 << " " << nums[1] << " " << nums[K];
    } else {
        cout << ans << " " << head << " " << tail;
    }
    return 0;
}