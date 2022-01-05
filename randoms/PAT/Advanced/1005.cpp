/**
 * @file 1005.cpp
 * @author midlane.top
 * @brief 1005 Spell It Right
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string N;
string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    int sum = 0;
    string sumstr;

    cin >> N;
    for(auto ch : N) {
        sum += ch - '0';
    }

    sumstr = to_string(sum);
    for(int i = 0; i < sumstr.size(); i++) {
        if(i == 0) {
            cout << digits[sumstr[i] - '0'];
        } else {
            cout << " " << digits[sumstr[i] - '0'];
        }
    }
    return 0;
}