/**
 * @file 1039.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805283241443328
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    int count1[256] = {0};
    int count2[256] = {0};
    int sum1 = 0, sum2 = 0;

    getline(cin, s1);
    getline(cin, s2);

    for(auto &ch : s1) {
        count1[ch]++;
        sum1++;
    }
    for(auto &ch : s2) {
        count2[ch]++;
        sum2++;
    }

    int flag = 0;
    int v = 0;

    for(int i = 0; i < 256; i++) {
        if(count2[i] > 0) {
            if(count1[i] < count2[i])  {
                flag = 1;
                v += count2[i] - count1[i];
            }
        }
    }

    if(flag == 0) {
        cout << "Yes " << sum1 - sum2;
    } else {
        cout << "No " << v;
    }

    return 0;
}