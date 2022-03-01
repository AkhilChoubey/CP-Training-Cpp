
int 3rdLargest(vector<int> arr) {
    int max = arr[0];
    int secMax = arr[0];
    int thirdMax = arr[0];

    for(int i = 0; i < arr.size(); i++) {
        if(max < arr[i]) {
            thirdMax = secMax;
            secMax = max;
            max = arr[i];
        }
        else if(secMax < arr[i]) {
            thirdMax = secMax; 
            secMax = arr[i];
        }
        else if(thirdMax < arr[i]) {
            thirdMax = arr[i];
        }
    }

    return thirdMax;
}