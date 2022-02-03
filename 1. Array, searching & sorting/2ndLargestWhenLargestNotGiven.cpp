
// find the 2nd largest element in an array when largest is not given

int secondLargest(vector<int> &nums)
{
    int max = arr[0];
    int secondMax = arr[0];

    for (int i = 0; i < nums.size(); i++)
    {
        if (arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
    }
    return secondMax;
}