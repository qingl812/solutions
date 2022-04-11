#pragma
#include "detail.hpp"

#include <gtest/gtest.h>

/***
 * @brief tools
 * @details 一些常用函数
 * @author qingl
 * @date 2022_04_11
 */
namespace zql {
/***
 * @brief 生成 n 个随机数据，并判断两个函数执行结果是否相等
 * @author qingl
 * @date 2022_04_11
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
} // namespace zql
