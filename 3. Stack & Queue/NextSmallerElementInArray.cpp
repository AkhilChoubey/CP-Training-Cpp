#include<bits/stdc++>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr) {
    if(arr.size() == 0) {
        //ask interveiwer
        return {};
    }

    int n = arr.size();
    vector<int> result(n);
    stack<int> S;

    result[n-1] = -1;
    for(int i = n-1; i >= 0; i--){
        while(!S.empty() && arr[S.top()] > arr[i]) {
            S.pop();
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