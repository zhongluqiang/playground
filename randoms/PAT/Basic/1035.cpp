/**
 * @file 1035.cpp
 * @author midlane.top
 * @brief https://pintia.cn/problem-sets/994805260223102976/problems/994805286714327040
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const string INSERT_SORT = "Insertion Sort";
const string MERGE_SORT = "Merge Sort";

vector<int> nums;
vector<int> ordered_nums;

void hehe(int x, int y) {
    if(x > y) {
        return;
    }
    hehe(x, (x+y)/2);
    if(nums == ordered_nums) {
        return;
    }
    hehe((x+y)/2+1, y);
    if(nums == ordered_nums) {
        return;
    }

}

int main() {
    int N;
    cin >> N;
    nums.resize(N);
    ordered_nums.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> ordered_nums[i];
    }

    bool insertion = true;
    int i, j;
    for(i = 0; i < nums.size() - 1; i++) {
        if(ordered_nums[i] > ordered_nums[i + 1]){
            break;
        }
    }
    for(j = i+1; j < nums.size(); j++) {
        if(nums[j] != ordered_nums[j]) {
            insertion = false;
        }
    }

    if(insertion) {
        cout << INSERT_SORT << endl;
        sort(ordered_nums.begin(), ordered_nums.begin() + i + 2);
        for(i = 0; i < ordered_nums.size() - 1; i++) {
            cout << ordered_nums[i] << " ";
        }
        cout << ordered_nums.back();
    } else {
        cout << MERGE_SORT << endl;
        int k = 1, flag = 1;
        while(flag) {
            flag = 0;
            for(i = 0; i < N; i++) {
                if(nums[i] != ordered_nums[i]) {
                    flag = 1;
                }
            }
            k = k*2;
            for(i = 0; i < N / k; i++) {
                sort(nums.begin() + i*k, nums.begin() + (i+1) * k);
            }
            sort(nums.begin()+N/k*k, nums.begin()+N);
        }
        for(i = 0; i < nums.size() - 1; i++) {
            cout << nums[i] << " ";
        }
        cout << nums.back();
    }

    return 0;
}