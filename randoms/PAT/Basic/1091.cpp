/**
 * @file 1091.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1071785664454127616
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

bool check(int k, int n) {
    int result = k * k * n;
    if(k < 10) {
        return (result - k) % 10 == 0;
    } else if(k < 99) {
        return (result - k) % 100 == 0;
    } else if(k < 999) {
        return (result - k) % 1000 == 0;
    } else {
        return (result - k) % 10000 == 0;
    }
}

int main() {
    int m;
    cin >> m;
    int tmp;
    bool flag;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        flag = false;
        for(int n = 1; n < 10; n++) {
            if(check(tmp, n)) {
                cout << n << " " << tmp * tmp * n << endl;
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << "No" << endl;
        }
    }
    return 0;
}