/**
 * @file 1054.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805272659214336
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool verify(string s) {
    if(s[0] == '-') {
        s = s.substr(1);
        if(s.empty()) {
            return false;
        }
    }
    
    if(s.find_first_not_of(".0123456789") != string::npos) {
        return false;
    }
    if(s.find_first_of('.') != s.find_last_of('.')) {
        return false;
    }
    if(s.back() == '.') {
        s.pop_back();
        if(s.empty()) {
            return false;
        }
    }

    bool dot = (s.find('.') != string::npos);
    if(dot) {
        string s1 = s.substr(0, s.find('.'));
        string s2 = s.substr(s.find('.') + 1);
        if(stoi(s1) > 1000) {
            return false;
        }
        if(s2.length() > 2) {
            return false;
        }
        if(stoi(s1) == 1000 && stoi(s2) != 0) {
            // 测试点3
            return false;
        }
        return true;
    } else {
        if(stoi(s) > 1000) {
            return false;
        }
        return true;
    }
 }

 bool verify2(string s) {
     try {
         return verify(s);
     } catch(...) {
         return false;
     }
 }

int main() {
    int n;
    vector<string> nums;
    int count = 0;
    double total = 0;

    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for(auto s : nums) {
        if(!verify2(s)) {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        } else {
            count++;
            total += atof(s.c_str());
        }
    }

    if(count == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if(count == 1) {
        printf("The average of 1 number is %.2f\n", total);
    } else {
        printf("The average of %d numbers is %.2f\n", count, total/count);
    }
    return 0;
}