#include "common.h"

class MyQueue {
    stack<int> m_stack_pop;
    stack<int> m_stack_push;

public:
    MyQueue() {}

    void push(int x) { m_stack_push.push(x); }

    int pop() {
        auto ret = peek();
        m_stack_pop.pop();
        return ret;
    }

    int peek() {
        if (m_stack_pop.empty()) {
            while (!m_stack_push.empty()) {
                m_stack_pop.push(m_stack_push.top());
                m_stack_push.pop();
            }
        }
        return m_stack_pop.top();
    }

    bool empty() { return m_stack_pop.empty() && m_stack_push.empty(); }
};

TEST(solution, MyQueue) {
    {
        MyQueue myqueue;
        myqueue.push(1);
        myqueue.push(2);
        EXPECT_EQ(1, myqueue.peek());
        EXPECT_EQ(1, myqueue.pop());
        EXPECT_FALSE(myqueue.empty());
    }
}