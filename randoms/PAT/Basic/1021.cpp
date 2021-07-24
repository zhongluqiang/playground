/**
 * @file 1021.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805300404535296
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string N;
    stringstream ss;
    int count[10] = {0};

    cin >> N;

    for(auto &ch : N) {
        count[ch - '0']++;
    }

    for(int i = 0; i < 10; i++) {
        if(count[i]) {
            ss << i << ":" << count[i] << endl;
        }
    }

    string ans = ss.str();
    ans.pop_back();
    cout << ans;
    return 0;
}