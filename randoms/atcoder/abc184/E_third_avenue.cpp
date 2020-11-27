#include <bits/stdc++.h>
using namespace std;

int H, W; // H行 W列
int g[2010][2010]; // 存储输入矩阵
int visited[2010][2010]; // BFS遍历，存储哪些节点被访问过
vector<int> rooms[26]; // 存储相同字符的房间集合，例如rooms[0]表示全部字符为a的房间的集合，房间坐标转化成一维的，(x,y)位置转化成(x*W+y)
const int dirs[] = {-1, 0, 1, 0, -1};
int ans = 0;
bool found = false;

int main() {
    //freopen("./E_case1.txt", "r", stdin);
    int x, y; /*x,y保存起始点S的坐标*/
    cin >> H >> W;

    string line;
    for (int i = 0; i < H; i++) {
        cin >> line;
        for (int j = 0; j < W; j++) {
            g[i][j] = line[j];
            if (g[i][j] == 'S') {
                x = i;
                y = j;
            }
            if(islower(g[i][j])) {
                //rooms[g[i][j] - 'a'].push_back({i,j});
                rooms[g[i][j] - 'a'].push_back(i*W + j);
            }
        }
    }

    // BFS遍历，到达终点为止
    //queue<pair<int, int>> q;
    queue<int> q;
    //q.push({x,y});
    q.push(x*W+y);
    visited[x][y] = 1;
    while(!q.empty()) {
        int size = q.size();
        ++ans;
        while(size--) {
            auto cur = q.front(); q.pop();
            // int tx = cur.first;
            // int ty = cur.second;
            int tx = cur / W;
            int ty = cur % W;
            // 已达终点
            if(g[tx][ty] == 'G') {
                found = true;
                goto done;
            }
            // 未达终点，把当前点上下左右的点加入队列
            for(int i = 0; i < 4; i++) {
                int ttx = tx + dirs[i];
                int tty = ty + dirs[i+1];
                if(ttx < 0 || tty < 0 || ttx >= H || tty >= W) {
                    continue;
                }
                if(g[ttx][tty] == '#') {
                    continue;
                }
                if(visited[ttx][tty]) {
                    continue;
                }
                visited[ttx][tty] = 1;
                //q.push({ttx, tty});
                q.push(ttx*W + tty);
            }

            // 如果当前点是a~z，则把其他相同字母的房间也加入队列
            if(islower(g[tx][ty])) {
                for(auto &i : rooms[g[tx][ty]-'a']) {
                    int ttx = i / W;
                    int tty = i % W;
                    if(ttx == tx && tty == ty) {
                        continue;
                    }
                    if(visited[ttx][tty]) {
                        continue;
                    }
                    visited[ttx][tty] = 1;
                    q.push(ttx*W + tty);
                }
            }
        }
    }
    
done:
    printf("%d", found ? ans-1 : -1);
    return 0;
}