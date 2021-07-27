/**
 * @file 1047.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805277163896832
 * @version 0.1
 * @date 2021-07-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main() {
    int n;
    int teamscore[1001] = {0};
    int team, id, score;

    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        scanf("%d-%d %d", &team, &id, &score);
        teamscore[team] += score;
    }

    int max_team = 0;
    int max_score = teamscore[0];
    for(int i = 0; i < 1001; i++) {
        if(teamscore[i] > max_score) {
            max_team = i;
            max_score = teamscore[i];
        }
    }
    cout << max_team << " " << max_score << endl;
    return 0;
}