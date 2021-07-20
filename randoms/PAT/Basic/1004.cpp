/**
 * @file 1004.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct Info {
    string Name;
    string Num;
    int Score;

    Info(string name, string num, int score)
        : Name(name)
        , Num(num)
        , Score(score) {}
    
    bool operator< (const Info &r) const {
        return this->Score < r.Score;
    }
};

int main() {
    int n;
    set<Info> infos;
    string name, num;
    int score;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> name >> num;
        cin >> score;
        Info s(name, num, score);
        infos.insert(s);
    }

    cout << infos.rbegin()->Name << " " << infos.rbegin()->Num << endl;
    cout << infos.begin()->Name << " " << infos.begin()->Num;
    
    return 0;
}