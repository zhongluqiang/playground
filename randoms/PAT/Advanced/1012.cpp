/**
 * @file 1012.cpp
 * @author midlane.top
 * @brief 1012 The Best Rank
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Student {
    string id;
    int score[4]; // C M E A
    int rank[4];  // rank of C M E A
};

int N, M;
Student a[2001];
string query[2001];

void dump() {
    cout << "============" << endl;
    for(int i = 0; i < N; i++) {
        cout << a[i].id 
             << " " << a[i].score[0] << " " << a[i].score[1] << " " << a[i].score[2] << " " << a[i].score[3] 
             << " " << a[i].rank[0] << " " << a[i].rank[1] << " " << a[i].rank[2] << " " << a[i].rank[3] 
             << endl;
    }
}

int main() {
    unordered_map<string, Student*> m;

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> a[i].id >> a[i].score[0] >> a[i].score[1] >> a[i].score[2];
        a[i].score[3] = round((a[i].score[0] + a[i].score[1] + a[i].score[2]) / 3.0);
    }
    for(int i = 0; i < M; i++) {
        cin >> query[i];
    }

    // 对四个分数进行降序排序，得出每项的排名
    for(int j = 0; j < 4; j++) {
        sort(a, a+N, [j](Student &s1, Student &s2) {
            return s1.score[j] > s2.score[j];
        });
        a[0].rank[j] = 1;
        for(int i = 1; i < N; i++) {
            if(a[i].score[j] == a[i-1].score[j]) {
                a[i].rank[j] = a[i-1].rank[j];
            } else {
                // a[i].rank[j] = a[i-1].rank[j]+1;
                a[i].rank[j] = i + 1; // 测试点2，并列排名情况下，排名按人头加，比如 90 90 89，对应的排名是 1 1 3
            }
        }
        // dump();
    }

    // 建立索引
    for(int i = 0; i < N; i++) {
        m[a[i].id] = &a[i];
    }

    for(int i = 0; i < M; i++) {
        if(m.find(query[i]) == m.end()) {
            cout << "N/A" << endl;
            continue;
        }
        Student *p = m[query[i]];
        
        // 排名越靠前，rank越小
        // 笨办法，枚举出 C M E A各自作为最高rank的情况
        if(p->rank[3] <= p->rank[0] && p->rank[3] <= p->rank[1] && p->rank[3] <= p->rank[2]) {
            cout << p->rank[3] << " A" << endl;
        }
        else if(p->rank[0] < p->rank[3] && p->rank[0] <= p->rank[1] && p->rank[0] <= p->rank[2]) {
            cout << p->rank[0] << " C" << endl;
        }
        else if(p->rank[1] < p->rank[3] && p->rank[1] < p->rank[0] && p->rank[1] <= p->rank[2]) {
            cout << p->rank[1] << " M" << endl;
        }
        else if(p->rank[2] < p->rank[3] && p->rank[2] < p->rank[0] && p->rank[2] < p->rank[1]) {
            cout << p->rank[2] << " E" << endl;
        }
    }
    return 0;
}