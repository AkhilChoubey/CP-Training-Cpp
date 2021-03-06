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
        insertAtRightPosition(S, x);
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

    // int size = S.size();
    // while(size--) {
    //     int temp = S.top();
    //     S.pop();
    //     insertAtRightPosition(S, temp);
    // }
    int temp = S.top();
    S.pop();
    sortStack(S);
    insertAtRightPosition(S, temp);
}