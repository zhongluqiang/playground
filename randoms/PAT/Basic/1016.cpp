/**
 * @file 1016.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805306310115328
 * @version 0.1
 * @date 2021-07-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, DA, B, DB;
    int n1 = 0, n2 = 0;

    cin >> A >> DA >> B >> DB;
    for (auto &c : A) {
        if (c == DA[0]) {
            ++n1;
        }
    }
    for (auto &c : B) {
        if (c == DB[0]) {
            ++n2;
        }
    }

    string s1 = string(n1, DA[0]);
    string s2 = string(n2, DB[0]);
    cout << atoll(s1.c_str()) + atoll(s2.c_str());

    return 0;
}