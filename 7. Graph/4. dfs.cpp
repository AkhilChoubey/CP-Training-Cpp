
// dfs - depth first search , it recursively call dfs() for it's adjacent nodes

// time complexity - O(V + E) , where , V is no. of vertices , E is no. of edges

void dfs(vector<vector<int>> &adj, vector<int> &result, vector<bool> &visited, int s) {

    //marking visited as true for current vertix and adding it to result
    visited[s] = true;
    result.push_back(s);

    for(auto i : adj[s]) {
        if(!visited[i]) {
            dfs(adj, result, visited, i);
        }
    }
}

vector<int> dfs(vector<vector<int>> adj, int v) {
    vector<bool> visited(v, false);
    vector<int> result;

    for(int i = 0; i < v; i++)
    {
        if(!visited[i]) {
            // calling dfs for every vertix which is not visited
            dfs(adj, result, visited, i);
        }
    }
    return result;
}