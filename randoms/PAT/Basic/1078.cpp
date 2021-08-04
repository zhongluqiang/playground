/**
 * @file 1078.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805262018265088
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string op, s;
    cin >> op;
    getchar();
    getline(cin, s);

    if(op == "C") {
        int p1, p2;
        p1 = p2 = 0;
        while(p1 < s.size()) {
            p2 = p1;
            while(p2 < s.size() && s[p2] == s[p1]) {
                p2++;
            }
            p2--;
            if(p1 == p2) {
                printf("%c", s[p1]);
                p1 = p2+1;
            } else {
                printf("%d%c", p2-p1+1, s[p1]);
                p1 = p2+1;
            }
        }
    } else if(op == "D") {
        int p1, p2;
        p1 = p2 = 0;
        while(p1 < s.size()) {
            if(isalpha(s[p1]) || isspace(s[p1])) {
                printf("%c", s[p1]);
                p1++;
                continue;
            }
            p2 = p1;
            while(isdigit(s[p2])) {
                p2++;
            }
            char ch = s[p2];
            int count = stoi(s.substr(p1, p2));
            for(int i = 0; i < count; i++) {
                printf("%c", ch);
            }
            p2++;
            p1 = p2;
        }
    }
    return 0;
}