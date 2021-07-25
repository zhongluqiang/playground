/**
 * @file 1042.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805280817135616
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int count[27] = {0};

    getline(cin, s);

    for(auto &ch : s) {
        if(!isalpha(ch)) {
            continue;
        }
        count[tolower(ch) - 'a']++;
    }

    int x = -1;
    for(int i = 0; i < 27; i++) {
        x = max(x, count[i]);
    }
    for(int i = 0; i < 27; i++) {
        if(x == count[i]) {
            printf("%c %d", 'a'+i, x);
            break;
        }
    }

    return 0;
}