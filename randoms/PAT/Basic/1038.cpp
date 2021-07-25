/**
 * @file 1038.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805284092887040
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main() {
    int n, k, tmp;
    int score[101] = {0};

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        score[tmp]++;
    }

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> tmp;
        if(i == 0) {
            cout << score[tmp];
        } else {
            cout << " " << score[tmp];
        }
    }

    return 0;
}