
// logic - we will maintain two part in the array , an sorted part and an unsorted part,
//        if we are at index i that elements between indices 0 and i-1 is alresdy sorted. 
//        we move forword and put the element at it's right place.

// time complexity : O(n^2) , best - O(n)

void insertionSort(vector<int> &arr) {

    int n = arr.size();

    for(int i = 0; i < n; i++) {

        int key = arr[i];
        int j = i-1;

        // looping into the sorted part untill we find right place for current element
        while(j >= 0 && arr[j] > key) {
            //shifting elements towards right to place current element
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}