/**
 * @file main.cpp
 * @author midlane.top
 * @brief 排序算法，默认按从小到大排序
 * @version 0.1
 * @date 2021-11-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <algorithm> // std::random_shuffle
#include <cassert>   // assert
#include <cstdio>
#include <cstdlib> // std::srand
#include <cstring> // memcpy
#include <ctime>   // time
using namespace std;

bool silent = false; // trace打印使能


#define TEST(XX, SIZE)                            \
    do {                                          \
        printf("%s start\n", #XX);                \
        int a[SIZE], b[SIZE];                     \
        randomize(a, SIZE);                       \
        bubbleSort(a, SIZE);                      \
        memcpy(b, a, sizeof(a));                  \
        for (int i = 0; i < 20000; i++) {         \
            random_shuffle(a, a + SIZE);          \
            XX(a, SIZE);                          \
            assert(memcmp(a, b, sizeof(a)) == 0); \
        }                                         \
        printf("%s end\n", #XX);                  \
    } while (0)

#define TEST2(XX, SIZE)                           \
    do {                                          \
        printf("%s start\n", #XX);                \
        int a[SIZE], b[SIZE];                     \
        randomize(a, SIZE);                       \
        bubbleSort(a, SIZE);                      \
        memcpy(b, a, sizeof(a));                  \
        for (int i = 0; i < 20000; i++) {         \
            random_shuffle(a, a + SIZE);          \
            XX(a, SIZE, 0, SIZE - 1);             \
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
    assert(check(a, 10));

    printf("insertSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    insertSort(a, 10);
    assert(check(a, 10));

    printf("selectSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    selectSort(a, 10);
    assert(check(a, 10));

    printf("shellSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    shellSort(a, 10);
    assert(check(a, 10));

    printf("mergeSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    mergeSort(a, 10, 0, 9);
    trace(a, 10);
    assert(check(a, 10));

    printf("quickSort:\n");
    random_shuffle(a, a + 10);
    trace(a, 10);
    quickSort(a, 10, 0, 9);
    trace(a, 10);
    assert(check(a, 10));
}

int main() {
    srand(time(0));
    
    simple_test();
    
    silent = true;
    TEST(simpleSort, 100);
    TEST(bubbleSort, 100);
    TEST(insertSort, 100);
    TEST(selectSort, 100);
    TEST2(mergeSort, 100);
    TEST2(quickSort, 100);
    return 0;
}