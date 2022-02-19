// we will use binary search, idea is one half will always be sorted , we will compare the mid element
// with one of the corner elment , let's say first element, if(nums[mid] > nums[start]) then left half is sorted
// else right half is sorted. if element lie in sorted half we will search there or we will apply
// search in unsorted part.

int seachInRotatedArray(vector<int> &nums, int target)
{
    int start = 0, end = nums.size();

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > nums[start])
        {
            if (target >= nums[start] && target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (target > nums[mid] && target <= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}