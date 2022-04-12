#include "common.h"

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

// bfs
vector<vector<int>> floodFill_bfs(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
    // init
    int oldColor = image[sr][sc];
    if (newColor == oldColor)
        return vector<vector<int>>(image);

    auto& answer = image;
    queue<tuple<int, int>> nodes;
    auto height = image.size(), width = image[0].size();

    answer[sr][sc] = newColor;
    nodes.emplace(sr, sc);
    while (!nodes.empty()) {
        int x, y;
        std::tie(y, x) = nodes.front();
        nodes.pop();

        for (int i = 0; i < 4; i++) {
            int r = y + dy[i], c = x + dx[i];
            if (r >= 0 && r < height && c >= 0 && c < width &&
                answer[r][c] == oldColor) {
                answer[r][c] = newColor;
                nodes.emplace(r, c);
            }
        }
    }

    return answer;
}

// dfs
vector<vector<int>> floodFill_dfs(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
    // init
    int oldColor = image[sr][sc];
    if (newColor == oldColor)
        return vector<vector<int>>(image);

    auto& answer = image;
    stack<tuple<int, int>> nodes;
    auto height = image.size(), width = image[0].size();

    answer[sr][sc] = newColor;
    nodes.emplace(sr, sc);
    while (!nodes.empty()) {
        int x, y;
        std::tie(y, x) = nodes.top();
        nodes.pop();

        for (int i = 0; i < 4; i++) {
            int r = y + dy[i], c = x + dx[i];
            if (r >= 0 && r < height && c >= 0 && c < width &&
                answer[r][c] == oldColor) {
                answer[r][c] = newColor;
                nodes.emplace(r, c);
            }
        }
    }

    return answer;
}

TEST(solution, floodFill) {
    auto solution_func = floodFill_bfs;

    vector<vector<int>> question;
    vector<vector<int>> expected;

    // 1
    question.clear();
    expected.clear();
    question.push_back({1, 1, 1});
    question.push_back({1, 1, 0});
    question.push_back({1, 0, 1});

    expected.push_back({2, 2, 2});
    expected.push_back({2, 2, 0});
    expected.push_back({2, 0, 1});
    EXPECT_EQ(expected, solution_func(question, 1, 1, 2));

    // 2
    question.clear();
    expected.clear();
    question.push_back({0, 0, 0});
    question.push_back({0, 0, 0});

    expected.push_back({2, 2, 2});
    expected.push_back({2, 2, 2});
    EXPECT_EQ(expected, solution_func(question, 0, 0, 2));

    // 3
    question.clear();
    expected.clear();
    question.push_back({0, 0, 0});
    question.push_back({0, 1, 1});
    expected.push_back({0, 0, 0});
    expected.push_back({0, 1, 1});
    EXPECT_EQ(expected, solution_func(question, 1, 1, 1));

    // 4
    question.clear();
    expected.clear();
    question.push_back({0, 0, 0});
    question.push_back({0, 1, 0});
    expected.push_back({2, 2, 2});
    expected.push_back({2, 1, 2});
    EXPECT_EQ(expected, solution_func(question, 0, 0, 2));
}
