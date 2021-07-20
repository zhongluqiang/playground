/**
 * @file 1009.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    getline(cin, s); // cin >> s 无法读取带空格的一整行，换成getline 

    reverse(s.begin(), s.end());

    auto it1 = s.begin();
    auto it2 = s.begin();

    while(it1 != s.end()) {
        while(it2 != s.end() && *it2 != ' ') {
            ++it2;
        }
        reverse(it1, it2);
        while(it2 != s.end() && *it2 == ' ') {
            ++it2;
        }
        if(it2 == s.end()) {
            break;
        }
        it1 = it2;
    }
    cout << s;

    return 0;
}