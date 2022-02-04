
bool binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
    {
        return false;
    }

    int start = 0, end = nums.size();

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return false;
}