/**
 * @file 1062.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805268334886912
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    long long n1, m1, n2, m2, k;
    scanf("%lld/%lld %lld/%lld %lld", &n1, &m1, &n2, &m2, &k);
    
    vector<long long> divs{1};
    for(long long i = 2; i < k; i++) {
        if(gcd(k , i) == 1) {
            divs.push_back(i);
        }
    }

    long long low = min(n1*k*m2, n2*k*m1);
    long long high = max(n1*k*m2, n2*k*m1);
    bool first = true;
    for(long long i = 0; i < divs.size(); i++) {
        if(divs[i]*m1*m2 > low && divs[i]*m1*m2 < high) {
            if(first) {
                printf("%lld/%lld", divs[i], k);
                first = false;
            } else {
                printf(" %lld/%lld", divs[i], k);
            }
        }
    }
    return 0;
}