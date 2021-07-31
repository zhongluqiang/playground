/**
 * @file 1056.cpp
 * @author midlane.top
 * @brief 组合数的和 https://pintia.cn/problem-sets/994805260223102976/problems/994805271455449088
 * @version 0.1
 * @date 2021-07-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main() {
    int n;
    int num;
    int total = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        total += (num * 10 * (n-1) + num * (n-1));
    }
    cout << total << endl;
    return 0;
}