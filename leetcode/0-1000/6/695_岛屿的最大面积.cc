#include "common.h"

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

// 广度优先搜索每个节点，把已访问的节点置为 0
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int width = static_cast<int>(grid[0].size()),
        height = static_cast<int>(grid.size());
    queue<tuple<int, int>> que;
    int ans = 0;

    int x = 0, y = 0;
    while (y != height) {
        int max = 0;
        if (grid[y][x] != 0) {
            // bfs
            max++;
            grid[y][x] = 0;
            que.emplace(y, x);
            while (!que.empty()) {
                int x_1, y_1;
                std::tie(y_1, x_1) = que.front();
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int x_2 = x_1 + dx[i];
                    int y_2 = y_1 + dy[i];
                    if (x_2 >= 0 && x_2 < width && y_2 >= 0 && y_2 < height &&
                        grid[y_2][x_2] != 0) {
                        grid[y_2][x_2] = 0;
                        max++;
                        que.emplace(y_2, x_2);
                    }
                }
            }
        }

        ans = std::max(max, ans);

        // x++ or y++
        x++;
        if (x == width) {
            x = 0;
            y++;
        }
    }

    return ans;
}

TEST(solution, maxAreaOfIsland) {
    vector<vector<int>> question;
    int expected;

    question = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    };
    expected = 6;
    EXPECT_EQ(expected, maxAreaOfIsland(question));

    question = {{0, 0, 0, 0, 0, 0, 0, 0}};
    expected = 0;
    EXPECT_EQ(expected, maxAreaOfIsland(question));
}