#include <bits/stdc++.h>
using namespace std;

class stack
{
public:
    vector<int> arr;
    stack()
    {
        arr.clear();
    }

    void push(int val)
    {
        arr.push_back(val);
    }

    void pop()
    {
        if (arr.size() == 0)
            return;
        arr.pop_back();
    }

    int top()
    {
        return arr.back();
    }

    bool empty()
    {
        if (arr.size() == 0)
        {
            return true;
        }
        return false;
    }
};