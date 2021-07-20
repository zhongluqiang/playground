#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;

    cin >> n;

    while (n != 1) {
        if(n & 0x1) {
            n = (3*n+1) >> 1;
        } else {
            n >>= 1;
        }
        ++ans;
    }

    cout << ans;
    return 0;
}