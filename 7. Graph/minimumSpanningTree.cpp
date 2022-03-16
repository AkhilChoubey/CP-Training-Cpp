// minimum spanning tree : we are given with an undirected-weighted-connected-graph , we need to 
//         connect all the vertices together, without any cycles and with the minimum 
//         possible total edge weight.
// note : no. of edges  = v-1 (that's why it is called tree)

// we will use KRUSKAL'S ALGORITHM
// idea is very simple , we will first sort the edge weights in increasing order and check if
// adding current edge into mst array will cause a cycle or not , if it cause's cycle we will ignore that edge.
// else we will add it's weight to sum variable.

// we can create a seperate graph for min spanning tree and after adding each edge we need to run cycle 
// detection for each vertix. if no cycle , then add it to result.