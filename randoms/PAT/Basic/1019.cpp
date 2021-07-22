/**
 * @file 1019.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805302786899968
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string N;
    stringstream ss;

    cin >> N;
    while(N.size() < 4) {
        N.push_back('0');
    }

    if(N.find_last_not_of(N[0]) == string::npos) {
        cout << N << " - " << N << " = " << "0000";
        return 0;
    }

    int result = 0;
    string str1, str2;
    int n1, n2;
    while(result != 6174) {
        sort(N.begin(), N.end(), greater<int>());
        str1 = N;
        n1 = stoi(str1);
        reverse(N.begin(), N.end());
        str2 = N;
        n2 = stoi(str2);
        result = n1 - n2;
        ss << setw(4) << setfill('0') << n1 
           << " - " 
           << setw(4) << setfill('0') << n2 
           << " = " 
           << setw(4) << setfill('0') << result 
           << endl;
        N = to_string(result);
        while(N.size() < 4) {
            N.push_back('0');
        }
    }

    string ans = ss.str();
    ans.pop_back();
    cout << ans;
    return 0;
}