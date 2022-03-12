
// we will be using same logic as we have used in tree , 
// we will be using queue data structures and will travese through adjacancy list 
// and keep pushing in queue , but we need to take care of a fact that there could be 
// loops in a graph so to avoid repetition of vertices we will use visited array and 
// make sure each virtice appears only once in the queue.

// time complexity -> O(V + E) , V->no. of vertices , E -> no. of edges

vector<int> bfs(vector<vector<int>> adj, int v, int s) { // v-> no. of vertives , s-> source or starting point
    
    vector<int> result;

    vector<bool> visited(v, false);

    //using queue 
    queue<int> Q;
    visited[s] = true;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        result.push_back(u);

        // traversing through all the adjacent vertices of vertix u
        for(auto i : adj[u]) {
            //checking if the vertives is already visited or not
            if(!visited[i]) {
                visited[i] = true;
                Q.push(i);
            }
            
        }
    }

    return result;
}

// bfs when source is not given and there is disconnected components (actully bfs is below solution)

// for every disconnected component we will have new source and we can keep track of it using visited
// array , if after all the traersal of adjacent vertices of s , there is some vertices for which visited
// is false , that means there is discconected componemt.

void bfs(vector<vector<int>> &adj, vector<int> &result, vector<bool> &visited, int s) {

    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        result.push_back(u);

        for(auto i : adj[u]) {
            if(!visited[i]) {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}

vector<int> bfsDis(vector<vector<int>> adj, int v) {

    vector<bool> visited(v, false);

    vector<int result;

    for(int i = 0; i < v; i++) {
        // if more that one vertices have this means there is disconnected component
        if(!visited[i]) {
            bfs(adj, result, visited, i);
        }
    }
    return result;
}

