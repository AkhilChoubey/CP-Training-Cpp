#include<bits/stdc++.h>
using namespace std;

void generateSetsHelper(vector<vector<int>> &result, vector<int> &setSoFar,const vector<int> &vec, int index){
    if(index >= vec.size()){
        result.push_bsck(setSoFar);
        return;
    }
    else {
        setSoFar.push_back(vec[index]);
        generateSetsHelper(result, setSoFar, vec, index + 1);

        // backtraking
        setSoFar.pop_back();
        generateSetsHelper(result, setSoFar, vec, index + 1);
    }
}

vector<vector<int>> generateSets(vector<int> &vec) {
    if(vec.size() == 0) {
        return {};
    }
    vector<vector<int>> result;
    vector<int> setSoFar;

    generateSetsHelper(result, setSoFar, vec, 0);

    return result;
}


int main() {

}