// You are given a sorted array consisting of only integers where every element appears exactly twice,
// except for one element which appears exactly once.
// Return the single element that appears only once.

int singleNonDuplicate(vector<int> &nums)
{

    if (nums.size() == 1)
    {
        return nums[0];
    }

    int start = 0, end = nums.size();
    while (start <= end)
    {

        int mid = (start + end) / 2;

        if ((mid == 0 && (nums[mid] != nums[mid + 1])) ||
            (mid == nums.size() - 1 && (nums[mid] != nums[mid - 1])) ||
            nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        else if ((nums[mid] == nums[mid - 1] && mid % 2 == 0) ||
                 (nums[mid] == nums[mid + 1] && mid % 2 != 0))
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}