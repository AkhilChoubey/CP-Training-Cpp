

// return the 1st occurance of target element

int firstOccurance(vector<int> &nums, int target)
{
    int start = 0, end = nums.size();
    int n = nums.size();

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            if (mid == n - 1 || nums[mid] != nums[mid + 1])
            {
                return mid;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}