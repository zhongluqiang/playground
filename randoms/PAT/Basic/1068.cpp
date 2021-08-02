/**
 * @file 1068.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805265579229184
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m, tol; // n行，m列
    int array[1002][1002];
    map<int, int> count;

    cin >> m >> n >> tol;
    int tmp;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> tmp;
            array[i][j] = tmp;
            if(count.find(tmp) != count.end()) {
                count[tmp]++;
            } else {
                count[tmp] = 1;
            }
        }
    }

    bool found = false;
    int x, y, color;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int cur = array[i][j];
            if(count[cur] > 1) continue;
            // 上
            if(i != 1 && abs(cur - array[i-1][j]) <= tol) continue;
            // 下
            if(i != n && abs(cur - array[i+1][j]) <= tol) continue;
            // 左
            if(j != 1 && abs(cur - array[i][j-1]) <= tol) continue;
            // 右
            if(j != m && abs(cur - array[i][j+1]) <= tol) continue;
            // 左上
            if(i != 1 && j != 1 && abs(cur - array[i-1][j-1]) <= tol) continue;
            // 右上
            if(i != 1 && j != m && abs(cur - array[i-1][j+1]) <= tol) continue;
            // 左下
            if(i != n && j != 1 && abs(cur - array[i+1][j-1]) <= tol) continue;
            // 右下
            if(i != n && j != m && abs(cur - array[i+1][j+1]) <= tol) continue;

            if(!found) {
                found = true;
                x = j;
                y = i;
                color = cur;
                //printf("found: (%d:%d) %d\n", x, y, color);
            } else {
                cout << "Not Unique" << endl;
                return 0;
                //cout << "Not Unique:" << i << ":" << j << endl;
            }
        }
    }
    if(!found) {
        cout << "Not Exist" << endl;
    } else {
        printf("(%d, %d): %d\n", x, y, color);
    }
    return 0;
}