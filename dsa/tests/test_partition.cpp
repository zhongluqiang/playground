/**
 * @file test_partition.cpp
 * @author midlane.top
 * @brief 测试分割函数
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "partition/partition.h"
#include "util/util.h"
#include <cstdio>

void test1() {
    int a[] = {5, 5, 1, 9, 2, 5, 7, 4, 8, 6};
    trace(a, ARRAYSIZE(a));
    int mid = partition1(a, 0, ARRAYSIZE(a)-1);
    printf("mid=%d\n", mid);
    trace(a, ARRAYSIZE(a));
}

void test2() {
    //int a[] = {7, 5, 9, 2, 3, 4, 1, 6, 0, 8};
    int a[] = {4, 9, 5, 2, 3, 8, 6, 0 , 1, 7};
    trace(a, ARRAYSIZE(a));
    int mid = partition2(a, 0, ARRAYSIZE(a)-1);
    printf("mid=%d\n", mid);
    trace(a, ARRAYSIZE(a));
}

int main() {
    test1();
    test2();
    return 0;
}