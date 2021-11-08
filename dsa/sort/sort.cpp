
#include <utility>
#include <vector>
#include <cstdio>
#include "util/util.h"
#include "partition/partition.h"

using std::swap;
using std::vector;

static bool enable_trace = false;

/**
 * @brief 开关排序相关的调试打印
 */
void setTraceSortEnable(bool v) {
    enable_trace = v;
}

/**
 * @brief 简单排序
 * @details 两两比较所有的数，如果反序则交换位置
 */
void simpleSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
}

/**
 * @brief 冒泡排序
 * @details 两两比较相邻的数，如果反序则交换位置
 * @note 1. 如果一轮比较下来没有交换任何数，则表明数组已经排好序，直接返回即可
 *       2. 未排序部分在前，已排序部分在后
 */
void bubbleSort(int a[], int n) {
    bool flag;
    for (int i = n - 1; i > 0; i--) { // i表示已排序部分的起始位置，初始时指向最后一个元素
        flag = true;
        for (int j = 0; j <= i - 1; j++) { // j从0开始冒泡到未排序部分的结束位置
            if (a[j] > a[j + 1]) {
                flag = false;
                swap(a[j], a[j + 1]);
            }
        }
        if(enable_trace){
            trace(a, n);
        }
        if (flag) { // 未发生数据交换，则表示数组已排序好
            return;
        }
    }
}

/**
 * @brief 选择排序
 * @details 找到未排序部分最小元素的位置，然后与未排序部分的第一个数交换位置
 * @note 1. 每轮遍历只交换一次
 */
void selectSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) { // i指向未排序部分的起始位置
        int index = i;
        for (int j = i + 1; j < n; j++) { // j从i的下一个元素开始寻找最小元素
            if (a[j] < a[index]) {
                index = j;
            }
        }
        if (index != i) {
            swap(a[i], a[index]);
        }
        if(enable_trace){
            trace(a, n);
        }
    }
}

/**
 * @brief 插入排序
 * @details 每次将未排序的第一个数与已排好序的数进行比较，如果反序则将已排好序的数往后移一位，继续比较，直到将数字插入到合适的位置
 * @note 1. 未排序部分在后，已排序部分在前
 */
void insertSort(int a[], int n) {
    for (int i = 1; i < n; i++) { // i指向未排序部分的起始位置
        int tmp = a[i];
        int j   = i - 1;
        while (j >= 0 && a[j] > tmp) { // 将i前面比i大的数向右移一位，直到遇到比i小的数，或是到达数组起始位置
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
        if(enable_trace){
            trace(a, n);
        }
    }
}

/**
 * @brief 以g为间隔进行插入排序
 */
void insertSort(int a[], int n, int g) {
    for (int i = g; i < n; i++) {
        int tmp = a[i];
        int j   = i - g;
        while (j >= 0 && a[j] > tmp) {
            a[j + g] = a[j];
            j -= g;
        }
        a[j + g] = tmp;
    }
}

/**
 * @brief 希尔排序
 */
void shellSort(int a[], int n) {
    vector<int> G;
    for (int h = 1;;) {
        if (h > n) {
            break;
        }
        G.push_back(h);
        h = 3 * h + 1; // 以{1, 4, 13, 40, 121...}为间隔进行插入排序
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        insertSort(a, n, G[i]);
        if(enable_trace){
            trace(a, n);
        }
    }
}

/**
 * @brief 合并有序数组a[left...mid]和a[mid+1, right]
 */
static void merge(int a[], int left, int mid, int right) {
    static vector<int> v;
    v.clear();

    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            v.push_back(a[i]);
            i++;
        } else {
            v.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid) {
        v.push_back(a[i]);
        i++;
    }
    while (j <= right) {
        v.push_back(a[j]);
        j++;
    }

    for (int i = left, k = 0; i <= right; i++) {
        a[i] = v[k++];
    }
}

/**
 * @brief 归并排序，区间形式
 */
void mergeSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) >> 1;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

/**
 * @brief 归并排序
 */
void mergeSort(int a[], int n) {
    mergeSort(a, 0, n - 1);
}

/**
 * @brief 快速排序，区间形式
 */
void quickSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = partition1(a, left, right);
    if(enable_trace) {
        printf("mid=%d, left=%d, right=%d\n", mid, left, right);
        trace(a, right-left+1);
    }
    quickSort(a, left, mid - 1);
    quickSort(a, mid + 1, right);
}

/**
 * @brief 快速排序
 */
void quickSort(int a[], int n) {
    quickSort(a, 0, n - 1);
}

/**
 * @brief 快速排序，区间形式，形式二分割算法
 */
void quickSort2(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = partition2(a, left, right);
    if(enable_trace) {
        printf("mid=%d, left=%d, right=%d\n", mid, left, right);
        trace(a, right-left+1);
    }
    quickSort2(a, left, mid);
    quickSort2(a, mid+1, right);
}

/**
 * @brief 快速排序，形式二分割算法
 */
void quickSort2(int a[], int n) {
    quickSort2(a, 0, n - 1);
}

/**
 * @brief 快速排序，简化版，区间形式
 */
void quickSort3(int a[], int left, int right) {
    if(left >= right) {
        return;
    }
    int pivot = a[left];
    int i = left - 1, j = right + 1;
    while(i < j) {
        while(a[++i] < pivot);
        while(a[--j] > pivot);
        if(i < j) {
            swap(a[i], a[j]);
        }
    }
    quickSort3(a, left, j);
    quickSort3(a, j + 1, right);
}

/**
 * @brief 快速排序，简化版
 */
void quickSort3(int a[], int n) {
    quickSort3(a, 0, n - 1);
}