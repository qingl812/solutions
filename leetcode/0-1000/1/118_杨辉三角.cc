#include "common.h"

vector<int> generate_next_line(const vector<int>& pre_line) {
    auto n = pre_line.size();
    auto ans = vector<int>(n + 1);
    ans[0] = 1;
    ans[n] = 1;
    for (int j = 1; j < n; j++) {
        ans[j] = pre_line[j] + pre_line[j - 1];
    }
    return ans;
}

vector<vector<int>> generate(int numRows) {
    auto ans = vector<vector<int>>(1, {1});
    if (numRows == 1)
        return ans;

    ans.push_back({1, 1});
    if (numRows == 2)
        return ans;

    for (int i = 1; i < numRows - 1; i++) {
        ans.push_back(generate_next_line(ans[i]));
    }
    return ans;
}

TEST(solution, generate) {
    vector<vector<int>> expected;

    expected = {{1}};
    EXPECT_EQ(expected, generate(1));

    expected = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    EXPECT_EQ(expected, generate(5));
}