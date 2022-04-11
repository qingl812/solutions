#pragma
#include <gtest/gtest.h>
#include <stdlib.h>

/***
 * @brief tools detail
 * @details tools 实现所用到的辅助函数等
 * @author qingl
 * @date 2022_04_09
 */
namespace tools {
namespace detail {
/***
 * @brief 生成 [begin, end] 的随机非负整数
 * @details 包含 begin, end, 需要先设置随机数种子 srand
 * @author qingl
 * @date 2022_04_09
 */
int random_positive_int(size_t begin, size_t end) {
    assert(begin >= 0 && end >= 0);
    return rand() % (end - begin + 1) + begin;
}

/***
 * @brief 生成 [begin, end] 的随机整数
 * @details 包含 begin, end, 需要先设置随机数种子 srand
 * @author qingl
 * @date 2022_04_09
 */
int random_int(int begin, int end) {
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

// 带有一个 int 参数的函数
template <typename T>
using argu_int_fun_t = T (*)(int);
} // namespace detail
} // namespace tools

/***
 * @brief tools
 * @details 一些常用函数
 * @author qingl
 * @date 2022_04_09
 */
namespace tools {
/***
 * @brief 生成 n 个随机数据，并判断两个函数执行结果是否相等
 * @author qingl
 * @date 2022_04_09
 */
template <typename T>
void rand_int_check(size_t n, int begin, int end,
                    detail::argu_int_fun_t<T> answer,
                    detail::argu_int_fun_t<T> expected) {
    static bool is_init = false;
    if (is_init == false)
        srand((unsigned)time(nullptr));

    while (n--) {
        int question = detail::random_int(begin, end);
        EXPECT_EQ(expected(question), answer(question));
    }
}
} // namespace tools