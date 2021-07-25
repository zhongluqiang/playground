/**
 * @file 1041.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805281567916032
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main() {
    int n;
    map<int, pair<string, int>> index;

    cin >> n;

    string s;
    int n1, n2;
    for(int i = 0; i < n; i++) {
        cin >> s >> n1 >> n2;
        index.insert({n1, {s, n2}});
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> n1;
        if(i == m-1) {
            cout << index[n1].first << " " << index[n1].second;
        } else {
            cout << index[n1].first << " " << index[n1].second << endl;
        }
    }

    return 0;
}