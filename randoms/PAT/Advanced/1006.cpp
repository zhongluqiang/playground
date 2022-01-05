/**
 * @file 1006.cpp
 * @author midlane.top
 * @brief 1006 Sign In and Sign Out
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Record{
    string id;
    int in;
    int out;
};

int M;
vector<Record> v;

int main() {
    int h1, m1, s1, h2, m2, s2;
    char _ch;

    cin >> M;
    v.resize(M);
    for(int i = 0; i < M; i++) {
        cin >> v[i].id;
        cin >> h1 >> _ch >> m1 >> _ch >> s1 >> h2 >> _ch >> m2 >> _ch >> s2;
        v[i].in  = h1 * 3600 + m1 * 60 + s1;
        v[i].out = h2 * 3600 + m2 * 60 + s2;
    }

    sort(v.begin(), v.end(), [](Record &a,Record &b){
        return a.in < b.in;
    });
    cout << v[0].id;

    sort(v.begin(), v.end(), [](Record &a,Record &b){
        return a.out > b.out;
    });
    cout << " " << v[0].id;

    return 0;
}