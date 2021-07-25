/**
 * @file 1033.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805288530460672
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string missing, s;
    int flag[256] = {0};
    
    getline(cin, missing);
    getline(cin, s);

    bool missing_shift = false;
    if(missing.find('+') != string::npos) {
        missing_shift = true;
    }
    if(missing_shift) {
        for(int i = 'A'; i <= 'Z'; i++) {
            flag[i] = 1;
        }
    }

    for(auto &ch : missing) {
        if(ch == '+') {
            continue;
        }

        if(isalpha(ch)) {
            flag[ch] = flag[tolower(ch)] = 1;
        } else {
            flag[ch] = 1;
        }
    }

    for(char &c : s) {
        if(flag[c]) {
            continue;
        }
        cout << c;
    }
    return 0;
}