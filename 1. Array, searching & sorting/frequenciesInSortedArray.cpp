// we are given with sorted array, we have to return frequency of each elementof the array.

vector<pair<int, int>> frequenciesOfSortedArray(vector<int> &nums)
{

    vector<pair<int, int>> result;

    int freq = 1;
    int i = 1;

    while (i < nums.size())
    {
        while (i < nums.size() && nums[i] == nums[i - 1])
        {
            freq += 1;
            i++;
        }
        result.push_back({nums[i - 1], freq});
        i++;
        freq = 1;
    }

    return result;
}