/**
 * @file test_sort.cpp
 * @author midlane.top
 * @brief 测试排序算法
 * @version 0.1
 * @date 2021-11-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "sort/sort.h"
#include "util/util.h"
#include <algorithm> // std::random_shuffle
#include <cassert>   // assert
#include <cstdio>
#include <cstdlib>    // std::srand
#include <cstring>    // memcpy
#include <ctime>      // time
#include <sys/time.h> // gettimeofday

using std::random_shuffle;

/**
 * @brief 使用大小为SIZE的随机数组测试排序算法XX
 * @details 设置a[] b[]两个大小一致的数组，先对a[]进行简单排序，将排序结果存储在b[]中，
 *          然后重复打乱a[]并执行XX排序，再与b[]进行比较，看结果是否一致
 */
#define TEST(XX, SIZE)                            \
    do {                                          \
        printf("%s start\n", #XX);                \
        int a[SIZE], b[SIZE];                     \
        randomize(a, SIZE);                       \
        simpleSort(a, SIZE);                      \
        memcpy(b, a, sizeof(a));                  \
        for (int i = 0; i < 20000; i++) {         \
            random_shuffle(a, a + SIZE);          \
            XX(a, SIZE);                          \
            assert(memcmp(a, b, sizeof(a)) == 0); \
        }                                         \
        printf("%s end\n", #XX);                  \
    } while (0)

void simple_test() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("bubbleSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    bubbleSort(a, 10);
    assert(isAscending(a, 10));

    printf("insertSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    insertSort(a, 10);
    assert(isAscending(a, 10));

    printf("selectSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    selectSort(a, 10);
    assert(isAscending(a, 10));

    printf("shellSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    shellSort(a, 10);
    assert(isAscending(a, 10));

    printf("mergeSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    mergeSort(a, 10);
    trace(a, 10);
    assert(isAscending(a, 10));

    printf("quickSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    quickSort(a, 10);
    trace(a, 10);
    assert(isAscending(a, 10));

    printf("quickSort2:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    quickSort2(a, 10);
    trace(a, 10);
    assert(isAscending(a, 10));
}

int main() {
    srand(time(0));

    setTraceSortEnable(true);
    simple_test();

    setTraceSortEnable(false);
    TEST(bubbleSort, 100);
    TEST(insertSort, 100);
    TEST(selectSort, 100);
    TEST(mergeSort, 100);
    TEST(quickSort, 100);
    TEST(quickSort2, 100);
    TEST(quickSort3, 100);
    return 0;
}