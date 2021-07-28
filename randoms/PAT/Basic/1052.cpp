/**
 * @file 1052.cpp
 * @author midlane.top
 * @brief 
 * @version 0.1
 * @date 2021-07-28
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805273883951104
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void parse(const string &s, vector<string> &out) {
    out.push_back("");
    bool found = false;
    string tmp;
    for(auto &ch : s) {
        if(ch == '[') {
            found = true;
        } else if(ch == ']') {
            found = false;
            out.push_back(tmp);
            tmp.clear();
        } else {
            if(!found) continue;
            tmp.push_back(ch);
        }
    }
}

int main() {
    string s1, s2, s3;
    vector<string> hands, eyes, mouths;

    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    parse(s1, hands);
    parse(s2, eyes);
    parse(s3, mouths);

    int n;
    int p1, p2, p3, p4, p5;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p1 >> p2 >> p3 >> p4 >> p5;
        if(p1 < 1 || p2 < 1 || p3 < 1 || p4 < 1 || p5 < 1) {
            printf("Are you kidding me? @\\/@\n");
        } else if(p1 > hands.size()-1 || p2 > eyes.size()-1 || p3 > mouths.size()-1 || p3 > eyes.size()-1 || p5 > hands.size()-1) {
            printf("Are you kidding me? @\\/@\n");
        } else {
            printf("%s(%s%s%s)%s\n", hands[p1].c_str(), eyes[p2].c_str(), mouths[p3].c_str(), eyes[p4].c_str(), hands[p5].c_str());
        }
    }
    return 0;
}