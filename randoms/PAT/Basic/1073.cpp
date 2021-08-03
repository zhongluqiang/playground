/**
 * @file 1073.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805263624683520
 * @version 0.1
 * @date 2021-08-03
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
    int score; // 满分值
    int total; // 选项个数
    int correct; // 正确选项个数
    int choices[5]; // choices[0]~choices[5]表示a~e是否为正确选项
    int failed[5]; // 单项错误次数统计
    int count_failed; // 本题错误次数统计

    bool operator<(const struct Problem &r) const {
        //if(count_failed != r.count_failed) {
        if(max_failed() != r.max_failed()) {
            return max_failed() > r.max_failed();
        } else {
            return index < r.index;
        }
    }

    int max_failed() const {
        return *max_element(failed, failed+5);
    }
};

struct Answer {
    int total;
    int choices[5];
};

struct Student {
    vector<Answer> ans;
};

int main() {
    int n, m; // n个学生，m道题

    cin >> n >> m;

    vector<Student> stu(n, {vector<Answer>(m)});
    vector<Problem> p(m);
    char c;

    for(int i = 0; i < m; i++) {
        cin >> p[i].score >> p[i].total >> p[i].correct;
        for(int j = 0; j < p[i].correct; j++) {
            cin >> c;
            p[i].choices[c-'a'] = 1;
        }
        p[i].index = i+1;
        p[i].count_failed = 0;
    }

    getchar();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        vector<Answer> &cur = stu[i].ans;
        int index = 0;
        for(int j = 0; j < s.size(); j++) {
            char ch = s[j];
            if(ch == ' ') {
                continue;
            }
            if(ch == '(') {
                j++;
                cur[index].total = s[j] - '0';
            } else if(ch == ')') {
                index++;
            } else {
                cur[index].choices[ch-'a'] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        double score = 0;
        for(int j = 0; j < stu[i].ans.size(); j++) {
            bool wrong = false, right = true;
            for(int k = 0; k < 5; k++) {
                if(stu[i].ans[j].choices[k] && !p[j].choices[k]) {
                    wrong = true;
                    p[j].failed[k]++;
                } else if(!stu[i].ans[j].choices[k] && p[j].choices[k]) {
                    right = false;
                    p[j].failed[k]++;
                }
            }
            if(wrong) {
                p[j].count_failed++;
            } else if(!right) {
                score += p[j].score / 2.0;
            } else {
                score += p[j].score;
            }
        }
        printf("%.1f\n", score);
    }

    sort(p.begin(), p.end());
    if(p.begin()->max_failed() == 0) {
        printf("Too simple\n");
    } else {
        for(int i = 0; i < m && p[i].max_failed() == p[0].max_failed(); i++) {
            for(int k = 0; k < 5; k++) {
                if(p[i].failed[k] == p[i].max_failed()) {
                    printf("%d %d-%c\n", p.begin()->max_failed(), p[i].index, k+'a');
                }
            }
        }
    }

    return 0;
}