/**
 * @file 1022.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    uint64_t A, B, D;
    vector<int> ans;
    uint64_t sum;

    cin >> A >> B >> D;

    sum = A + B;

    while(sum >= D) {
        ans.push_back(sum % D);
        sum = sum / D;
    }
    ans.push_back(sum);
    
    for(auto it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it;
    }
    return 0;
}