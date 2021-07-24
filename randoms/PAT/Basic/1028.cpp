/**
 * @file 1028.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805293282607104
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int N;
    int count = 0;
    string eldest, youngest;

    const string maxbirthday = "2014/09/06";
    const string minbirthday = "1814/09/06";

    string cur_maxbirthday = minbirthday;
    string cur_minbirthday = maxbirthday;

    bool found_eldest = false, found_youngest = false;

    cin >> N;
    for(int i = 0; i <N; i++) {
        string name, birthday;
        cin >> name >> birthday;

        if(birthday < minbirthday || birthday > maxbirthday) {
            continue;
        }
        count++;
        cur_maxbirthday = max(cur_maxbirthday, birthday);
        cur_minbirthday = min(cur_minbirthday, birthday);
        if(cur_minbirthday == birthday) {
            eldest = name;
            found_eldest = true;
        }
        if(cur_maxbirthday == birthday) {
            youngest = name;
            found_youngest = true;
        }
    }
    cout << count;
    if(found_eldest) {
        cout << " " << eldest;
    }
    if(found_youngest) {
        cout << " " << youngest;
    }
    return 0;
}