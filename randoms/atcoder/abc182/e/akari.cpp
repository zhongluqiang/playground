#include <bits/stdc++.h>
using namespace std;

#define EMPTY 0
#define BULB 1
#define BLOCK 2
#define LIGHT 3

int H,W,N,M;
vector<pair<int, int>> bulbs;
vector<vector<int>> grid;

int main() {
    cin >> H >> W >> N >> M;
    grid = vector<vector<int>>(H, vector<int>(W, EMPTY));
    int a, b, c, d;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        bulbs.push_back({a-1, b-1});
        grid[a-1][b-1] = BULB;
    }
    for(int i = 0; i < M; i++) {
        cin >> c >> d;
        grid[c-1][d-1] = BLOCK;
    }

    // visited[i][j][index] grid[i][j]位置的灯的index方向是否被访问过
    vector<vector<vector<int>>> visited(H, vector<vector<int>>(W, vector<int>(4, 0)));
    vector<int> dirs{0, 1, 0, -1, 0};
    int r, h, tr, th;
    // 循环每个灯，向上下左右扩展，直到扩展到block
    // 每次扩展时记录当前灯和扩展到的灯的该方向是否访问过，便于去除重复计算，否则会TLE
    for(int i = 0; i < N; i++) {
        for(int index = 0; index < 4; index++) {
            r = bulbs[i].first;
            h = bulbs[i].second;
            if(visited[r][h][index]) {
                continue;
            }
            visited[r][h][index] = true;
            tr = r + dirs[index];
            th = h + dirs[index+1];
            while(tr >= 0 && tr < H && th >= 0 && th < W) {
                if(grid[tr][th] == BLOCK) {
                    break;
                }
                if(grid[tr][th] == BULB) {
                    visited[tr][th][index] = true;
                }
                if(grid[tr][th] == EMPTY) {
                    grid[tr][th] = LIGHT;
                }
                tr += dirs[index];
                th += dirs[index+1];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(grid[i][j] == BULB || grid[i][j] == LIGHT) {
                ans++;
            }
        }
    }

    printf("%d", ans);
    return 0;
}