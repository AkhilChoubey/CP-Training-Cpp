
// we are given with an array , we have to find max. length subarray with alternating even odd element.

// Logic -- for each element we will check if it's previous element is alternating or not , if , so
// we will increment curr += 1 , we will traverse through the array and keep incrementing curr.
// if at any point we found current element and previous element same (even / odd) , set curr = 1

int maxLengthEvenOddSubarray(vector<int> &nums)
{
    int curr = 1;
    int res = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if ((nums[i] % 2 == 0 && nums[i - 1] % 2 != 0) || (nums[i] % 2 != 0 && nums[i - 1] % 2 == 0))
        {
            curr += 1;
        }
        else
        {
            curr = 1;
        }
        res = max(res, curr);
    }
    return res;
}
