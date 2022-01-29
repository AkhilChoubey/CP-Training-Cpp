

// Method 1 -- Using insertToBottom Function

class MyQueue
{
public:
    stack<int> S;

    MyQueue()
    {
    }

    void insertAtButtom(stack<int> &S, int x)
    {
        if (S.empty())
        {
            S.push(x);
            return;
        }

        int temp = S.top();
        S.pop();
        insertAtButtom(S, x);
        S.push(temp);
    }

    void push(int x)
    {
        insertAtButtom(S, x);
    }

    int pop()
    {
        int top = S.top();
        S.pop();
        return top;
    }

    int peek()
    {
        return S.top();
    }

    bool empty()
    {
        if (S.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//Method 2 -- Using 2 Stack method

class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int x = peek();
        s2.pop();
        return x;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};