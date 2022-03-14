#include "common.h"

vector<vector<int>> combine(int n, int k) {
    if (k == 1) {
        vector<vector<int>> ret;
        for (int i = 1; i <= n; i++)
            ret.push_back({i});
        return ret;
    } else if (k == 2) {
        if (n == 2) {
            return {{1, 2}};
        } else {
            auto ret = combine(n - 1, k);
            for (int i = 1; i < n; i++)
                ret.push_back({i, n});
            return ret;
        }
    } else if (n == k) {
        vector<int> ret;
        for (int i = 1; i <= n; i++)
            ret.push_back({i});
        return vector<vector<int>>(1, ret);
    } else {
        auto ret = combine(n - 1, k - 1);
        for (auto& i : ret)
            i.push_back(n);
        // + c n-1,k
        auto ret_2 = combine(n - 1, k);
        ret.insert(ret.end(), ret_2.begin(), ret_2.end());
        return ret;
    }
}

// 排序以便判断算法得出结果的正确性
bool cmp(const vector<int>& a, const vector<int>& b) {
    int i = 0;
    while (a[i] == b[i])
        i++;
    return a[i] < b[i];
}
void sort(vector<vector<int>>& target) {
    for (auto& i : target) {
        std::sort(i.begin(), i.end());
    }
    std::sort(target.begin(), target.end(), cmp);
}

TEST(solution, combine) {
    vector<vector<int>> expected;
    vector<vector<int>> answer;

    expected = {{2, 4}, {3, 4}, {2, 3}, {1, 2}, {1, 3}, {1, 4}};
    answer = combine(4, 2);
    sort(expected);
    sort(answer);
    EXPECT_EQ(expected, answer);

    expected = {{1}};
    answer = combine(1, 1);
    EXPECT_EQ(expected, answer);

    expected = {{1}, {2}, {3}};
    answer = combine(3, 1);
    EXPECT_EQ(expected, answer);

    expected = {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}};
    answer = combine(4, 3);
    sort(expected);
    sort(answer);
    EXPECT_EQ(expected, answer);

    expected = {{1, 2, 3, 4}};
    answer = combine(4, 4);
    sort(expected);
    sort(answer);
    EXPECT_EQ(expected, answer);
}