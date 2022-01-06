/**
 * @file 1010.cpp
 * @author midlane.top
 * @brief 1010 Radix
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

static inline int char2num(char ch) {
    switch(ch) {
        case '0'...'9':  return ch - '0';
        case 'a'...'z': return ch - 'a' + 10;
        default: return 0;
    }
}

static inline ll str2num(string s, ll radix) {
    ll ans = 0;
    for(auto ch : s) {
        ans = ans * radix + char2num(ch);
    }
    return ans;
}

int main() {
    string N1, N2;
    ll tag, radix;
    ll n1, n2;
    
    cin >> N1 >> N2 >> tag >> radix;

    // 交换N1和N2以简化流程
    if(tag == 2) {
        swap(N1, N2);
    }

    n1 = str2num(N1, radix);
    ll low = char2num(*max_element(N2.begin(), N2.end())) + 1;
    ll high = n1 + 1;
    ll mid;

    while(low <= high) {
        mid = low + (high - low) / 2;
        n2 = str2num(N2, mid);
        if(n2 < 0 || n2 > n1) {
            high = mid - 1;
        } else if(n2 == n1) {
            cout << mid;
            return 0;
        } else {
            low = mid + 1;
        }
    }

    cout << "Impossible";
    
    return 0;
}