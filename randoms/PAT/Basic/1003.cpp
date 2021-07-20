#include <bits/stdc++.h>
using namespace std;

bool isPAT(const string & s) {
    if(s.size() < 3) {
        return false;
    }
    if(s.find_first_not_of("PAT") != string::npos) {
        // 不能包含除PAT外的字符
        return false;
    }
    if(s.find('P') == string::npos || s.find('A') == string::npos || s.find('T') == string::npos) {
        // 必须PAT三个字符都包含
        return false;
    }
    // 归纳一下，P开头的话只能是PAAAA...AT的形式，A开头的话只能是(A*x)P(A*y)T(A*x*y)的形式
    // 统一之后的形式是(A*x)P(A*y)T(A*x*y), x>=0, y>=1
    int pos_P = s.find_first_of('P');
    int pos_T = s.find_first_of('T');
    int x = pos_P;
    int y = pos_T - pos_P - 1;
    int z = s.size() - pos_T - 1;
    if(y < 1 || z != x * y) {
        return false;
    }
    return true;
}

int main() {
    int n;
    vector<string> strs;
    
    cin >> n;
    if(n <= 0) {
        return 0;
    }

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    for(size_t i = 0; i < strs.size() - 1; i++) {
        if(isPAT(strs[i])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    cout << (isPAT(strs.back()) ? "YES" : "NO");
    
    return 0;
}