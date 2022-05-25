#include "common.h"

struct Trie {
    unordered_map<char, Trie*> child;
    priority_queue<string> words;
};

void addWord(Trie* root, const string& word) {
    Trie* cur = root;
    for (const char& ch : word) {
        if (!cur->child.count(ch)) {
            cur->child[ch] = new Trie();
        }
        cur = cur->child[ch];
        cur->words.push(word);
        if (cur->words.size() > 3) {
            cur->words.pop();
        }
    }
}

vector<vector<string>> suggestedProducts2(vector<string>& products,
                                          string searchWord) {
    Trie* root = new Trie();
    for (const string& word : products) {
        addWord(root, word);
    }

    vector<vector<string>> ans;
    Trie* cur = root;
    bool flag = false;
    for (const char& ch : searchWord) {
        if (flag || !cur->child.count(ch)) {
            ans.emplace_back();
            flag = true;
        } else {
            cur = cur->child[ch];
            vector<string> selects;
            while (!cur->words.empty()) {
                selects.push_back(cur->words.top());
                cur->words.pop();
            }
            reverse(selects.begin(), selects.end());
            ans.push_back(move(selects));
        }
    }

    return ans;
}

vector<vector<string>> suggestedProducts(vector<string>& products,
                                         string searchWord) {
    sort(products.begin(), products.end());
    string query;
    auto left = products.begin();
    vector<vector<string>> ans;
    for (char ch : searchWord) {
        query += ch;
        auto it = lower_bound(left, products.end(), query);
        auto cur = it;
        vector<string> selects;
        for (int i = 0; i < 3; ++i) {
            if (cur < products.end() && cur->find(query) == 0) {
                selects.push_back(*cur);
                cur++;
            }
        }
        ans.push_back(move(selects));
        left = it;
    }
    return ans;
}

TEST(solution, suggestedProducts) {
    vector<string> question;
    vector<vector<string>> expected, answer;

    question = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    expected = {{"mobile", "moneypot", "monitor"},
                {"mobile", "moneypot", "monitor"},
                {"mouse", "mousepad"},
                {"mouse", "mousepad"},
                {"mouse", "mousepad"}};
    answer = suggestedProducts(question, "mouse");
    EXPECT_EQ(expected, answer);

    question = {"havana"};
    expected = {{
                    "havana",
                },
                {
                    "havana",
                },
                {
                    "havana",
                },
                {
                    "havana",
                },
                {
                    "havana",
                },
                {
                    "havana",
                }};
    answer = suggestedProducts(question, "havana");
    EXPECT_EQ(expected, answer);

    question = {"bags", "baggage", "banner", "box", "cloths"};
    expected = {
        {
            "baggage",
            "bags",
            "banner",
        },
        {
            "baggage",
            "bags",
            "banner",
        },
        {
            "baggage",
            "bags",
        },
        {
            "bags",
        },
    };
    answer = suggestedProducts(question, "bags");
    EXPECT_EQ(expected, answer);

    question = {"havana"};
    expected = {{}, {}, {}, {}, {}, {}, {}};
    answer = suggestedProducts(question, "tatiana");
    EXPECT_EQ(expected, answer);
}
