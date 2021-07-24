/**
 * @file 1029.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805292322111488
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    int found1[256] = {0};
    int found2[256] = {0};
    
    cin >> str1 >> str2;

    for(auto &ch : str1) {
        if(isalpha(ch)) {
            found1[tolower(ch)] = 1;
        } else {
            found1[ch] = 1;
        }
    }

    for(auto &ch : str2) {
        if(isalpha(ch)) {
            found2[tolower(ch)] = 1;
        } else {
            found2[ch] = 1;
        }
    }

    for(auto &i : str1) {
        if(isalpha(i)) {
            i = tolower(i);
        }
        if(found1[i] && !found2[i]) {
            if(isalpha(i)) {
                found2[i] = 1;
                cout << (char)toupper(i);
            } else {
                found2[i] = 1;
                cout << (char)i;
            }
        }
    }
    return 0;
}