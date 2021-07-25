/**
 * @file 1043.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805280074743808
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
    string s;
    int count[256] = {0};

    cin >> s;

    for(auto &ch : s) {
        count[ch]++;
    }

    const char wheel[6] = {'P', 'A', 'T', 'e', 's', 't'};
    int index = 0;
    bool empty;

    while(1) {
        empty = true;
        for(int i = 0; i < 6; i++) {
            char cur = wheel[i];
            if(count[cur] > 0) {
                empty = false;
                cout << cur;
                count[cur]--;
                index++;
            } else {
                index++;
            }
            index %= 6;
        }
        if(empty) {
            break;
        }
    }

    return 0;
}