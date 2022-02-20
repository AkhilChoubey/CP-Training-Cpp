
// we are given with an array we have to find max diffrence of 2 elements.

// Logic -- we will consider a min value element , and initialize it to arr[0] , and we will subtract it with each element,
//  res = max (res, arr[i] - minVal) and if we find an element with value less than minVal , we will update
//  minVal to that element.

int maxDiffrence(vector<int> &arr)
{

    int minVal = arr[0];
    int res = arr[1] - arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        res = max(res, arr[i] - minVal);
        minVal = min(minVal, arr[i]);
    }

    return res;
}