/**
 * @file 1058.cpp
 * @author midlane.top
 * @brief 选择题 https://pintia.cn/problem-sets/994805260223102976/problems/994805270356541440
 * @version 0.1
 * @date 2021-07-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Problem {
    int index; // 编号， 从1开始
    int score;
    int total;
    int correct;
    vector<char> choices;
    int failed; // 错误次数统计

    bool operator<(const struct Problem &r) const {
        if(failed != r.failed) {
            return failed > r.failed;
        } else {
            return index < r.index;
        }
    }
};

struct Answer {
    int total;
    vector<char> choices;
};

struct Student {
    vector<Answer> ans;
};

int main() {
    int n, m;

    cin >> n >> m;

    vector<Student> stu(n, {vector<Answer>(m)});
    vector<Problem> p(m);

    for(int i = 0; i < m; i++) {
        cin >> p[i].score >> p[i].total >> p[i].correct;
        p[i].choices.resize(p[i].correct);
        for(int j = 0; j < p[i].correct; j++) {
            cin >> p[i].choices[j];
        }
        p[i].index = i+1;
        p[i].failed = 0;
        sort(p[i].choices.begin(), p[i].choices.end());
    }

    getchar();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        vector<Answer> &cur = stu[i].ans;
        int index = 0;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == ' ') {
                continue;
            }
            if(ch == '(') {
                i++;
                cur[index].total = s[i] - '0';
            } else if(ch == ')') {
                sort(cur[index].choices.begin(), cur[index].choices.end());
                index++;
            } else {
                cur[index].choices.push_back(ch);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int score = 0;
        for(int j = 0; j < stu[i].ans.size(); j++) {
            if(stu[i].ans[j].choices == p[j].choices) {
                score += p[j].score;
            } else {
                p[j].failed++;
            }
        }
        printf("%d\n", score);
    }

    sort(p.begin(), p.end());
    if(p.begin()->failed == 0) {
        printf("Too simple\n");
    } else {
        printf("%d", p.begin()->failed);
        for(int i = 0; i < m && p[i].failed == p[0].failed; i++) {
            printf(" %d", p[i].index);
        }
        printf("\n");
    }

    return 0;
}