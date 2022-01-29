#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vetor<int> &arr) {
    if(arr.size() == 0) {
        return {};
    }
    int n = arr.size();
    vector<int> result(n);
    stack<int> S;

    result[n-1] = -1;

    for(int i = n-1; i>=0; i--){
        //checking if current elment is greater than elements in stack --
        // the loop will stop when we found an element greater than cuurent element 
        //or stack becomes empty (untill then we will pop the top of stack)
        while(!S.empty() && arr[S.top()] < arr[i]) {
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