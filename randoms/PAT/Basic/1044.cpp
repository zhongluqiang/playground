/**
 * @file 1044.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805279328157696
 * @version 0.1
 * @date 2021-07-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string map1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string map2[13] = {"zero", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> map3 = {
    {"tret", 0},
    {"jan", 1},
    {"feb", 2},
    {"mar", 3},
    {"apr", 4},
    {"may", 5},
    {"jun", 6},
    {"jly", 7},
    {"aug", 8},
    {"sep", 9},
    {"oct", 10},
    {"nov", 11},
    {"dec", 12}
};
map<string, int> map4 = {
    {"tam", 1},
    {"hel", 2},
    {"maa", 3},
    {"huh", 4},
    {"tou", 5},
    {"kes", 6},
    {"hei", 7},
    {"elo", 8},
    {"syy", 9},
    {"lok", 10},
    {"mer", 11},
    {"jou", 12}
};

int main() {
    int n;
    vector<string> strs;

    cin >> n;
    getchar();
    strs.resize(n);
    for(int i = 0; i < n; i++) {
        getline(cin, strs[i]);
    }

    for(int i = 0; i < n; i++) {
        string &s = strs[i];
        if(isdigit(s[0])) {
            int x = stoi(s);
            int high = x / 13;
            int low = x % 13;
            if(high) {
                if(low == 0) {
                    cout << map2[high] << endl; // 测试点2 4 fail原因
                } else {
                    cout << map2[high] << " " << map1[low] << endl;
                }
            } else {
                cout << map1[low] << endl;
            }
        } else {
            if(s.find(' ') != string::npos) {
                string s1 = s.substr(0, s.find(' '));
                string s2 = s.substr(s.find(' ') + 1);
                //cout << "s1:" << s1 << ",s2:" << s2 << endl;
                //cout << "map4[s1]:" << map4[s1] << ",map3[s2]:" << map3[s2] << endl;
                cout << map4[s1]*13 + map3[s2] << endl;
            } else {
                if(map3.find(s) != map3.end()) {
                    cout << map3[s] << endl;
                } else {
                    cout << map4[s] * 13 << endl;
                }
            }
        }
    }
    return 0;
}