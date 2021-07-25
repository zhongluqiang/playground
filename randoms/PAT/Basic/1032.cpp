/**
 * @file 1032.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805289432236032
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    uint64_t id, score;
    map<int64_t, int64_t> index;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> id >> score;
        if(index.find(id) == index.end()) {
            index[id] = score;
        } else {
            index[id] += score;
        }
    }

    int64_t ans_id = 0, ans_score = -1;
    
    for(auto &i : index) {
        if(i.second > ans_score) {
            ans_id = i.first;
            ans_score = i.second;
        }
    }

    cout << ans_id << " " << ans_score;

    return 0;
}