/**
 * @file partition.h
 * @author midlane.top
 * @brief 分割函数
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __PARTITION_H__
#define __PARTITION_H__

/**
 * @brief 以最左边的数作为分界点进行数组分割，返回分界点的下标
 */
int partition_l(int a[], int left, int right);

/**
 * @brief 以中间的数作为分界点进行数组分割，返回分界点的下标
 */
int partition_m(int a[], int left, int right);

/**
 * @brief 以最右边的数作为分界点进行数组分割，返回分界点的下标
 */
int partition_r(int a[], int left, int right);

/**
 * @brief 形式一，左边<=基准值<=右边，返回基准值下标
 */
int partition1(int a[], int left, int right);

/**
 * @brief 形式二，左边<=右边，返回左边的结束位置
 */
int partition2(int a[], int left, int right);

#endif