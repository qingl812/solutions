#include "common.h"

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> zero_row(m, false), zero_col(n, false);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                zero_row[i] = true;
                zero_col[j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (zero_row[i]) {
            matrix[i] = vector<int>(n, 0);
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (zero_col[j])
                matrix[i][j] = 0;
        }
    }
}

TEST(solution, setZeroes) {
    vector<vector<int>> question;
    vector<vector<int>> expected;

    question = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    expected = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    setZeroes(question);
    EXPECT_EQ(expected, question);

    question = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    expected = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    setZeroes(question);
    EXPECT_EQ(expected, question);
}