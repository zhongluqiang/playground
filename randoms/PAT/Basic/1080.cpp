/**
 * @file 1080.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805261493977088
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

struct Student {
    string id;
    int gp;
    int gm;
    int gf;

    Student(): gp(-1), gm(-1), gf(-1) {}
    Student(const string &_id): id(_id), gp(-1), gm(-1), gf(-1) {}
    
    bool valid() const {
        if(gp < 200) {
            return false;
        }
        if(total() < 60) {
            return false;
        }
        return true;
    }
    int total() const {
        if(gm > gf) {
            return (int)round(gm * 0.4 + gf * 0.6);
        } else {
            return gf;
        }
    }
    bool operator<(const Student &r) const {
        if(!valid() && !r.valid()) {
            return false;
        }
        if(!valid() && r.valid()) {
            return true;
        }
        if(valid() && !r.valid()) {
            return false;
        }
        if(total() != r.total()) {
            return total() > r.total();
        } else {
            return id < r.id;
        }
    }
};

int main() {
    int p, m, n;
    string id;
    int tmp;
    vector<Student*> stus;
    map<string, Student*> index;

    cin >> p >> m >> n;
    
    for(int i = 0; i < p; i++) {
        cin >> id >> tmp;
        if(index.find(id) == index.end()) {
            Student *stu = new Student(id);
            stu->gp = tmp;
            stus.push_back(stu);
            index[id] = stu;
        } else {
            index[id]->gp = tmp;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> id >> tmp;
        if(index.find(id) == index.end()) {
            Student *stu = new Student(id);
            stu->gm = tmp;
            stus.push_back(stu);
            index[id] = stu;
        } else {
            index[id]->gm = tmp;
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> id >> tmp;
        if(index.find(id) == index.end()) {
            Student *stu = new Student(id);
            stu->gf = tmp;
            stus.push_back(stu);
            index[id] = stu;
        } else {
            index[id]->gf = tmp;
        }
    }
    sort(stus.begin(), stus.end(), [](const Student *l, const Student *r){
        return *l < *r;
    });
    for(int i = 0; i < stus.size(); i++) {
        if(stus[i]->valid()) {
            cout << stus[i]->id << " " << stus[i]->gp << " " << stus[i]->gm << " " << stus[i]->gf << " " << stus[i]->total() << endl;
        }
        delete stus[i];
    }
    
    return 0;
}