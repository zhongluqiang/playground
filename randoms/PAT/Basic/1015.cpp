/**
 * @file 1015.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805307551629312
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int N, L, H;

struct Student {
    int id;
    int d;
    int c;
    int total;
    int level; // 3, 2, 1, 0, -1

    Student(int _id, int _d, int _c)
        : id(_id)
        , d(_d)
        , c(_c)
        , total(d + c) {
            if (d >= H && c >= H) {
                level = 3;
            } else if (d >= H && c >= L && c < H) {
                level = 2;
            } else if (d >= L && d < H && c >= L && c < H && d >= c) {
                level = 1;
            } else if (d < L || c < L) {
                level = -1;
            } else {
                level = 0;
            }
            // printf("id=%d, d=%d, c=%d, level=%d\n", id, d, c, level);
    }

    int getlevel() const{
        return level;
    }

    bool fail() {
        return level == -1;
    }

    bool operator<(const Student &r) const {
        if (getlevel() == r.getlevel()) {
            if (total == r.total) {
                if (d == r.d) {
                    return id > r.id;
                } else {
                    return d < r.d;
                }
            } else {
                return total < r.total;
            }
        } else {
            return getlevel() < r.getlevel();
        }
    }
};

int main() {
    int id, d, c;
    set<Student> pass;

    cin >> N >> L >> H;

    for (int i = 0; i < N; i++) {
        cin >> id >> d >> c;
        Student stu(id, d, c);
        //printf("id=%d, d=%d, c=%d, level=%d\n", stu.id, stu.d, stu.c, stu.getlevel());
        if (stu.fail()) {
            continue;
        } else {
            pass.insert(stu);
        }
    }

    stringstream ss;
    ss << pass.size() << endl;
    for (auto it = pass.rbegin(); it != pass.rend(); it++) {
        ss << it->id << " " << it->d << " " << it->c << endl;
    }
    string ans = ss.str();
    ans.pop_back();
    cout << ans;
    return 0;
}