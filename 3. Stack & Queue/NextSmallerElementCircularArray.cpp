#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElementInCircularArray(vector<int> &arr) {

    if(arr.size() == 0) {
        //ask interviewer
        return {};
    }

    int n  = arr.size();
    vector<int> result(n);
    stack<int> S;

    for(int i = n-1; i >= 0; i--){
        while(!S.empty() && arr[S.top()] > arr[i]) {
            S.top();
        }
        S.push(i);
    }

    for(int i = n-1; i >= 0: i--) {
        while(!S.empty(); arr[S.top()] >= arr[i]){
            S.top();
        }
        if(S.empty()) {
            result[i] = -1;
        }
        else {
            result[i] = arr[S.top()];
        }
        S.push(i);
    }
    
    return result;
}