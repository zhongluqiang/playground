/**
 * @file 1048.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805276438282240
 * @version 0.1
 * @date 2021-07-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    string ans;

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    while(a.size() < b.size()) {
        a.push_back('0');
    }
    while(b.size() < a.size()) {
        b.push_back('0');
    }
    //cout << a << endl;
    //cout << b << endl;
    int tmp;
    for(int i = 0; i < a.size(); i++) {
        if(i % 2 == 0) {
            tmp = (a[i] - '0' + b[i] - '0') % 13;
            if(tmp == 10) {
                ans.push_back('J');
            } else if(tmp == 11) {
                ans.push_back('Q');
            } else if(tmp == 12) {
                ans.push_back('K');
            } else {
                ans.push_back(tmp + '0');
            }
            
        } else {
            tmp = b[i] - a[i];
            if(tmp < 0) {
                tmp += 10;
            }
            ans.push_back(tmp + '0');
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}