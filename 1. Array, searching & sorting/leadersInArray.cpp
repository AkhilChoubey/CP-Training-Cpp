
// Leader -- an element is a leader only if there is no element greater than that element on it's right side.

vector<int> leaders(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int n = nums.size();
    vector<int> result;
    int currentLeader = nums[n - 1];
    result.push_back(currentLeader);

    for (int i = n - 2; i >= 0; i--)
    {
        if (currentLeader < nums[i])
        {
            currentLeader = nums[i];
            result.push_back(currentLeader);
        }
    }

    return result;
}