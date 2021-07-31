/**
 * @file 1064.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805267416334336
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n, tmp;
    string s;
    set<int> ans;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        tmp = 0;
        for(auto ch : s) {
            tmp += ch - '0';
        }
        ans.insert(tmp);
    }
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++) {
        if(it == ans.begin()) {
            cout << *it;
        } else {
            cout << " " << *it;
        }
    }
    return 0;
} 