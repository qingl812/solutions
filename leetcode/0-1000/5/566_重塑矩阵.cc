#include "common.h"

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();
    if (m * n != r * c)
        return mat;

    vector<vector<int>> ans(r, vector<int>(c));
    for (int x = 0; x < m * n; ++x) {
        ans[x / c][x % c] = mat[x / n][x % n];
    }
    return ans;
}

TEST(solution, matrixReshape) {
    vector<vector<int>> question;
    vector<vector<int>> expected;

    question = {{1, 2}, {3, 4}};
    expected = {{1, 2, 3, 4}};
    EXPECT_EQ(expected, matrixReshape(question, 1, 4));

    question = {{1, 2}, {3, 4}};
    expected = {{1, 2}, {3, 4}};
    EXPECT_EQ(expected, matrixReshape(question, 2, 2));

    question = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    expected = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    EXPECT_EQ(expected, matrixReshape(question, 2, 4));

    question = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    expected = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}};
    EXPECT_EQ(expected, matrixReshape(question, 8, 1));
}