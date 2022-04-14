#include "common.h"

map<char, char> bracket_map = {{')', '('}, {'}', '{'}, {']', '['}};

bool isValid(string s) {
    stack<char> brackets;
    auto i = s.begin();
    brackets.push(*i);
    for (i++; i != s.end(); i++) {
        if (bracket_map.count(*i) != 0) {
            if (!brackets.empty() && bracket_map[*i] == brackets.top())
                brackets.pop();
            else
                return false;
        } else
            brackets.push(*i);
    }
    return brackets.empty();
}

TEST(solution, isValid) {
    EXPECT_EQ(true, isValid("()"));
    EXPECT_EQ(true, isValid("()[]{}"));
    EXPECT_EQ(false, isValid("(]"));
    EXPECT_EQ(false, isValid("([)]"));
    EXPECT_EQ(true, isValid("{[]}"));
    EXPECT_EQ(false, isValid("(){}}{"));
}
