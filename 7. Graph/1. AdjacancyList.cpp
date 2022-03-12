
// adjacancy list - it is a 2d array , where each index represent a vertics and all the elements for particular
//                  vertices represents edges to that vertices.


// adding new edge to the adjacency list
void addEdge(vector<int> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {

    int v;
    cin>>v; // no. of vertices
    vector<vector<int>> ajd(v);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
}