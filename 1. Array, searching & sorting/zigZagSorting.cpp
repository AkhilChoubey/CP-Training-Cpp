
// you are given with an array , you need to sort thr array in zig-zag fashion (increasing->deacreasing->increa...)
// Ex - a > b < c > d < e
// Time Complexity - O(n)

// Logic : we will use a flag variable and for every interation we will revert the flag value and 
//         using a condition we will perform two alternating operations. 

void zigZagSort(vector<int> arr) {
    if(arr.size() == 0) {
        return;
    }

    bool flag = true;

    for(int i = 0; i < arr.size()-1; i++) {
        if(flag) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        else {
            if(arr[i] < arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }

        flag = !flag;
    }
}