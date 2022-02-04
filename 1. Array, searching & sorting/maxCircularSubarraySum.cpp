
// we are given with array , we need to find maximum bettween normalMax Subarray Sum and circular subarray sum

// trick -- we can find maxCircularSubArraySum by [TotalSum - minimumSubarraySum]

// Finding maximum subarray sum (normal)
int maxSubarraySum(vector<int> &nums)
{
    int res = nums[0];
    int maxEnding = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        maxEnding = max(maxEnding + nums[i], nums[i]);
        res = max(res, maxEnding);
    }
    return res;
}

// Finding minimum subarray sum (normal)
int maxSubarraySum(vector<int> &nums)
{
    int res = nums[0];
    int minEnding = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        minEnding = min(minEnding + nums[i], nums[i]);
        res = min(res, minEnding);
    }
    return res;
}

int maxCircularSubArraySum(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    // maximum normal subarray sum
    int maxNormalSum = maxSubarraySum(nums);

    if (maxNormalSum < 0)
    {
        return maxNormalSum;
    }

    // minimum normal subarray sum
    int minNormalSum = minSubArraySum(nums);

    int totalSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totalSum += nums[i];
    }

    // Maximum Circular Subarray Sum
    int maxCircularSum = totalSum - minNormalSum;

    return max(maxCircularSum, maxNormalSum);
}