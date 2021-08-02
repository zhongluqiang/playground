/**
 * @file 1071.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805264312549376
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;
/*
玩家赢，输出 Win t! Total = x.；
玩家输，输出 Lose t. Total = x.；
玩家下注超过持有的筹码量，输出 Not enough tokens. Total = x.；
玩家输光后，输出 Game Over. 并结束程序。
*/

int main() {
    int T, K; // 筹码数，游戏次数
    int n1, b, t, n2;

    cin >> T >> K;

    for(int i = 0; i < K; i++) {
        cin >> n1 >> b >> t >> n2;
        if(t > T) {
            printf("Not enough tokens.  Total = %d.\n", T);
            continue;
        }
        if((b == 0 && n2 < n1) || (b == 1 && n2 > n1)) {
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
        } else {
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
            if(T == 0) {
                printf("Game Over.\n");
                return 0;
            }
        }
    }
    return 0;
}