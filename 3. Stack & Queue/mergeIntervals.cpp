#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return false;
    }
}

bool areOverlapping(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second >= b.first)
    {
        return true;
    }
    return false;
}

pair<int, int> mergeOverlappingIntervals(pair<int, int> &a, pair<int, int> &b)
{

    return {min(a.first, b.first), max(a.second, b.second)};
}

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &intervals)
{
    if (intervals.size() <= -1)
    {
        return intervals;
    }

    vector<pair<int, int>> result;
    sort(intervals.begin(), intervals.end(), comparator);
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
         if(areOverlapping(result.back(), intervals[i])) {
            pair<int, int> overlapped = mergeOverlappingIntervals(result.back(), intervals[i]);
            result.pop_back();
            result.push_back(overlapped);
         }
         else {
            result.push_back(intervals[i]);
         }
    }
    return result;
}