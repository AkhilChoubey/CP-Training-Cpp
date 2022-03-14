
// Logic -- If the element is smaller than the last,
//              the point of rotation definitely lies in the left of the middle element
//              Hence, redefine the range for probing [L .. M – 1]
//          Else
//              The point of rotation certainly lies in the right of the middle element
//              Hence, redefine the range for probing [M+1, L]


int pointOfRotation(vector<int> arr) {
    int start = 0;
    int end = arr.size();

    int last = arr[end-1];

    int mid = (start + end) / 2;

    while(start <= end) {
        mid = (start + end) / 2;

        if(arr[mid] < last) {
            end = mid - 1;
        }
        else if(arr[mid] > last) {
            start = mid + 1;
        }
        else {
            break;
        }
    }

    return mid;
}