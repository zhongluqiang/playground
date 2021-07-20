#include <bits/stdc++.h>
using namespace std;

map<char, string> table = {
    {'1', "yi"},
    {'2', "er"},
    {'3', "san"},
    {'4', "si"},
    {'5', "wu"},
    {'6', "liu"},
    {'7', "qi"},
    {'8', "ba"},
    {'9', "jiu"},
    {'0', "ling"}
};

int main() {
    string n, ans;
    int sum = 0;
    string sum_str;

    cin >> n;

    for(auto &ch : n) {
        sum += ch - '0';
    }
    sum_str = to_string(sum);
    for(auto &ch : sum_str) {
        ans += table[ch] + " ";
    }
    ans.pop_back();
    cout << ans;

    return 0;
}