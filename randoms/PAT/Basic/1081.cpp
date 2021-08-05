/**
 * @file 1081.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805261217153024
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        if(s.length() < 6) {
            cout << "Your password is tai duan le." << endl;
            continue;
        }
        transform(s.begin(), s.end(), s.begin(), [](char c) {
            return tolower(c);
        });
        if(s.find_first_not_of("qwertyuiopasdfghjklmnbvcxz0123456789.") != string::npos) {
            cout << "Your password is tai luan le." << endl;
            continue;
        }
        if(s.find_first_of("0123456789") == string::npos) {
            cout << "Your password needs shu zi." << endl;
            continue;
        }
        if(s.find_first_of("qwertyuiopasdfghjklmnbvcxz") == string::npos) {
            cout << "Your password needs zi mu." << endl;
            continue;
        }
        cout << "Your password is wan mei." << endl;
    }
    return 0;
}