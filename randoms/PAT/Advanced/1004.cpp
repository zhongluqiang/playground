/**
 * @file 1004.cpp
 * @author midlane.top
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> v[100]; // v[i]表示结点i的子结点数组

int main() {
    int i, j, k, l;

    cin >> N >> M;
    if(N == 0) return 0;
    for(i = 0; i < M; i++) {
        cin >> j >> k;
        v[j].resize(k);
        for(l = 0; l < k; l++) {
            cin >> v[j][l];
        }
    }

    // 树的按层遍历
    bool flag = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int count = q.size();
        int num = 0;
        for(i = 0; i < count; i++) {
            int cur = q.front();
            q.pop();
            if(v[cur].empty()) {
                num++;
            } else {
                for(auto i : v[cur]) {
                    q.push(i);
                }
            }
        }
        
        if(!flag) {
            cout << num;
            flag = 1;
        } else {
            cout << " " << num;
        }
    }
    return 0;
}