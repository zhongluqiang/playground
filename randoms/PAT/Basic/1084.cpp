/**
 * @file 1084.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805260583813120
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

string iterate(string s) {
    string ret;
    int p1, p2;
    p1 = p2 = 0;
    while(p1 < s.size()) {
        p2 = p1;
        while(p2 < s.size() && s[p2] == s[p1]) {
            p2++;
        }
        ret.push_back(s[p1]);
        ret += to_string(p2 - p1);
        p1 = p2;
    }
    return ret;
}

int main() {
    string d;
    int n;
    
    cin >> d >> n;
    for(int i = 0; i < n-1; i++) {
        d = iterate(d);
    }
    cout << d << endl;
    return 0;
}