/**
 * @file main.cpp
 * @author midlane.top
 * @brief <climits>和<cfloat>常量宏测试
 * @version 0.1
 * @date 2022-02-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main() {
    cout << "SCHAR_MIN:" << SCHAR_MIN << endl;
    cout << "SCHAR_MAX:" << SCHAR_MAX << endl;
    cout << "UCHAR_MAX:" << UCHAR_MAX << endl;
    cout << "CHAR_MIN:" << CHAR_MIN << endl;
    cout << "CHAR_MAX:" << CHAR_MAX << endl;
    cout << "SHORT_MIN:" << SHRT_MIN << endl;
    cout << "SHORT_MAX:" << SHRT_MAX << endl;
    cout << "USHORT_MAX:" << USHRT_MAX << endl;
    cout << "INT_MIN:" << INT_MIN << endl;
    cout << "INT_MAX:" << INT_MAX << endl;
    cout << "UINT_MAX:" << UINT_MAX << endl;
    cout << "LONG_MIN:" << LONG_MIN << endl;
    cout << "LONG_MAX:" << LONG_MAX << endl;
    cout << "ULONG_MAX:" << ULONG_MAX << endl;
    cout << "LLONG_MIN:" << LLONG_MIN << endl;
    cout << "LLONG_MAX:" << LLONG_MAX << endl;
    cout << "ULLONG_MAX:" << ULLONG_MAX << endl;
    cout << "FLT_MIN:" << FLT_MIN << endl;
    cout << "DBL_MIN:" << DBL_MIN << endl;
    cout << "LDBL_MIN:" << LDBL_MIN << endl;
    cout << "FLT_MAX:" << FLT_MAX << endl;
    cout << "DBL_MAX:" << DBL_MAX << endl;
    cout << "LDBL_MAX:" << LDBL_MAX << endl;
    return 0;
}