/**
 * @file 1085.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805260353126400
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Agent {
    int score;
    int num;
    string agent_id;
    //int totalB;
    //int totalA;
    //int totalT;
    double total;
    
    Agent(const string &s) : agent_id(s){}
    void caculate() {
        //score = (int)(totalB / 1.5 + totalA + totalT * 1.5);
        score = (int)total;
    }
    
    bool operator<(const Agent &r) const {
        if(score != r.score) {
            return score > r.score;
        } else {
            if(num != r.num) {
                return num < r.num;
            } else {
                return agent_id < r.agent_id;
            }
        }
    }
};

int main() {
    int n;
    string id, agent_id;
    int score;
    vector<Agent*> agents;
    map<string, Agent*> index;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> id >> score >> agent_id;
        transform(agent_id.begin(), agent_id.end(), agent_id.begin(), [](const char c) {
            return tolower(c);
        });
        if(index.find(agent_id) == index.end()) {
            Agent *p = new Agent(agent_id);
            agents.push_back(p);
            index[agent_id] = p;
            p->num = 1;
            if(id[0] == 'B') {
                //p->totalB = score; // 测试点4、5报错原因：总分单独计算，而不是先累加再计算
                p->total = score / 1.5;
            } else if(id[0] == 'A') {
                //p->totalA = score;
                p->total = score;
            } else if(id[0] == 'T') {
                //p->totalT = score;
                p->total = score * 1.5;
            }
        } else {
            Agent *p = index[agent_id];
            p->num += 1;
            if(id[0] == 'B') {
                //p->totalB += score; 
                p->total += score / 1.5;
            } else if(id[0] == 'A') {
                //p->totalA += score;
                p->total += score;
            } else if(id[0] == 'T') {
                //p->totalT += score;
                p->total += score * 1.5;
            }
        }
    }
    
    cout << agents.size() << endl;

    for(auto &i : agents) {
        i->caculate();
    }
    sort(agents.begin(), agents.end(), [](const Agent *l, const Agent *r){
        return *l < *r;
    });

    int p1, p2;
    p1 = p2 = 0;
    int rank = 1;
    while(p1 < agents.size()) {
        p2 = p1;
        while(p2 < agents.size() && agents[p2]->score == agents[p1]->score) {
            cout << rank << " " << agents[p2]->agent_id << " " << agents[p2]->score << " " << agents[p2]->num << endl;
            p2++;
        }
        rank = p2+1;
        p1 = p2;
    }

    for(auto &p : agents) {
        delete p;
    }

    return 0;
}