/**
 * @file 1088.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1038429286185074688
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void print(double my, double other) {
    if(my - other > 1e-6) cout << " Gai";
    else if(my - other < -1e-6) cout << " Cong";
    else cout << " Ping";
}

int main() {
    double a, b, c; // 甲乙丙
    double m, x, y;
    
    cin >> m >> x >> y;

    for(int i = 99; i >= 10; i--) {
        a = i;
        b = i / 10 + (i % 10) * 10;
        c = b / y;
        if(fabs(a - b) == x * c) {
            cout << a;
            print(m, a);
            print(m, b);
            print(m, c);
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}