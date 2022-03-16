
// logic - idea is to move the largest element to it's right position and so on.
// time complexity - O(n^2)

void bubbleSort(vector<int> &arr) {
    
    int n = arr.size();

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}