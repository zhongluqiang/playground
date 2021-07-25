/**
 * @file 1036.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805285812551680
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main() {
    int n;
    char c;

    cin >> n >> c;
    int lines;
    if(n & 0x1) {
        lines = n/2+1;
    } else {
        lines = n/2;
    }

    for(int i = 0; i < n; i++) {
        cout << c;
    }
    cout << endl;
    lines--;
    if(lines == 1) {
        for(int i = 0; i < n; i++) {
            cout << c;
        }
        return 0;
    } else {
        for(int i = 0; i < lines-1; i++) {
            cout << c;
            for(int j = 0; j < n-2; j++) {
                cout << " ";
            }
            cout << c << endl;
        }
        for(int i = 0; i < n; i++) {
            cout << c;
        }
    }
    return 0;
}