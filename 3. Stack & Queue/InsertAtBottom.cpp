#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &S, int x)
{
    if (S.empty())
    {
        S.push(x);
        return;
    }

    int temp = S.top();
    S.pop();
    insertAtBottom(S, x);
    S.push(temp);
}