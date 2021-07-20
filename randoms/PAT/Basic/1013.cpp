/**
 * @file 1013.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23};
    int M, N;
    cin >> M >> N;

    int num = primes.back() + 1;
    while(primes.size() < (size_t)N) {
        bool is_prime = true;
        for(auto i : primes) {
            if(num % i == 0) {
                is_prime = false;
                break;
            }
        }
        // 优化一下，解决超时问题
        // 如果当前是质数，那直接加2，因为加1结果必然是偶数
        if(is_prime) {
            primes.push_back(num);
            num += 2;
        } else {
            num += 1;
        }
    }

    int count = 0;
    for(int i = M-1; i <= N-1; i++) {
        ++count;
        if(i == N-1) {
            cout << primes[i];
        } else if(count % 10 == 0) {
            cout << primes[i] << endl;
        } else {
            cout << primes[i] << " ";
        }
    }

    return 0;
}