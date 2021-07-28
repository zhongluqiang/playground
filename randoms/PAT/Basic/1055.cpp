/**
 * @file 1055.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805272021680128
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct st {
    string name;
    int height;
    st() {}
    st(const string &s, int h) : name(s), height(h) {}
};

bool compare(const st &l, const st &r) {
    if(l.height != r.height) {
        return l.height > r.height;
    } else {
        return l.name < r.name;
    }
}

int main() {
    int n, k;
    vector<st> people;

    cin >> n >> k;
    people.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> people[i].name >> people[i].height;
    }

    sort(people.begin(), people.end(), compare);

    int t = 0, row = k;
    int m;
    while(row) {
        if(row == k) {
            m = n - n / k * (k - 1);
        } else {
            m = n / k;
        }
        vector<string> ans(m);
        ans[m/2] = people[t].name;
        // 左边
        int j = m / 2  - 1;
        for(int i = t + 1; i < t + m; i = i + 2) {
            ans[j--] = people[i].name;
        }
        // 右边
        j = m / 2 + 1;
        for(int i = t + 2; i < t + m; i = i + 2) {
            ans[j++] = people[i].name;
        }
        cout << ans[0];
        for(int i = 1; i < m; i++) {
            cout << " " << ans[i];
        }
        cout << endl;
        t = t + m;
        row--;
    }

    return 0;
}