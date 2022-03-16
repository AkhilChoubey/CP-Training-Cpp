
// logic - the main idea is to find the mimimum element and put it to right place.
// time complexity : O(n^2)

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for(int i = n-1; i >= 1; i--) {
        for(int j = n-1; j >= 1; j++) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}