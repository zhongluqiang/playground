/**
 * @file 1089.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1038429385296453632
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> players(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> players[i];
    }

    vector<int> goodman(n+1, 1);
    int i, j;
    for(int i = 1; i <= n-1; i++) {
        goodman[i] = -1;
        for(int j = i+1; j <= n; j++) {
            goodman[j] = -1;
            int liars = 0, wolves = 0; // 统计说谎次数，狼人数
            for(int k = 1; k <= n; k++) {
                if(goodman[abs(players[k])] * players[k] < 0) {
                    liars++;
                    if(k == i || k == j) {
                        wolves++;
                    }
                }
            }
            if(liars == 2 && wolves == 1) { // 满足总共有2人说谎，其中1人是狼人即可
                cout << i << " " << j;
                return 0;
            }
            goodman[j] = 1;
        }
        goodman[i] = 1;
    }
    cout << "No Solution";
    return 0;
}