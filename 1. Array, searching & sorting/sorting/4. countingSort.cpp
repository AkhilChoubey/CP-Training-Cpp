
// logic - we will count the no. of occurances of all the elements till the given value k 
//         (or we can find max element of arr) , and for every element we will insert the element 
//         as many times as there count is.

// time complexity O(n + k) , where k is mac element of the array
// space complexity : O(k) 

void countingSort(vector<int> &arr, int k) { // k is max Element of the array 

    vector<int> count(k+1, 0);
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for(int i = 0; i < k; i++) {
        // pushing every element count[i] number of times
        while(count[i]--) {
            arr[index] = i;
            index++;
        }
    }     
}