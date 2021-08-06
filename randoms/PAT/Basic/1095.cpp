/**
 * @file 1095.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1071786104348536832
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

struct Student{
    string id;
    int score;
};

int main() {
    int n, m;

    unordered_map<char, vector<Student>> cmd1; // 等级 ->[考生] 
    unordered_map<char, int> cmd1_sorted; // 记录某个等级是否已排序好

    unordered_map<string, pair<int, int>>  cmd2; // 考场 -> [考生人数-总分]

    unordered_map<string, vector<pair<string, int>>> cmd3; // 日期 -> [考场-人数]
    unordered_map<string, int> cmd3_sorted; // 记录某个日期是否已排序好

    cin >> n >> m;

    string id;
    int score;
    string room, date;
    for(int i = 0; i < n; i++) {
        cin >> id >> score;
        room = id.substr(1, 3);
        date = id.substr(4, 6);
        cmd1[id[0]].push_back({id, score});

        cmd2[room].first++;
        cmd2[room].second += score;

        bool found = false;
        auto &v = cmd3[date];
        for(auto &p : v) {
            if(p.first == room) {
                p.second++;
                found = true;
                break;
            }
        }
        if(!found) {
            v.push_back({room, 1});
        }
    }

    // 不要提前全部排序好，以防查询数较小时额外浪费时间
    // for(auto &p : cmd1) {
    //     sort(p.second.begin(), p.second.end(), [](const Student &l, const Student &r){
    //         if(l.score != r.score) {
    //             return l.score > r.score;
    //         } else {
    //             return l.id < r.id;
    //         }
    //     });
    // }

    // for(auto &p : cmd3) {
    //     sort(p.second.begin(), p.second.end(), [](const pair<string, int> &l, const pair<string, int> &r) {
    //         if(l.second != r.second) {
    //             return l.second > r.second;
    //         } else {
    //             return l.first < r.first;
    //         }
    //     });
    // }

    int cmd;
    string data;
    for(int i = 0; i < m; i++) {
        cin >> cmd >> data;
        //cout << "Case " << i+1 << ": " << cmd << " " << data << endl;
        printf("Case %d: %d %s\n", i+1, cmd, data.c_str());
        if(cmd == 1) {
            if(cmd1.find(data[0]) == cmd1.end()) {
                //cout << "NA" << endl;
                printf("NA\n");
                continue;
            }
            if(!cmd1_sorted[data[0]]) {
                auto &p = cmd1[data[0]];
                sort(p.begin(), p.end(), [](const Student &l, const Student &r){
                    if(l.score != r.score) {
                        return l.score > r.score;
                    } else {
                        return l.id < r.id;
                    }
                });
                cmd1_sorted[data[0]] = 1;
            }
            for(auto &i : cmd1[data[0]]) {
                //cout << i.id << " " << i.score << endl;
                printf("%s %d\n", i.id.c_str(), i.score);
            }
        } else if(cmd == 2) {
            if(cmd2.find(data) == cmd2.end()) {
                //cout << "NA" << endl;
                printf("NA\n");
                continue;
            }
            //cout << cmd2[data].first << " " << cmd2[data].second << endl;
            printf("%d %d\n", cmd2[data].first, cmd2[data].second);
        } else if(cmd == 3) {
            if(cmd3.find(data) == cmd3.end()) {
                //cout << "NA" << endl;
                printf("NA\n");
                continue;
            }
            if(!cmd3_sorted[data]) {
                auto &p = cmd3[data];
                sort(p.begin(), p.end(), [](const pair<string, int> &l, const pair<string, int> &r) {
                    if(l.second != r.second) {
                        return l.second > r.second;
                    } else {
                        return l.first < r.first;
                    }
                });
                cmd3_sorted[data] = 1;
            }
            for(auto &i : cmd3[data]) {
                //cout << i.first << " " << i.second << endl;
                printf("%s %d\n", i.first.c_str(), i.second);
            }
        }
    }

    return 0;
}