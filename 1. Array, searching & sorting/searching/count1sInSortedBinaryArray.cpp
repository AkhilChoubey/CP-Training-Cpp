
int count1sInSortedArray(vector<int> &nums)
{
    int start = 0, end = nums.size();

    while (start <= end)
    {

        int mid = (start + end) / 2;

        if (arr[mid] == 0)
        {
            start = mid + 1;
        }
        else
        {
            if (mid == 0 || nums[mid] != nums[mid - 1])
            {
                return nums.size() - mid;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}