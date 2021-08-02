/**
 * @file 1067.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805266007048192
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string password;
    cin >> password >> n;
    getchar();

    string tmp;
    while(n-- > 0) {
        getline(cin, tmp);
        if(tmp == "#") {
            return 0;
        }
        if(tmp != password) {
            cout << "Wrong password: " << tmp << endl;
        } else {
            cout << "Welcome in" << endl;
            return 0;
        }
    }
    cout << "Account locked" << endl;
    return 0;
}