/**
 * @file 1093.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1071785884776722432
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    int seen[256] = {0};

    getline(cin, a);
    getline(cin, b);

    for(auto ch : a) {
        if(!seen[ch]) {
            printf("%c", ch);
            seen[ch] = 1;
        }
    }
    for(auto ch : b) {
        if(!seen[ch]) {
            printf("%c", ch);
            seen[ch] = 1;
        }
    }
    return 0;
}