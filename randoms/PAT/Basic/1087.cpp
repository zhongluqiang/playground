/**
 * @file 1087.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1038429191091781632
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    set<int> ans;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        ans.insert(i/2 + i/3 + i/5);
    }
    cout << ans.size() << endl;
    return 0;
}