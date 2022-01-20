/**
 * @file main.cpp
 * @author midlane.top
 * @brief 用于修整百度脑图在线导出的freemind格式的脑图文件
 * @details 修改如下：
 *          1. 删除CREATED和MODIFED属性
 *          2. 将每个节点的ID属性修改成全局唯一值
 * @version 0.1
 * @date 2022-01-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_set>

#include <cstdio>
using namespace std;

#define LENGTH 8 // 随机ID长度为8

string gen_random(int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return -1;
    }
    if (strlen(argv[1]) == strlen(argv[2]) && strncmp(argv[1], argv[2], strlen(argv[1])) == 0) {
        printf("input_file and output_file should not be the same.\n");
        return -1;
    }

    ifstream in;
    ofstream out;
    string line;
    unordered_set<string> ids;

    regex exp1("CREATED=\"\\d+\"\\s");  // CREATED="\d+"\s
    regex exp2("MODIFIED=\"\\d+\"\\s"); // MODIFIED="\d+"\s
    regex exp3("(ID=)\"(\\w+)\"");      // (ID=)"(\w+)"

    in.open(argv[1], ios::in);
    if (!in.is_open()) {
        perror("Open input_file failed");
        return -1;
    }
    out.open(argv[2], ios::out);
    if (!out.is_open()) {
        perror("Open output_file failed");
        return -1;
    }

    while (getline(in, line)) {
        auto id = gen_random(LENGTH);
        while (ids.find(id) != ids.end()) {
            id = gen_random(LENGTH);
        }
        ids.insert(id);
        line = regex_replace(line, exp1, "");                 // 删除CREATED="XXXX"
        line = regex_replace(line, exp2, "");                 // 删除MODIFIED="XXXX"
        line = regex_replace(line, exp3, "$1\"" + id + "\""); // 替换ID为当前唯一值
        out << line << endl;
    }

    in.close();
    out.close();

    return 0;
}