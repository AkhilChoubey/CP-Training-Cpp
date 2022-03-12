
// we will be using dfs for cycle detection , we will maintain a visited array and 
// if visited of a vertix is true and we came to that vertix again that means there is a cycle , 
// we have to maintain a parent variable so that we donot return true when we visited to  
// the vertix from where we came to current vertix.

// time complexity - O(V + E) , where , V is no. of vertices , E is no. of edges

// cycle detection in undirected graph
bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int s, int parent) {

    visted[s] = true;

    for(auto i : adj[s]) {
        if(!visited[i]) {
            if(dfs(adj, visited, i, s) == true) {  // if there is already cycle detected , then we will keep returning true
                return true;
            }
        }
        else {
            if(i != parent) {
                return true;
            }
        }
    }

    return false;
}


bool dfs(vector<vector<int>> adj, int v) {
    vector<bool> visited(v, false);
    
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            if(dfs(adj, visited, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

// cycle detection in directed graph
// for directed graph the above solution will not work , 
// there is a cycle only if a desendent in recursive stack calls an ansester of it's recursive stack
// we will maintain an bool array recStack and mark it true for all the the vertix in current rec stack
// we will mark it back to false for other recursive stack , if we find an recStack[i] for current 
// vertex true , then there is cycle

bool dfs(vector<vector<int>> &adj, vector<int> visited, vector<int> &recStack, int s) {
    visited[s] = true;
    recStack[s] = true;

    for(auro i : adj[s]) {
        if(!visited[i]) {
            if(dfs(adj, visited, recStack, i) == true) {
                return true;
            }
        }
        else {
            // if i is already present in reccursive stack then return true
            if(recStack[i] == true) {
                return true;
            }
        }
    }
    recStack[s] = false;
    return false;
}

bool dfs(vector<vector<int>> adj, int v) {
    vector<bool> visited(v, false);
    vector<bool> recStack(v, false);

    for(int i = 0; i < v; i++) {
        if(dfs(adj, visited, recStack, i) == true) {
            return true
        }
    }
    return false;
}