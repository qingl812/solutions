#include <assert.h>
#include <stdlib.h>
#include <time.h>

/***
 * @brief tools detail
 * @details tools 实现所用到的辅助函数等
 * @author qingl
 * @date 2022_04_11
 */
namespace zql {
namespace detail {
/***
 * @brief 初始化函数 init
 * @details 初始化，用于如 rand 函数等
 * @author qingl
 * @date 2022_04_11
 */
void init() {
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
int random_positive_int(int begin, int end) {
    assert(begin >= 0 && end >= 0);
    return rand() % (end - begin + 1) + begin;
}

/***
 * @brief 生成 [begin, end] 的随机整数
 * @details 包含 begin, end, 需要先设置随机数种子 srand
 * @author qingl
 * @date 2022_04_11
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

/***
 * @brief 带有一个 int 参数的函数
 * @author qingl
 * @date 2022_04_11
 */
template <typename T>
using argu_int_fun_t = T (*)(int);
} // namespace detail
} // namespace zql