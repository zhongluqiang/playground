/**
 * @file 1082.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805260990660608
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
    int n;
    string s1, s2;
    int min = INT_MAX, max = INT_MIN;

    cin >> n;
    string tmp;
    int x, y, m;
    for(int i = 0; i < n; i++) {
        cin >> tmp >> x >> y;
        m = x*x + y*y;
        if(m < min) {
            s1 = tmp;
            min = m;
        }
        if(m > max) {
            s2 = tmp;
            max = m;
        }
    }
    cout <<s1 << " " << s2 << endl;
    return 0;
}