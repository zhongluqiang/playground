/**
 * @file 1009.cpp
 * @author midlane.top
 * @brief 1009 Product of Polynomials
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct Term {
    int exp;        // 指数
    double coeff;   // 系数
    Term(int e, double c): exp(e), coeff(c) {}
};

Term operator*(Term &t1, Term &t2) {
    return Term(t1.exp + t2.exp, t1.coeff * t2.coeff);
}

int main() {
    vector<Term> a, b;
    double ans[1000001] = {0}; // ans[i]表示A*B结果中指数为i的项的系数
    int k, exp;
    double coeff;

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> exp >> coeff;
        a.emplace_back(Term(exp, coeff));
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> exp >> coeff;
        b.emplace_back(Term(exp, coeff));
    }

    // 多项式乘法A的每一项乘遍B的所有项，再累加
    for(auto &t1 : a) {
        for(auto &t2 : b) {
            auto r = t1 * t2;
            ans[r.exp] += r.coeff;
        }
    }

    // 统计非零项
    int ansK = 0;
    for(int i = 0; i <= 1000000; i++) {
        if(fabs(ans[i]) < 0.1) {
            ans[i] = 0;
        }
        if(ans[i]) {
            ansK++;
        }
    }
    cout << ansK;
    // 按指数从高到低输出每个项
    for(int i = 1000000; i >= 0; i--) {
        if(ans[i]) {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}