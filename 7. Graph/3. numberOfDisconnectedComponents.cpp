
// popular interview question -> find no. of islands (island -> disconnected component)

// logic -> we will simpally use bfs() algo for disconnected components and count the no. of bfs call.
// we can also use dfs() 

void bfs(vector<vector<int>> &adj, vector<int> &visited, int s) {

    queue<int> Q;
    Q.push(s);
    visited[s] = true;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(auto i : adj[u]) {
            if(!visited[i]) {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
    
}

int distinctComponents(vector<vector<int>> &adj, int v) {

    vector<int> visited(v, false);
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bfs(adj, visited, i);
            // incrementing count wheneven new disconnected component is found
            count += 1;
        }
    }
    return count;
}