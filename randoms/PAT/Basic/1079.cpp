/**
 * @file 1079.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805261754023936
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool ispalindrome(string s) {
    if(s.empty()) {
        return false;
    }
    if(s.size() == 1) {
        return true;
    }
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size()-i-1]) {
            return false;
        }
    }
    return true;
}

string strnum_add(string s1, string s2) {
    if(s1.empty()) {
        return s2;
    }
    if(s2.empty()) {
        return s1;
    }

    int carry = 0;
    string ans;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(int i = 0; i < s1.size(); i++) {
        int sum = s1[i] - '0' + s2[i] - '0' + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum + '0');
    }
    if(carry) {
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string num;
    int count = 0;

    cin >> num;

    while(count < 10 && !ispalindrome(num)) {
        cout << num << " + ";
        string s2 = num;
        reverse(s2.begin(), s2.end());
        cout << s2 << " = ";
        num = strnum_add(num, s2);
        cout << num << endl;
        count++;
    }
    if(count == 10) {
        cout << "Not found in 10 iterations." << endl;
    } else {
        cout << num << " is a palindromic number." << endl;
    }
    return 0;
}