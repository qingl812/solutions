#include "common.h"

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int orangesRotting(vector<vector<int>>& grid) {
    auto width = grid.size(), height = grid[0].size();
    queue<tuple<int, int>> que;
    que.emplace(-1, -1);
    int ans = 0;
    int count = 0; // 新鲜橘子的数量
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            auto& t = grid[x][y];
            if (t == 2) {
                que.emplace(x, y);
            } else if (t == 1) {
                count++;
            }
        }
    }

    while (count != 0 && !que.empty()) {
        int x, y;
        std::tie(x, y) = que.front();
        que.pop();

        if (x == -1 && !que.empty()) {
            que.emplace(-1, -1);
            ans++;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && tx < width && ty >= 0 && ty < height) {
                auto& t = grid[tx][ty];
                if (t == 1) {
                    t = 2;
                    count--;
                    que.emplace(tx, ty);
                }
            }
        }
    }

    return count == 0 ? ans : -1;
}

TEST(solution, orangesRotting) {
    vector<vector<int>> question;
    int expected;

    question = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    expected = 4;
    EXPECT_EQ(expected, orangesRotting(question));

    question = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    expected = -1;
    EXPECT_EQ(expected, orangesRotting(question));

    question = {{0, 2}};
    expected = 0;
    EXPECT_EQ(expected, orangesRotting(question));
}