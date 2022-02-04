// majority element - it is an element which have appeared more than half the size of array.
// Boyer-moore voting algorithm

int findMajority(vector<int> &nums)
{

    int res = 0, count = 0;
    // finding candidate for majority check (finding max appearing element in the array).
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[res])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            count = 1;
            res = i;
        }
    }

    count = 0;
    // checking if our candidate element has occurace more then half of array size or not
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[res])
        {
            count++;
        }
    }
    if (count >= nums.size() / 2)
    {
        return res;
    }

    return -1;
}