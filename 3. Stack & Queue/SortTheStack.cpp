#include <bits/stdc++.h>
using namespace std;

void insertAtRightPosition(stack<int> &S, int x)
{
    if (S.empty())
    {
        S.push(x);
        return;
    }
    else if (S.top() < x)
    {
        int temp = S.top();
        S.pop();
        insertAtRightPosition(S, temp);
        S.push(temp);
    }
    else
    {
        S.push(x);
        return;
    }
}

void sortStack(stack<int> &S)
{
    if (S.empty())
    {
        return;
    }

    int temp = S.top();
    S.pop();
    sortStack(S);
    insertAtRightPosition(S, temp);
}