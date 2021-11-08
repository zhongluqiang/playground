/**
 * @file test_partition.cpp
 * @author midlane.top
 * @brief 测试分割算法
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "partition/partition.h"
#include "util/util.h"
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm> // std::random_shuffle, std::max_element
using namespace std;

#define SIZE 10

void test1() {
    printf("test1 start\n");
    int a[SIZE], b[SIZE];
    int mid, max1, pivot, max2;
    randomize(a, SIZE);
    memcpy(b, a, sizeof(a));
    for (int i = 0; i < 20000; i++) {
        random_shuffle(a, a + SIZE);
        mid  = partition1(a, 0, SIZE - 1);

        if(mid == 0) {
            max1 = pivot = a[0];
        } else {
            max1 = *max_element(a, a + mid);
        }

        pivot = a[mid];

        if(mid == SIZE - 1) {
            max2 = pivot = a[SIZE - 1];
        } else {
            max2 = *max_element(a + mid + 1, a + SIZE);
        }
        if(!(max1 <= pivot && pivot <= max2)) {
            printf("test fail: mid=%d, max1=%d, pivot=%d, max2=%d\n", mid, max1, pivot, max2);
            trace(b, SIZE);
            trace(a, SIZE);
        }
    }
    printf("test1 end\n");
}

void test2() {
    printf("test2 start\n");
    int a[SIZE], b[SIZE];
    int mid, max1, max2;
    randomize(a, SIZE);
    memcpy(b, a, sizeof(a));
    for (int i = 0; i < 20000; i++) {
        random_shuffle(a, a + SIZE);
        mid  = partition2(a, 0, SIZE - 1);
        max1 = *max_element(a, a + mid);
        if(mid == SIZE - 1) {
            max2 = a[SIZE - 1];
        } else {
            max2 = *max_element(a + mid + 1, a + SIZE);
        }
        if(max1 > max2) {
            printf("test fail: mid=%d, max1=%d, max2=%d\n", mid, max1, max2);
            trace(b, SIZE);
            trace(a, SIZE);
        }
    }
    printf("test2 end\n");
}

void simple_test() {
    {
        int a[] = {5, 5, 1, 9, 2, 5, 7, 4, 8, 6};
        trace(a, ARRAYSIZE(a));
        int mid = partition1(a, 0, ARRAYSIZE(a)-1);
        printf("mid=%d\n", mid);
        trace(a, ARRAYSIZE(a));
    }
    printf("\n");
    {
        int a[] = {4, 9, 5, 2, 3, 8, 6, 0 , 1, 7};
        trace(a, ARRAYSIZE(a));
        int mid = partition2(a, 0, ARRAYSIZE(a)-1);
        printf("mid=%d\n", mid);
        trace(a, ARRAYSIZE(a));
    }
    printf("\n");
    {
        int a[] = {9, 8, 0, 8, 9, 1, 0, 1, 9, 5};
        trace(a, ARRAYSIZE(a));
        int mid = partition2(a, 0, ARRAYSIZE(a)-1);
        printf("mid=%d\n", mid);
        trace(a, ARRAYSIZE(a));
    }
    printf("\n");
    {
        int a[] = {9, 10, 11, 12};
        trace(a, ARRAYSIZE(a));
        int mid = partition2(a, 0, ARRAYSIZE(a)-1);
        printf("mid=%d\n", mid);
        trace(a, ARRAYSIZE(a));
    }
}

int main() {
    simple_test();
    test1();
    test2();
    return 0;
}