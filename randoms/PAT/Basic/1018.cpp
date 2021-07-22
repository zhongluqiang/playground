/**
 * @file 1018.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805304020025344
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int flag[255][255];
    memset(flag, 0xff, sizeof(flag)); // -1
    flag['C']['J'] = 1;
    flag['J']['B'] = 1;
    flag['B']['C'] = 1;
    flag['C']['C'] = 0;
    flag['J']['J'] = 0;
    flag['B']['B'] = 0;

    int N;
    char A, B;
    int winA = 0, drawA = 0, failA = 0;
    int AcountC = 0, AcountJ = 0, AcountB = 0;
    int BcountC = 0, BcountJ = 0, BcountB = 0;


    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A >> B;
        if(flag[A][B] > 0) {
            winA++;
            if(A == 'C') {
                AcountC++;
            } else if(A == 'J') {
                AcountJ++;
            } else {
                AcountB++;
            }
        } else if(flag[A][B] == 0) {
            drawA++;
        } else {
            failA++;
            if(B == 'C') {
                BcountC++;
            } else if(B == 'J') {
                BcountJ++;
            } else {
                BcountB++;
            }
        }
    }

    cout << winA << " " << drawA << " " << failA << endl;
    cout << failA << " " << drawA << " " << winA << endl;

    int maxA = max(max(AcountB, AcountC), AcountJ);
    int maxB = max(max(BcountB, BcountC), BcountJ);

    if(maxA == AcountB) {
        cout << "B ";
    } else if(maxA == AcountC) {
        cout << "C ";
    } else {
        cout << "J ";
    }

    if(maxB == BcountB) {
        cout << "B";
    } else if(maxB == BcountC) {
        cout << "C";
    } else {
        cout << "J";
    }
    return 0;
}