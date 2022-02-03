

void reverse(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}