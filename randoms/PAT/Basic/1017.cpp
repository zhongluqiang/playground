/**
 * @file 1017.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805305181847552
 * @version 0.1
 * @date 2021-07-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str;
    int div;
    stringstream ss;
    int left = 0;

    cin >> str >> div;

    for(auto ch : str) {
        ss << (left * 10 + ch - '0') / div;
        left = (left * 10 + ch - '0') % div;
    }

    string ans = ss.str();
    if(ans.size() > 1 && ans[0] == '0') {
        ans = ans.substr(1);
    }

    cout<< ans << " " << left << endl;

    return 0;
}

