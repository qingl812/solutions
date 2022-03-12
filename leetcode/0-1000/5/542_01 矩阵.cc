#include "common.h"

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    // init
    int width = mat[0].size();
    int height = mat.size();
    queue<tuple<int, int>> que;
    vector<vector<int>> ans(height, vector<int>(width, -1));
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (mat[y][x] == 0) {
                ans[y][x] = 0;
                que.emplace(x, y);
            }
        }
    }

    // ans
    while (!que.empty()) {
        int x, y;
        std::tie(x, y) = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < width && ty >= 0 && ty < height &&
                ans[ty][tx] == -1) {
                ans[ty][tx] = ans[y][x] + 1;
                que.emplace(tx, ty);
            }
        }
    }

    return ans;
}

TEST(solution, updateMatrix) {
    vector<vector<int>> question;
    vector<vector<int>> expected;

    question = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    expected = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    EXPECT_EQ(expected, updateMatrix(question));

    question = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    expected = {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}};
    EXPECT_EQ(expected, updateMatrix(question));
}