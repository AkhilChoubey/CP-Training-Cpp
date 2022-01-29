#include <bits/stdc++.h>
using namespace std;

// Logic -- For every element of the array we will find left smallest element and right smallest element
// (we will pre process it like trapping rainwater problem) , the for every element we will find width
// with , width[i] = ((right_smallest_index - 1) - (left_smallest_index + 1) + 1) (using stack we will find next left smaller and next right smaller)
// area = width* heights[i].

vector<int> findLeftSmaller(vector<int> &heights)
{

    vector<int> nsl(heights.size());
    stack<int> S;

    for (int i = 0; i < heights.size(); i++)
    {
        while (!S.empty() && heights[S.top()] >= heights[i])
        {
            S.pop();
        }
        if (S.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            nsl[i] = S.top();
        }
        S.push(i);
    }
    return nsl;
}

vector<int> findRightSmaller(vector<int> &heights)
{

    vector<int> nsr(heights.size());
    stack<int> S;

    for (int i = heights.size() - 1; i >= 0; i--)
    {
        while (!S.empty() && heights[S.top()] >= heights[i])
        {
            S.pop();
        }
        if (S.empty())
        {
            nsr[i] = heights.size();
        }
        else
        {
            nsr[i] = S.top();
        }
        S.push(i);
    }
    return nsr;
}

int largestRectangleArea(vector<int> &heights)
{

    if (heights.size() == 0)
    {
        return 0;
    }
    vector<int> leftSmaller = findLeftSmaller(heights);
    vector<int> rightSmaller = findRightSmaller(heights);

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = ((rightSmaller[i] - 1) - (leftSmaller[i] + 1) + 1);
        maxArea = max(maxArea, width * heights[i]);
    }

    return maxArea;
}

//alternative -> using simple for loop for each element.
int findLeftSmaller(int index, const vector<int> &heights)
{
    for (int i = index - 1; i >= 0; i--)
    {
        if (heights[i] < heights[index])
        {
            return i;
        }
    }
    return -1;
}

int findRightSmaller(int index, const vector<int> &heights)
{
    for (int i = index + 1; i < heights.size(); i++)
    {
        if (heights[i] < heights[index])
        {
            return i;
        }
    }
    return heights.size();
}

int largestRectangleArea(vector<int> &heights)
{

    if (heights.size() == 0)
    {
        return NULL;
    }
    vector<int> leftSmaller(heights.size());
    vector<int> rightSmaller(heights.size());

    for (int i = 0; i < heights.size(); i++)
    {
        leftSmaller[i] = findLeftSmaller(i, heights);
        rightSmaller[i] = findRightSmaller(i, heights);
    }

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = ((rightSmaller[i] - 1) - (leftSmaller[i] + 1) + 1);
        maxArea = max(maxArea, width * heights[i]);
    }

    return maxArea;
}
