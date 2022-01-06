/**
 * @file 1013.cpp
 * @author midlane.top
 * @brief 1013 Battle Over Cities
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, M, K, lost, visited[1000], ans;
vector<int> v[1000];

void dfs(int curcity) {
    visited[curcity] = 1;
    for(auto i : v[curcity]) {
        if(!visited[i] && i != lost) {
            dfs(i);
        }
    }
}

int main() {
    int a, b;

    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    while(K--) {
        cin >> lost;
        ans = 0;
        for(int i = 1; i <= N; i++) visited[i] = 0;
        for(int i = 1; i <= N; i++) {
            if(!visited[i] && i != lost) {
                ans++;
                dfs(i);
            }
        }
        cout << ans - 1 << endl;
    }
    

    return 0;
}