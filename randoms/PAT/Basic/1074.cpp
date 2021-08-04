/**
 * @file 1074.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805263297527808
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

int main() {
    string weight;
    string a, b;
    string ans;

    cin >> weight >> a >> b;

    reverse(weight.begin(), weight.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int i;
    int tmp;
    int w;
    int carry = 0;
    for(i = 0; i < a.size() && i < b.size(); i++) {
        if(weight[i] == '0' || weight[i] == 'd') {
            w = 10; // 测试点3 4
        } else {
            w = weight[i] - '0';
        }
        tmp = a[i] - '0' + b[i] - '0' + carry;
        carry = tmp / w;
        ans.push_back(tmp % w + '0');
    }

    while(i < a.size()) {
        if(weight[i] == '0' || weight[i] == 'd') {
            w = 10;
        } else {
            w = weight[i] - '0';
        }
        tmp = a[i] - '0' + carry;
        carry = tmp / w;
        ans.push_back(tmp % w + '0');
        i++;
    }

    while(i < b.size()) {
        if(weight[i] == '0' || weight[i] == 'd') {
            w = 10;
        } else {
            w = weight[i] - '0';
        }
        tmp = b[i] - '0' + carry;
        carry = tmp / w;
        ans.push_back(tmp % w + '0');
        i++;
    }

    if(carry) {
        ans.push_back('1');
    }
    while(ans.back() == '0') {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    if(ans.empty()) {
        cout << "0" << endl; // 测试点5
    } else {
        cout << ans << endl;
    }
    return 0;
}