/**
 * @file 1011.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    int64_t A, B, C;
    stringstream ss;
    
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> A >> B >> C;
        if(A + B > C) {
            ss << "Case #" << i+1 << ": true" << endl;
        } else {
            ss << "Case #" << i+1 << ": false" << endl;
        }
    }
    string ans = ss.str();
    ans.pop_back();
    cout << ans;
    return 0;
}