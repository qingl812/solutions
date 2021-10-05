#ifndef _PUBLIC_H__
#define _PUBLIC_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 单元测试
#define EXPECT_EQ_BASE(equality, expect, actual, format)                       \
    do {                                                                       \
        test_count++;                                                          \
        if (equality)                                                          \
            test_pass++;                                                       \
        else {                                                                 \
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n",  \
                    __FILE__, __LINE__, expect, actual);                       \
            main_ret = 1;                                                      \
        }                                                                      \
    } while (0)

#define EXPECT_EQ_INT(expect, actual)                                          \
    EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

#define EXPECT_EQ_STRING(expect, actual)                                       \
    EXPECT_EQ_BASE(strcmp((expect), (actual)) == 0, expect, actual, "%s")

int test_count = 0;
int test_pass = 0;
int main_ret = 0;

#endif // ! _PUBLIC_H__