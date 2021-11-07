/**
 * @file util.h
 * @author midlane.top
 * @brief 工具函数
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __UTIL_H__
#define __UTIL_H__

#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))

/**
 * @brief 数组随机化，随机范围为0~n-1
 */
void randomize(int a[], int n);

/**
 * @brief 打印数组，以便于观察排序过程
 */
void trace(int a[], int n);

/**
 * @brief 检查数组是否为升序
 */
bool isAscending(int a[], int n);

/**
 * @brief 检查数组是否为降序
 */
bool isDescending(int a[], int n);

#endif