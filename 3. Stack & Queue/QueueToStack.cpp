#include <bits/stdc++.h>
using namespace std;

// Logic -- we are making push operation costlier , for push operation - firstly we will push the new element in q2
// then we will push all elements of q1 in q2 (at the same time we will pop from q1). then we will swap q1 and q2.
// for top - we will return q1.front() , for pop - we will pop from q1 and return q1.front().
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty)
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int top = q1.front();
        q1.top();
        return top;
    }
    int top()
    {
        return q1.top();
    }
    bool empty()
    {
        return q1.empty();
    }
};
