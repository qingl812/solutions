#include <iostream>
#include <string>

using namespace std;

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
