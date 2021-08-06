/**
 * @file 1094.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1071785997033074688
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isprime(long long n) {
    if(n < 2) return false;
    for(int i = 2, x = sqrt(n); i < x; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int l, k;
    string s;
    cin >> l >> k >> s;
    // 测试点 4 5 
    if(k > l) {
        cout << 404;
        return 0;
    } 
    if(k == l) {
        if(isprime(stoll(s))) {
            cout << s;
        } else {
            cout << 404;
        }
        return 0;
    }
    bool found = false;
    for(int i = 0; i <= s.size() - k; i++) { // 测试点2: <=
        if(isprime(stoll(s.substr(i, k)))) {
            cout << s.substr(i, k);
            found = true;
            break;
        }
    }
    if(!found) {
        cout << 404;
    }
    return 0;
}