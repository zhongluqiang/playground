/**
 * @file 1031.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805290334011392
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int z2m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool isTrue(const string &s) {
    int sum = 0;
    for(int i = 0; i < 17; i++) {
        if(s[i]< '0' || s[i] > '9') {
            return false;
        }
        sum += (s[i] - '0') * weight[i];
    }
    sum = sum % 11;
    return z2m[sum] == s[17];
}

int main() {
    int n;
    bool flag = false;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(!isTrue(s)) {
            cout << s << endl;
            flag = true;
        }
    }

    if(!flag) cout << "All passed";

    return 0;
}