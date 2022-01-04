/**
 * @file 1003.cpp
 * @author midlane.top
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// 原始输入
int N, M, C1, C2;     // N个城市，M条路，C1起点，C2终点
int num_of_team[500]; // 救援队数量
vector<int> v[500];   // 图的邻接表形式，v[i]表示与i相连的所有点
int dis[500][500];    // dis[i][j]表示i与j之间的距离

// 中间计算结果
int mindis[500]; // 记录当前从C1到每个城市的最短距离，dfs过程中更新，初始时设置为一个较大值

// 最终结果
int paths;
int teams;

/**
 * @brief dfs遍历
 * 
 * @param curcity 当前城市，也就是到达的城市
 * @param curlen 当前路径长度
 * @param curteam 当前救援队数量
 * @note dfs的结果存储在全局变量中，通过全局变量记录的值进行剪枝
 */
void dfs(int curcity, int curlen, int curteam) {
    // 如果当前到curcity的路径长度已经超过了之前记录的到最短路径长度，那么就没必要再操作下去了
    if (curlen > mindis[curcity]) {
        return;
    }
    if (curcity == C2) {
        // 到达目的地，更新最终结果
        if (curlen == mindis[curcity]) {
            paths++;
            if (curteam > teams) {
                teams = curteam;
            }
        } else {
            mindis[C2] = curlen;
            paths      = 1;
            teams      = curteam;
        }
    } else {
        // 未到目的地，更新中间计算结果，继续dfs
        if (curlen < mindis[curcity]) {
            mindis[curcity] = curlen;
        }
        for (int i = 0; i < v[curcity].size(); i++) {
            int j = v[curcity][i];
            // 对相邻点进行dfs时要叠加本次dfs所带来的收益
            dfs(j, curlen + dis[curcity][j], curteam + num_of_team[j]);
        }
    }
}

int main() {
    int i, j, k, l;

    cin >> N >> M >> C1 >> C2;
    for (i = 0; i < N; i++) {
        cin >> num_of_team[i];
    }
    for (i = 0; i < M; i++) {
        cin >> j >> k >> l;
        v[j].push_back(k); // 邻接表赋值，无向图
        v[k].push_back(j);
        dis[j][k] = dis[k][j] = l;
    }

    for (i = 0; i < N; i++) {
        mindis[i] = 1000000000;
    }

    dfs(C1, 0, num_of_team[C1]); //从C1开始进行dfs，初始时路径长度为0，能够召集的救援队只有本市
    cout << paths << " " << teams;
    return 0;
}