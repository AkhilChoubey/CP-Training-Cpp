
// Find 2nd Largest element in an array when the largest element is given.

int find2ndLargestWhenLargestGiven(vector<int> &nums, int largest)
{
    int secondLargest = arr[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (arr[i] == largest)
        {
            continue;
        }

        if (secondLargest < arr[i])
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}