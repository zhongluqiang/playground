/**
 * @file 1059.cpp
 * @author midlane.top
 * @brief C语言竞赛 https://pintia.cn/problem-sets/994805260223102976/problems/994805269828059136
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

bool isprime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    map<string, int> index;
    set<string> checked;
    string s;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        index[s] = i+1;
    }

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> s;
        if(index.find(s) == index.end()) {
            printf("%s: Are you kidding?\n", s.c_str());
            continue;
        }
        if(checked.find(s) != checked.end()) {
            printf("%s: Checked\n", s.c_str());
            continue;
        }
        if(index[s] == 1) {
            printf("%s: Mystery Award\n", s.c_str());
        } else if(isprime(index[s])) {
            printf("%s: Minion\n", s.c_str());
        } else {
            printf("%s: Chocolate\n", s.c_str());
        }
        checked.insert(s);
    }
    return 0;
}