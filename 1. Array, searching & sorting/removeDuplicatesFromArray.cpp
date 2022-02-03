
// we will traverse through whole array and if we found arr[i] != arr[i-1] we will push arr[i] to arr[res] position.

vector<int> removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }

    int res = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return nums;
    // if asked no. of unique values in array -- return res
}