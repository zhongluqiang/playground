题目链接：https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=52

题意：

解题思路：
在不考虑输出路径的情况下，这题就是数字三角形DP的变题，用g[m][n]表示输入矩阵，用dp[i][j]表示从i,j位置到最后一列的最小开销，那么有以下dp方程：
```
dp[i][j] = g[i][j] | j == n
dp[i][j] = g[i][j] + min{dp[i-1][j+1], dp[i][j+1], dp[i+1][j+1]} | j != n
```
因为g[m][n]的第一行和最后一行是相互连接的，在边界点上需适时对i-1，i+1进行纠正。

最后结果存储在dp数组的第一列中，求出dp[1][1]~dp[m][1]的最小值就是整个dp的最优解。

示例代码如下：
```cpp
#include <bits/stdc++.h>
using namespace std;

int m, n; // m行 n列
int g[15][110]; // 最大不超过10行 100列，有效数据下标从1开始
int dp[15][110]; // dp[i][j]表示从i,j位置出发到最后一列的开销，i,j从1开始，最后结果存储在dp[i][1]中

int main() {
    //freopen("./case1.txt", "r", stdin);
    while(cin >> m >> n) {
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> g[i][j];
            }
        }

        // 从最后一列往左递推
        for(int j = n; j >= 1; j--) {
            for(int i = 1; i <= m; i++) {
                if(j == n) {
                    // 最后一列的dp[i][j]就是g[i][j]
                    dp[i][j] = g[i][j];
                } else {
                    // 其他列的dp[i][j]通过j+1列来进行递推
                    // dp[i][j] = g[i][j] + min{dp[i-1][j+1], dp[i][j+1], dp[i+1][j+1]}
                    int row1 = i-1;
                    int row2 = i;
                    int row3 = i+1;
                    // 纠正第一行的上一行和最后一行的下一行
                    if(row1 == 0) row1 = m;
                    if(row3 == m+1) row3 = 1;
                    dp[i][j] = g[i][j] + min(min(dp[row1][j+1], dp[row2][j+1]), dp[row3][j+1]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 1; i <= m; i++) {
            // 结果存储在第1列中，求第1列的最小值
            ans = min(ans, dp[i][1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
```

增加输出路径，并且要求输出字典序最小的路径，上面的dp过程仍然不变，dp结束之后，从第1列的起点开始往右反推即可，每次推导时，只需要关心与起点相邻的三个点，比如起点是(i,j)，那那么需要关心(i-1,j+1),(i,j+1),(i+1,j+1)三个点，具体取哪个点可以通过dp[i][j]和g[i][j]来推导，根据dp方程，下一个点的dp值应该等于dp[i][j]-g[i][j]，以字典序遍历(i-1,j+1),(i,j+1),(i+1,j+1)三个点，逐个比较dp值是否为dp[i][j]-g[i][j]即可。

示例代码：
```cpp
#include <bits/stdc++.h>
using namespace std;

int m, n; // m行 n列
int g[15][110]; // 最大不超过10行 100列，有效数据下标从1开始
int dp[15][110]; // dp[i][j]表示从i,j位置出发到最后一列的开销，i,j从1开始，最后结果存储在dp[i][1]中

int main() {
    //freopen("./case1.txt", "r", stdin);
    while(cin >> m >> n) {
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> g[i][j];
            }
        }

        // 从最后一列往左递推
        for(int j = n; j >= 1; j--) {
            for(int i = 1; i <= m; i++) {
                if(j == n) {
                    // 最后一列的dp[i][j]就是g[i][j]
                    dp[i][j] = g[i][j];
                } else {
                    // 第j列的dp[i][j]通过j+1列来进行递推
                    // dp[i][j] = g[i][j] + min{dp[i-1][j+1], dp[i][j+1], dp[i+1][j+1]}
                    int row1 = i-1;
                    int row2 = i;
                    int row3 = i+1;
                    // 纠正第一行的上一行和最后一行的下一行
                    if(row1 == 0) row1 = m;
                    if(row3 == m+1) row3 = 1;
                    dp[i][j] = g[i][j] + min(min(dp[row1][j+1], dp[row2][j+1]), dp[row3][j+1]);
                }
            }
        }

        int ans = INT_MAX;
        int row = -1;
        // 结果存储在第1列中，求第1列的最小值，并记录最小值所在的行，后面以这行为起点推导路径
        for(int i = 1; i <= m; i++) {
            if(ans > dp[i][1]) {
                ans = dp[i][1];
                row = i;
            }
        }
        printf(" %d", row);

        // 从第2列开始，推导每个列应该走哪行，起点是第1列的第row行，推导过程是根据起点的dp[i][j]和g[i][j]求出右边列的dp值，
        // 判断与起点相邻的三个点，哪个dp值与之相等即可
        int col = 2;
        while(col <= n) {
            int rows[3] = {row-1, row, row+1};
            if(rows[0] == 0) rows[0] = m;
            if(rows[2] == m+1) rows[2] = 1;
            sort(rows, rows+3);
            for(int i = 0; i < 3; i++) {
                if(dp[row][col-1] - g[row][col-1] == dp[rows[i]][col]) {
                    row = rows[i];
                    printf(" %d", row);
                    break;
                }
            }
            
            col++;
        }
        printf("\n");

        printf("%d\n", ans);
    }
    return 0;
}
```