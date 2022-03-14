
// DAG -> Directed Acuclic Graph

// the idea is to use topological sort , we will firstly find the topological sort of the raph,
// then for every vertic we will traverse through it's adjacency list and udpate our distace array
// as if(dist[v] > dist[u] + weight(u,v)) {
//      dist[v] = dist[u] + weight(u,v);
//    }

void dfs(vector<vector<int>> &arr, vector<bool> visited, int s, stack<int> &S) {

    visited[s] = true;

    for(auto i : arr[s]) {
        if(!visited[i]) {
            dfs(arr, visited, i, S);
        }
    }

    S.push(s);
}

vector<int> topologicalSort(vector<vector<int>> &arr,vector<vector<int>> &weight, int v) {
    vector<int> topo;
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);

    stack<int> S;

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfs(arr, visited, i, S);
        }
    }

    while(!S.empty()) {
        topo.push_back(S.top());
        S.pop();
    }

    // for every topo element go to it's ajjacent vertices and update it's path value
    for(auto u : topo) {
        for(auto v : arr[v]) // all adjacent of vertix u
            if(dist[v] > dist[u] + weight[u][v]) { 
                dist[v] = dist[u] + weight[u][v]; // updating value of all adjacent vertices of u
            }
    }

    return dist;

}
