#include<bits/stdc++.h>
using namespace std;

void firstKSmallestElement(vector<int> &arr, int k){
	int n = arr.size();
	
	
	
	
	for(int i=k;i< n;i++){
		
		int max = arr[k-1];
		int pos = k-1;
		//Finding Max Element
		
		for(int j=k-2;j>=0;j--){
			if(max < arr[j]){
				max = arr[j];
				pos = j;
			}	
		}
		
		//Left Shifting All element from j to K-1
		if(max > arr[i]){
			int j = pos;
			while(j<k-1){
				arr[j] = arr[j+1];
				j++;
			}
		
		//Pushing smaller element in first K
		arr[k-1] = arr[i];
	}
	

	}
	cout<<"First "<<k<<" smallest Element in Same Order :: ";
	for(int i=0;i<k;i++){
		cout<<arr[i]<<" ";
	}	

	
}

int main() {
	int n;
	cin>>n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	
	firstKSmallestElement(arr, k);
}
