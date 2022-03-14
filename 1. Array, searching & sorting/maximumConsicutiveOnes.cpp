
// we are given with binary array , we need to find max consecutive 1's in it.
//  Ex - [0,1,1,1,1,0,1,1,0] , output : 4

// Tn - O(n^2) | Sn - O(1)

int maximumConsecutiveOnes(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return 0;
    }

    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int curr = 0;
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] == 1)
            {
                curr += 1;
            }
            else
            {
                break;
            }
            result = max(result, curr);
        }

        return result;
    }
}

// eficient solution : O(n)
// when current element is 1 increment the count , when 0 is incountered set count to 0
// for every itreation we will update the result variable to max(result, count)

int maxConsicutiveOnes(vector<int> &arr) {
    int count = 0;
    int result = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 1) {
            count += 1;
        }
        else {
            count = 0;
        }
        result = max(result, count);
    }

    return result;
}