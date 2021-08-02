/**
 * @file 1065.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805266942377984
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, m;
    map<string, string> m1, m2;
    set<string> s;
    set<string> single;

    cin >> n;
    string tmp1, tmp2;
    for(int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2;
        m1[tmp1] = tmp2;
        m2[tmp2] = tmp1;
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp1;
        s.insert(tmp1);
    }
    
    for(auto it = s.begin(); it != s.end(); it++) {
        if(m1.find(*it) != m1.end()) {
            if(s.find(m1[*it]) == s.end()) {
                single.insert(*it);
            }
        } else if(m2.find(*it) != m2.end()) {
            if(s.find(m2[*it]) == s.end()) {
                single.insert(*it);
            }
        } else {
            single.insert(*it);
        }
    }
    
    cout << single.size() << endl;
    for(auto it = single.begin(); it != single.end(); it++) {
        if(it == single.begin()) {
            cout << *it;
        } else {
            cout << " " << *it;
        }
    }
    return 0;
}