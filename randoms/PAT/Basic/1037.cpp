/**
 * @file 1037.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805284923359232
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string p, a;
    
    cin >> p >> a;

    long long x, y, z;
    long long n1, n2;

    x = stoi(p.substr(0, p.find('.')));
    y = stoi(p.substr(p.find('.')+1, p.rfind('.')));
    z = stoi(p.substr(p.rfind('.')+1));
    n1 = z + y*29 + x*17*29;

    x = stoi(a.substr(0, a.find('.')));
    y = stoi(a.substr(a.find('.')+1, a.rfind('.')));
    z = stoi(a.substr(a.rfind('.')+1));
    n2 = z + y*29 + x*17*29;

    if(n2 < n1) {
        cout << "-";
    }

    n1 = llabs(n1 - n2);
    cout << n1/17/29 << "." << n1%(17*29)/29 << "." << n1 % 29;

    return 0;
}