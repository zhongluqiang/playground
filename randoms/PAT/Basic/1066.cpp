/**
 * @file 1066.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805266514558976
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int m, n, a, b, v;
    cin >> m >> n >> a >> b >> v;

    int tmp;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // cin >> tmp; // 测试点3超时
            scanf("%d", &tmp);
            tmp = (tmp >= a && tmp <= b) ? v : tmp;
            if(j != n-1) {
                printf("%03d ", tmp);
            } else {
                printf("%03d\n", tmp);
            }
        }
    }
    return 0;
}