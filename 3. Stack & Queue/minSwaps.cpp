#include <bits/stdc++.h>
using namespace std;

//minimum Swaps to make parenthesis balanced --
// Ex - ']][][[' output : 2

// Logic -- we will maintain two variables , open & close , when we find an open parenthesis , we will do open +=1
// if(open == 0 && str[i] == ']') then close +=1 , and (if open > 0 && str[i] == ']') then open--;

int minSwaps(string str)
{
    if (str.size() == 0)
    {
        //ask interviewer
        return 0;
    }

    int open = 0, close = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '[')
        {
            open += 1;
        }
        else
        {
            if (open == 0 && str[i] == ']')
            {
                close += 1;
            }
            else if (open > 0 && str[i] == ']')
            {
                open -= 1;
            }
        }
    }
    return (close + 1) / 2;
}