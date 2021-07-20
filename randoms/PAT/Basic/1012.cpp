/**
 * @file 1012.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805311146147840
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N;
    vector<int> nums;
    int A1 = 0, A2 = 0, A3 = 0, A5 = INT_MIN;
    float A4 = 0;
    bool minus = false;
    int countA1 = 0, countA2 = 0, countA3 = 0, countA4 = 0, countA5 = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    for(auto i : nums) {
        int remainder = i % 5;
        if(remainder == 0) {
            if(i % 2 == 0) {
                A1 += i;
                ++countA1;
            }
        } else if(remainder == 1) {
            ++countA2;
            if(minus) {
                A2 -= i;
            } else {
                A2 += i;
            }
            minus = !minus;
        } else if(remainder == 2) {
            ++countA3;
            A3++;
        } else if(remainder == 3) {
            ++countA4;
            A4 += i;
        } else {
            ++countA5;
            A5 = max(A5, i);
        }
    }

    if(countA1) {
        printf("%d ", A1);
    } else {
        printf("N ");
    }

    if(countA2) {
        printf("%d ", A2);
    } else {
        printf("N ");
    }

    if(countA3) {
        printf("%d ", A3);
    } else {
        printf("N ");
    }

    if(countA4) {
        printf("%.1f ", (float)A4/countA4);
    } else {
        printf("N ");
    }

    if(countA5) {
        printf("%d", A5);
    } else {
        printf("N");
    }

    return 0;
}