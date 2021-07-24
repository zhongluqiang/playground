/**
 * @file 1024.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805297229447168
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    string flag;
    string x, y;
    string exp;
    int e;

    cin >> num;

    flag = num.substr(0, 1);
    x = num.substr(1, 1);
    y = num.substr(3, num.find('E') - 3);
    exp = num.substr(num.find('E') + 1);
    e = stoi(exp);

    if(flag == "-") {
        cout << flag;
    }

    if(e < 0) {
        cout << "0.";
        for(int i = e+1; i < 0; i++) {
            cout << "0";
        }
        cout << x << y;
    } else if(e == 0) {
        cout << x << "." << y;
    } else {
        cout << x;
        int i = 0;
        for(; i < e && i < y.size(); i++) {
            cout << y[i];
        }
        if(i < e) {
            while(i < e) {
                cout << "0";
                i++;
            }
        }
        if(i < y.size()) {
            cout << ".";
            while(i < y.size()) {
                cout << y[i];
                i++;
            }
        }
    }

    return 0;
}