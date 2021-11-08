/**
 * @file sort.h
 * @author midlane.top
 * @brief 排序函数
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __SORT_H__
#define __SORT_H__

/**
 * @brief 开关排序步骤的打印
 */
void setTraceSortEnable(bool v);

/**
 * @brief 简单排序
 */
void simpleSort(int a[], int n);

/**
 * @brief 冒泡排序
 */
void bubbleSort(int a[], int n);

/**
 * @brief 选择排序
 */
void selectSort(int a[], int n);

/**
 * @brief 插入排序
 */
void insertSort(int a[], int n);

/**
 * @brief 希尔排序
 */
void shellSort(int a[], int n);

/**
 * @brief 归并排序
 */
void mergeSort(int a[], int n);

/**
 * @brief 快速排序，分割成"左边<=基准值<=右边"的形式
 */
void quickSort(int a[], int n);

/**
 * @brief 快速排序，分割成"左边<=右边"的形式
 */
void quickSort2(int a[], int n);

/**
 * @brief 快速排序，quickSort2简化版
 */
void quickSort3(int a[], int n);
#endif