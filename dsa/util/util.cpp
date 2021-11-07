/**
 * @file util.cpp
 * @author midlane.top
 * @brief 工具函数实现
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cstdio>
#include <cstdlib> // std::srand
#include "util.h"

/**
 * @brief 数组随机化，随机范围为0~n-1
 */
void randomize(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n;
    }
}

/**
 * @brief 打印数组，以便于观察排序过程
 */
void trace(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

/**
 * @brief 检查数组是否为升序
 */
bool isAscending(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief 检查数组是否为降序
 */
bool isDescending(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            return false;
        }
    }
    return true;
}