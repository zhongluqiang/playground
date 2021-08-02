/**
 * @file 1069.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805265159798784
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n, interval, start;
    set<string> seen;
    
    cin >> n >> interval >> start;

    if(start > n) {
        cout << "Keep going..." << endl;
        return 0;
    }

    string tmp;
    int count = 0;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(--start > 0) {
            continue;
        } else {
            if(count % interval == 0) {
                if(seen.count(tmp) > 0) {
                    //count--;
                    continue;
                }
                cout << tmp << endl;
                seen.insert(tmp);
                count++;
            } else {
                count++;
            }
        }
    }
}