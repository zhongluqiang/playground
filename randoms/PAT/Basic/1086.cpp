/**
 * @file 1086.cpp
 * @author midlane.top
 * @brief 
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int a, b;
    string ans;
    
    cin >> a >> b;
    ans = to_string(a*b);
    while(ans.size() > 0 && ans.back() == '0') {
        ans.pop_back();
    }
    if(ans.empty()) {
        cout << "0" << endl;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}