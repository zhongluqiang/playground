/**
 * @file 1050.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805275146436608
 * @version 0.1
 * @date 2021-07-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> nums;

    cin >> N;
    nums.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());

    int m, n;
    m = n = sqrt(N);
    while(m * n != N) {
        if(m * n < N) {
            m++;
        } else {
            n--;
        }
    }

    vector<vector<int>> matrix(m, vector<int>(n));

    int t = 0;
    int level = m / 2 + m % 2;
    for(int i = 0; i < level; i++) {
        for(int j = i; j <= n - 1 - i && t <= N - 1; j++) {
            matrix[i][j] = nums[t++];
        }
        for(int j = i+1; j <= m - 2 - i && t <= N-1; j++) {
            matrix[j][n-1-i] = nums[t++];
        }
        for(int j = n-i-1; j >= i && t <= N-1; j--) {
            matrix[m-1-i][j] = nums[t++];
        }
        for(int j = m-2-i; j >= i+1 && t <= N-1;j--) {
            matrix[j][i] = nums[t++];
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if(j != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}