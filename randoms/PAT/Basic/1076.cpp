/**
 * @file 1076.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805262622244864
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        if(s[2] == 'T') printf("%c", s[0]-'A'+'1');
        else if(s[6] == 'T') printf("%c", s[4]-'A'+'1');
        else if(s[10] == 'T') printf("%c", s[8]-'A'+'1');
        else if(s[14] == 'T') printf("%c", s[12]-'A'+'1');
    }
    return 0;
}