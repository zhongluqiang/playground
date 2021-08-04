/**
 * @file 1072.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805263964422144
 * @version 0.1
 * @date 2021-08-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n, m;
    set<string> banned;
    string tmp;
    int heads = 0, items = 0;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        banned.insert(tmp);
    }

    string name;
    int count;
    bool found;
    for(int i = 0; i < n; i++) {
        found = false;
        cin >> name >> count;
        for(int j = 0; j < count; j++) {
            cin >> tmp;
            if(banned.find(tmp) != banned.end()) {
                if(!found) {
                    found = true;
                    cout << name << ": " << tmp;
                } else {
                    cout << " " << tmp;
                }
                items++;
            }
        }
        if(found) {
            cout << endl;
            heads++;
        }
    }
    cout << heads << " " << items << endl;
    return 0;
}