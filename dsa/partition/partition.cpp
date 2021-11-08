/**
 * @file partition.cpp
 * @author midlane.top
 * @brief 分割函数实现
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "partition.h"
#include "util/util.h"

#include <utility>
using std::swap;

/**
 * @brief 以最左边的数作为分界点进行数组分割，返回分界点的下标
 */
int partition_l(int a[], int left, int right) {
    int pivot = a[left];
    while(left < right) {
        while(left < right && a[right] > pivot) {
            right--;
        }
        if(left < right) {
            a[left] = a[right];
        }
        while(left < right && a[left] <= pivot) {
            left++;
        }
        if(left < right) {
            a[right] = a[left];
        }
    }
    a[left] = pivot; // or a[right] = pivot;
    return left;
}

/**
 * @brief 以中间的数作为分界点进行数组分割，返回分界点的下标
 */
int partition_m(int a[], int left, int right) {
    int pivot = a[(left+right) >> 1];
    // TODO
    (void)pivot;
    return 0;
}

/**
 * @brief 以最右边的数作为分界点进行数组分割，返回分界点的下标
 */
int partition_r(int a[], int left, int right) {
    int pivot = a[right];
    int i = left - 1;
    for(int j = left; j <= right - 1; j++) {
        if(a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[right]);
    return i+1;
}

/**
 * @brief 形式一，以数组第一个元素作为基准值将数组分割成"左边 基准值 右边"的形式，满足"左边<=基准值<=右边"
 * @return 分割后的基准值下标
 */
int partition1(int a[], int left, int right) {
    int pivot = a[left]; // 以最左边的元素作为基准值
    while (left < right) {
        while (left < right && a[right] >= pivot) { // 比较一
            right--;
        }
        if (left < right) {
            a[left] = a[right];
        }
        while (left < right && a[left] <= pivot) {  // 比较二
            left++;
        }
        if (left < right) {
            a[right] = a[left];
        }
    }
    a[left] = pivot; // 或 a[right] = pivot;
    return left;
}

/**
 * @brief 形式二，以数组第一个元素作为基准值将数组分割成"左边 右边"的形式，满足"左边<=右边"
 * @return 分割后左部分的结束位置
 * @note 这个算法可以以任何元素作为pivot，结果都是正确的
 */
int partition2(int a[], int left, int right) {
    int pivot = a[left];
    int i = left-1, j = right+1;
    while(i < j) {
        while(a[++i] < pivot); // 比较一
        while(a[--j] > pivot); // 比较二
        if(i < j) {
            swap(a[i], a[j]);
        }
    }
    return j;
}