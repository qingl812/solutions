#include "common.h"

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> m;
    int min = INT_MAX;
    vector<string> ans;
    for (int i = 0; i < list1.size(); i++) {
        m.emplace(list1[i], i);
    }

    for (int i = 0; i < list2.size(); i++) {
        auto t = m.find(list2[i]);
        if (t != m.end()) {
            int x = t->second + i;
            if (x < min) {
                min = x;
                ans.clear();
                ans.push_back(t->first);
            } else if (x == min) {
                ans.push_back(t->first);
            }
        }
    }
    return ans;
}

TEST(solution, findRestaurant) {
    vector<string> question_a, question_b;
    vector<string> expected, answer;

    question_a = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    question_b = {"Piatti", "The Grill at Torrey Pines",
                  "Hungry Hunter Steakhouse", "Shogun"};
    expected = {"Shogun"};
    answer = findRestaurant(question_a, question_b);
    EXPECT_EQ(expected, answer);

    question_a = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    question_b = {"KFC", "Shogun", "Burger King"};
    expected = {"Shogun"};
    answer = findRestaurant(question_a, question_b);
    EXPECT_EQ(expected, answer);

    question_a = {"Shogun", "KFC", "Burger King", "Tapioca Express"};
    question_b = {"KFC", "Shogun", "Burger King"};
    expected = {"Shogun", "KFC"};
    answer = findRestaurant(question_a, question_b);
    sort(answer.begin(), answer.end());
    sort(expected.begin(), expected.end());
    EXPECT_EQ(expected, answer);

    question_a = {"Shogun"};
    question_b = {"Shogun"};
    expected = {"Shogun"};
    answer = findRestaurant(question_a, question_b);
    EXPECT_EQ(expected, answer);
}