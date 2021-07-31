/**
 * @file 1061.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805268817231872
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main() {
    int n, m;
    int scores[101] = {0};
    int ans[101] = {0};

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> scores[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> ans[i];
    }
    for(int i = 0; i < n; i++) {
        int result = 0;
        int x;
        for(int j = 0; j < m; j++) {
            cin >> x;
            if(x == ans[j]) {
                result += scores[j];
            }
        }
        printf("%d\n", result);
    }
    return 0;
}