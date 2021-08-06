/**
 * @file 1090.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/1038429484026175488
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, m;
    set<int> s;
    map<int, set<int>> index;

    cin >> n >> m;
    int n1, n2;
    for(int i = 0; i < n; i++) {
        cin >> n1 >> n2;
        s.insert(n1);
        s.insert(n2);
        index[n1].insert(n2);
        index[n2].insert(n1);
    }

    int count;
    set<int> nums;
    int tmp;
    bool flag;
    for(int i = 0; i < m; i++) {
        flag = false;
        nums.clear();
        cin >> count;
        for(int j = 0; j < count; j++) {
            cin >> tmp;
            if(flag) {
                continue;
            }
            if(s.count(tmp) == 0) {
                continue;
            }
            for(auto i : index[tmp]) {
                if(nums.count(i) != 0) {
                    flag = true;
                }
            }
            if(!flag) {
                nums.insert(tmp);
            }
        }
        if(flag) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}