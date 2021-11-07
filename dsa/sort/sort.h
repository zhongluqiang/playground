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
 * 
 * @param v 
 */
void setTraceSortEnable(bool v);

void simpleSort(int a[], int n);
void bubbleSort(int a[], int n);
void selectSort(int a[], int n);
void insertSort(int a[], int n);
void shellSort(int a[], int n);
void mergeSort(int a[], int n);
void quickSort(int a[], int n);
void quickSort3(int a[], int n);
#endif