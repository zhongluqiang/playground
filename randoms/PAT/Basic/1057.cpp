/**
 * @file 1057.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805270914383872
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int total = 0;
    int zeros = 0, ones = 0;
    bool found = false;
    
    getline(cin, s);
    
    for(auto ch : s) {
        if(isalpha(ch)) {
            total += (tolower(ch) - 'a' + 1);
            found = true;
        }
    }
    if(!found) {
        printf("0 0\n");
        return 0;
    }
    if(total == 0) {
        printf("1 0\n");
        return 0;
    }

    while(total > 0) {
        if(total & 0x1) {
            ones++;
        } else {
            zeros++;
        }
        total >>= 1;
    }
    printf("%d %d\n", zeros, ones);
    return 0;
}