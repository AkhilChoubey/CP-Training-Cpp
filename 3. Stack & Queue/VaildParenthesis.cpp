
// x&1 --> checks if x is odd or not (faster way)
#include <bits/stdc++.h>
using namespace std;

// Logic -- For every opening parenthesis we will push the element ,
//          then for every closing parenthesis we will check if S.top() is it's opening or not ,
//          if it is we will popo the top of stack
bool validParenthesis(string s)
{
    if (s.size() == 0)
    {
        return true;
    }

    stack<char> S;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            S.push(s[i]);
        }
        else
        {
            if (!S.empty())
            {
                if (s[i] == ')' && S.top() == '(' ||
                    s[i] == '}' && S.top() == '{' ||
                    s[i] == ']' && S.top() == '[')
                {
                    S.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (!S.empty())
    {
        return false;
    }

    return true;
}