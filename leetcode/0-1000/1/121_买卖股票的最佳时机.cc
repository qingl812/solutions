#include "common.h"

int maxProfit(vector<int>& prices) {
    int minprice = INT_MAX, maxprofit = 0;
    for (auto i : prices) {
        maxprofit = max(maxprofit, i - minprice);
        minprice = min(i, minprice);
    }
    return maxprofit;
}

TEST(solution, maxProfit) {
    vector<int> question;

    question = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(5, maxProfit(question));

    question = {7, 6, 4, 3, 1};
    EXPECT_EQ(0, maxProfit(question));
}