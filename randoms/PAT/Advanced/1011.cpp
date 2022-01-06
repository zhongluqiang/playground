/**
 * @file 1011.cpp
 * @author midlane.top
 * @brief 1011 World Cup Betting
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    const char result[3] = {'W', 'T', 'L'};
    double game[3][3]; // game[i][j] 第i场比赛结局为j为赔率
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> game[i][j];
        }
    }

    double maxodds = 0;
    int x, y, z;
    for(int b1 = 0; b1 < 3; b1++) {
        for(int b2 = 0; b2 < 3; b2++) {
            for(int b3 = 0; b3 < 3; b3++) {
                if(game[0][b1] * game[1][b2] * game[2][b3] > maxodds) {
                    maxodds = game[0][b1] * game[1][b2] * game[2][b3];
                    x = b1;
                    y = b2;
                    z = b3;
                }
            }
        }
    }

    cout << result[x] << " " << result[y] << " " << result[z] << " ";
    printf("%.2f", (maxodds * 0.65 - 1) * 2);
    return 0;
}