/**
 * @file 1014.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560
 * @version 0.1
 * @date 2021-07-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<string> weekdays = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    size_t i, j;
    int c1, c2, c3;
    bool found = false;
    for(i = 0, j = 0; i < s1.size() && j < s2.size(); i++, j++) {
        if(s1[i] == s2[j]) {
            if(!found && isupper(s1[i]) && s1[i] >= 'A' && s1[i] <= 'G') {
                c1 = s1[i];
                found = true;
            } else if(found && isalnum(s1[i])) {
                if((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N')){
                    c2 = s1[i];
                    break;
                }
            }
        }
    }
    for(i = 0, j = 0; i < s3.size() && j < s4.size(); i++, j++) {
        if(s3[i] == s4[j] && isalpha(s3[i])) {
            c3 = i;
            break;
        }
    }
    
    string weekday = weekdays[c1 - 'A'];
    int hours = (isdigit(c2) ? (c2 - '0'): (c2 - 'A' + 10));
    int minutes = c3;
    printf("%s %02d:%02d", weekday.c_str(), hours, minutes);
    return 0;
}