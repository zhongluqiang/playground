/**
 * @file 1046.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805277847568384
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
    int a, b, c, d;
    int x = 0, y = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        if(a + c == b && a + c == d) {
            continue;
        } else if (a + c != b && a + c != d) {
            continue;
        } else if( a + c == b) {
            y++;
        } else {
            x++;
        }
    }

    cout << x << " " << y << endl;
    return 0;
}