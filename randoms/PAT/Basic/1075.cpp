/**
 * @file 1075.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805262953594880
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int head, n, k;
    int data[100005], next[100005], list[100005];
    int tmp;

    cin >> head >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        cin >> data[tmp] >> next[tmp];
    }

    int sum = 0;
    while(head != -1) {
        list[sum++] = head;
        head = next[head];
    }

    vector<int> negative;
    vector<int> between02k;
    vector<int> greaterthank;

    // 测试点4，不能以n作为遍历次数，因为可能存在游离结点，也就是某个结点不在这条链表上
    for(int i = 0; i < sum; i++) {
        int cur_pos = list[i];
        int cur = data[cur_pos];
        if(cur < 0) {
            negative.push_back(cur_pos);
        } else if(cur >= 0 && cur <= k) {
            between02k.push_back(cur_pos);
        } else {
            greaterthank.push_back(cur_pos);
        }
    }
    
    vector<int> newlist;
    newlist.insert(newlist.end(), negative.begin(), negative.end());
    newlist.insert(newlist.end(), between02k.begin(), between02k.end());
    newlist.insert(newlist.end(), greaterthank.begin(), greaterthank.end());

    for(int i = 0; i < newlist.size(); i++) {
        printf("%05d", newlist[i]);
        printf(" %d", data[newlist[i]]);
        if(i == newlist.size()-1) {
            printf(" -1\n");
        } else {
            printf(" %05d\n", newlist[i+1]);
        }
    }
    return 0;
}