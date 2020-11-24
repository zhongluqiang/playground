#include <bits/stdc++.h>
using namespace std;
typedef long double LD;
const int N = 110;
LD f[N][N][N]; // 以i,j,k为初始状态下，达成任意颜色硬币的数量到100时的期望价值（Expected Value）
int A, B, C;   // 初始状态

/*
计算以a,b,c为初始状态、重复操作直到a,b,c任意一个达到100时的期望操作次数。
例如计算以90,10,20为初始状态，重复操作直到任意一个值到达100为例，计算过程如下：
由于a,b,c都有可能达到100，那么分以下几种情况：
1. a先到100，那最好的结束情况是100, 10, 20，也就是一直拿的是a硬币，只需要操作(100-90)次，最坏的结束情况是100, 99, 99，
也就是先把b硬币和c硬币拿到不能再拿为止，再开始拿a硬币，需要操作的次数是(100-99)+(99-10)+(99-20)次。归纳一下，假如结束情况是100 x y，那么操作次数就是(100-99)+(x-10)+(y-20)次。

2. b和c各自先到100的过程与a类似。

3. 在没到结束状态之前，也就是a,b,c都没到100之前，每次拿都有可能拿到三种硬币中的一种，拿到任意一种硬币的概率是这种硬币的数量占总数的百分比，例如拿到a硬币的概率是a/(a+b+c)。
由于拿出1个硬币后会再往里放入2个硬币，相当于数量加1，那么在a,b,c状态下，如果拿到a硬币，那拿完之后状态就 a+1 b c，如果拿到b硬币，那拿完之后状态就是a b+1 c，以此类推。
这里应用一下dp思路，如果知道拿完之后的状态的期望，那当前状态的期望就等于拿到每种硬币的概率与拿完之后状态的期望的乘积之和，也就是下面的公式：
sum = a+b+c
dfs(a, b, c) = a/sum*dfs(a+1, b, c) + b/sum*dfs(a, b+1, c) + c/sum*dfs(a, b, c+1)
*/
LD dfs(int a, int b, int c) {
    if (a == 100 || b == 100 || c == 100)
        return a - A + b - B + c - C;
    LD *ans = &f[a][b][c];
    if (*ans != -1.0)
        return *ans;
    int tot = a + b + c;
    *ans    = ((LD)a / (LD)tot) * dfs(a + 1, b, c);
    *ans += ((LD)b / (LD)tot) * dfs(a, b + 1, c);
    *ans += ((LD)c / (LD)tot) * dfs(a, b, c + 1);
    return *ans;
}

int main() {
    cin >> A >> B >> C;
    for (int i = 0; i <= 100; ++i)
        for (int j = 0; j <= 100; ++j)
            for (int k = 0; k <= 100; ++k)
                f[i][j][k] = -1;
    auto ans = dfs(A, B, C);
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
