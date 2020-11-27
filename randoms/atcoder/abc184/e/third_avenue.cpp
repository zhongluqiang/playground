#include <bits/stdc++.h>
using namespace std;

const int dirs[] = {-1, 0, 1, 0, -1};
const int maxv = 0x3f3f3f3f;

int H, W; // H行 W列
int g[2010][2010]; // 存储输入矩阵
int dis[2010][2010]; // 存储每个位置到终点的距离
vector<int> rooms[30]; // 存储相同字符的房间集合，房间坐标转化成一维的，(x,y)位置转化成(x*W+y)
int visited_rooms[30]; // 存储字符a~z是否被访问过，相同字符的房间只需要访问一次

int main() {
    //freopen("./random_02.txt", "r", stdin);
    char ch;
    int x, y; /*x,y保存终点G的坐标*/
    cin >> H >> W;
    memset(dis, 0x3f, sizeof dis);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> ch;
            g[i][j] = ch;
            if (ch == 'G') {
                x = i;
                y = j;
            }
            if(islower(ch)) {
                rooms[ch - 'a'].push_back(i*W + j);
            }
        }
    }

    // BFS遍历，从终点开始，遍历到起点为止，每遍历一层，距离加1
    queue<int> q;
    q.push(x*W+y);
    dis[x][y] = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front(); q.pop();
            int tx = cur / W;
            int ty = cur % W;
            ch = g[tx][ty];
            
            // 把当前点上下左右的点加入队列
            for(int i = 0; i < 4; i++) {
                int ttx = tx + dirs[i];
                int tty = ty + dirs[i+1];
                if(ttx < 0 || tty < 0 || ttx >= H || tty >= W) {
                    continue;
                }
                if(dis[ttx][tty] != maxv) {
                    continue;
                }
                if(g[ttx][tty] == '#') {
                    continue;
                }
                dis[ttx][tty] = min(dis[ttx][tty], dis[tx][ty] + 1);
                if(g[ttx][tty] == 'S') {
                    printf("%d", dis[ttx][tty]);
                    return 0;
                }
                q.push(ttx*W + tty);
            }

            // 如果当前点是a~z，则把其他相同字母的房间也加入队列
            if(islower(ch) && !visited_rooms[ch -'a']) {
                visited_rooms[ch -'a'] = 1;
                for(auto &i : rooms[ch -'a']) {
                    int ttx = i / W;
                    int tty = i % W;
                    if(dis[ttx][tty] != maxv) continue;
                    dis[ttx][tty] = dis[tx][ty] + 1;
                    q.push(ttx*W + tty);
                }
            }
        }
    }
    
    printf("-1");
    return 0;
}