#pragma
#include <assert.h>
#include <gtest/gtest.h>
#include <stdlib.h>
#include <time.h>

#include "ListNode.hpp"
#include "TreeNode.hpp"

namespace zql {
/***
 * @brief tools
 * @details 一些常用函数
 * @author qingl
 * @date 2022_04_12
 */
class tools {
private:
    // 带有一个 int 参数的函数
    template <typename T>
    using argu_int_fun_t = T (*)(int);

public:
    /***
     * @brief 生成 n 个随机数据，并判断两个函数执行结果是否相等
     * @author qingl
     * @date 2022_04_12
     */
    template <typename T>
    static void rand_int_check(size_t n, int begin, int end,
                               argu_int_fun_t<T> answer,
                               argu_int_fun_t<T> expected) {
        while (n--) {
            int question = random_int(begin, end);
            EXPECT_EQ(expected(question), answer(question));
        }
    }

private:
    /***
     * @brief 初始化函数 init
     * @details 初始化，用于如 rand 函数等
     * @author qingl
     * @date 2022_04_11
     */
    static void init() {
        static bool is_init = false;
        if (is_init == false) {
            srand((unsigned)time(nullptr));
            is_init = true;
        }
    }

    /***
     * @brief 生成 [begin, end] 的随机非负整数
     * @details 包含 begin, end, 需要先设置随机数种子 srand
     * @author qingl
     * @date 2022_04_11
     */
    static int random_positive_int(int begin, int end) {
        assert(begin >= 0 && end >= 0);
        init();
        return rand() % (end - begin + 1) + begin;
    }

    /***
     * @brief 生成 [begin, end] 的随机整数
     * @details 包含 begin, end, 需要先设置随机数种子 srand
     * @author qingl
     * @date 2022_04_11
     */
    static int random_int(int begin, int end) {
        if (begin <= 0 && end <= 0)
            return -1 * random_positive_int(-1 * begin, -1 * end);
        else if (begin >= 0 && end >= 0)
            return random_positive_int(begin, end);

        // 0 生成正整数，1 生成负整数
        if (random_positive_int(0, 1) == 0) {
            return random_positive_int(0, end);
        } else {
            return random_positive_int(begin, -1);
        }
    }
};
} // namespace zql
