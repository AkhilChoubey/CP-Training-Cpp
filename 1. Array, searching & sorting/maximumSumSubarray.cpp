
// we are given with array , we need to return maxximum sum of all subarray

int maximumSumSubarray(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int maxEnding = arr[0];
    int res = arr[0];
    for (int i = 1; i < nums.size(); i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }

    return res;
}