/**
 * @file 1025.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805296180871168
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int first, N, K;
    int tmp;
    int data[100005], next[100005], list[100005];
    
    cin >> first >> N >> K;
    
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        cin >> data[tmp] >> next[tmp];
    }

    int sum = 0; // 统计链表有效节点数
    while(first != -1) {
        list[sum++] = first;
        first = next[first];
    }

    for(int i = 0; i < (sum - sum % K); i+= K) {
        reverse(begin(list) + i, begin(list) + i + K);
    }

    for(int i = 0; i < sum - 1; i++) {
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i+1]);
    }
    printf("%05d %d -1", list[sum - 1], data[list[sum-1]]);

    return 0;
}