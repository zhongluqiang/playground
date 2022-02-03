/**
 * @file main.cpp
 * @author midlane.top
 * @brief zigzap算法实现与测试
 * @version 0.1
 * @date 2022-02-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

/**
 * @brief 32位zigzag编码 
 */
uint32_t EncodeZigzag32(const int32_t &v) {
    return (v << 1) ^ (v >> 31);
}

/**
 * @brief 64位zigzag编码 
 */
uint32_t EncodeZigzag64(const int64_t &v) {
    return (v << 1) ^ (v >> 63);
}

/**
 * @brief 32位zigzag解码 
 */
int32_t DecodeZigzag32(const uint32_t &v) {
    return (v >> 1) ^ -(v & 1);
}

/**
 * @brief 64位zigzag解码 
 */
int64_t DecodeZigzag64(const uint64_t &v) {
    return (v >> 1) ^ -(v & 1);
}

/**
 * @brief 32位zigzag编码压缩
 * 
 * @param value zigzag编码后的数字
 * @param buf 输出缓冲区
 * @return int 返回zigzag压缩后的字节数，范围1~5字节
 */
int WriteZigzag32(uint32_t value, char *buf) {
    uint8_t i = 0;
    while(value >= 0x80) {
        buf[i++] = (value & 0x7F) | 0x80;
        value >>= 7;
    }
    buf[i++] = value;
    return i;
}

/**
 * @brief 解码压缩后的32位zigzag数字
 * 
 * @param buf 存储压缩后的数字
 * @param size 长度
 * @return uint32_t 返回解压后的zigzap数字 
 */
uint32_t ReadZigzag32(const char *buf, int size) {
    uint32_t result = 0;
    int offset = 0;
    for(int i = 0; i < size; i++) {
        uint8_t cur = buf[i];
        if(cur & 0x80) {
            result |= ((uint32_t)(cur & 0x7f)) << offset;
        } else {
            result |= ((uint32_t)cur) << offset;
            break;
        }
        offset += 7;
    }

    return result;
}

/**
 * @brief 64位zigzag编码压缩
 * 
 * @param value zigzag编码后的数字
 * @param buf 输出缓冲区
 * @return int 返回zigzag压缩后的字节数，范围1~10字节
 */
int WriteZigzag64(uint64_t value, char *buf) {
    uint8_t i = 0;
    while(value >= 0x80) {
        buf[i++] = (value & 0x7F) | 0x80;
        value >>= 7;
    }
    buf[i++] = value;
    return i;
}

/**
 * @brief 解码压缩后的64位zigzag数字
 * 
 * @param buf 存储压缩后的数字
 * @param size 长度
 * @return uint64_t 返回解压后的zigzap数字 
 */
uint64_t ReadZigzag64(const char *buf, int size) {
    uint64_t result = 0;
    int offset = 0;
    for(int i = 0; i < size; i++) {
        uint8_t cur = buf[i];
        if(cur & 0x80) {
            result |= ((uint64_t)(cur & 0x7f)) << offset;
        } else {
            result |= ((uint64_t)cur) << offset;
            break;
        }
        offset += 7;
    }

    return result;
}

bool testZigzag32(int32_t value) {
    char tmp[5] = {0}; // 32位zigzag压缩之后最多占用5字节， 32 / 7 向上取整等于5
    int len = WriteZigzag32(EncodeZigzag32(value), tmp);
    int32_t v = DecodeZigzag32(ReadZigzag32(tmp, len));
    return v == value;
}

bool testZigzag64(int64_t value) {
    char tmp[10] = {0}; // 64位zigzag之后最多占用10字节，64 / 7 向上取整等于10
    int len = WriteZigzag64(EncodeZigzag64(value), tmp);
    int64_t v = DecodeZigzag64(ReadZigzag64(tmp, len));
    return v == value;
}


int main() {
    srand(time(nullptr));

    // 32位zigzag编解码及解压缩测试
    for(int i = 0; i < 1000000; i++) {
        int32_t num = rand();
        if(i % 2 == 0) num = -num;
        if(!testZigzag32(num)) {
            cout << "test fail, num = " << num << endl;
            return -1;
        }
    }

    // 64位zigzag编解码及解压缩测试
    for(int i = 0; i < 1000000; i++) {
        int64_t num = rand() * rand() * rand() % LLONG_MAX;
        if(i % 2 == 0) num = -num;
        if(!testZigzag64(num)) {
            cout << "test fail, num = " << num << endl;
            return -1;
        }
    }

    cout << "test success" << endl;

    return 0;
}