
// Topological sort : we are given with a directed acyclic graph and we need to make sure that all 
//           the dependent vertices must come after the current vertix.

// Logic : we will use dfs and a stack , the idea is to push all the dependent of a vertix before pushing it.
//         we just need to call dfs for each vertix and after the caller we will push the vertic in stack
//         so that it will be pushed after it's child.

// time & space : O(V + E) and O(V) (using stack for storing all the vertices)

void dfs(vector<vector<int>> &arr, vector<int> &visited, int s, stack<int> &S) {

    visited[s] = true;

    for(auto i : arr[s]) {
        if(!visited[i]) {
            dfs(arr, i, S);
        }
    }
    S.push(s);
}


vector<int> topologicalSort(vector<vector<int>> &arr, int v) {
    vector<bool> visited(v, false);
    vector<int> result;

    // creating stack to store vertix
    stack<int> S;

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfs(arr, visited, i, S);
        }
    }
    
    // pushing all the values of stack into result array
    while(!S.empty()) {
        result.push_back(S.top());
        S.pop();
    }

    return result;
}
