// printing Minimum Cost Simple Path between two given nodes
#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF INT_MAX
 
// Function to do DFS through the nodes
int minimumCostSimplePath(int u, int destination,
 bool visited[], int graph[][V])
{
    // check if we find the destination then further cost will be 0
    if (u == destination)
        return 0;
    // marking the current node as visited
    visited[u] = 1;
    int ans = INF;
    // traverse through all the adjacent nodes
    for (int i = 0; i < V; i++) {
        if (graph[u][i] != INF && !visited[i]) {
            // cost of the further path
            int curr = minimumCostSimplePath(i,
                        destination, visited, graph);
            // check if we have reached the destination
            if (curr < INF) {
                // Taking the minimum cost path
                ans = min(ans, graph[u][i] + curr);
            }
        }
    }
    // unmarking the current node to make it available for other simple paths
    visited[u] = 0;
    // returning the minimum cost
    return ans;
}
int main()
{
    // initialising the graph
    int graph[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }
    // marking all nodes as unvisited
    bool visited[V] = { 0 };
    // initialising the edges;
    graph[0][1] = -1;
    graph[0][3] = 1;
    graph[1][2] = -2;
    graph[2][0] = -3;
    graph[3][2] = -1;
    graph[4][3] = 2;
 
    // source and destination
    int s = 0, t = 2;
    // marking the source as visited
    visited[s] = 1;
    cout << minimumCostSimplePath(s, t, 
    visited, graph);
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// Stores minimum-cost of path from source
int minSum = INT_MAX;
 
// Function to Perform BFS on graph g starting from vertex v
void getMinPathSum(unordered_map<int,vector<pair<int,
    int> > >& graph,vector<bool>& visited,
    vector<int> necessary,int src, int dest, int currSum)
{
    // If destination is reached
    if (src == dest) {
        // Set flag to true
        bool flag = true;
        // Visit all the intermediate nodes
        for (int i : necessary) {
 
            // If any intermediate node is not visited
            if (!visited[i]) {
                flag = false;
                break;
            }
        }
        // If all intermediate nodes are visited
        if (flag)
            // Update the minSum
            minSum = min(minSum, currSum);
        return;
    }
    else {
        // Mark the current node visited
        visited[src] = true;
        // Traverse adjacent nodes
        for (auto node : graph[src]) {
 
            if (!visited[node.first]) {
                // Mark the neighbour visited
                visited[node.first] = true;
                // Find minimum cost path considering the neighbour as the source
                getMinPathSum(graph, visited,    necessary, node.first,
                dest, currSum + node.second);
                // Mark the neighbour unvisited
                visited[node.first] = false;
            }
        }
        // Mark the source unvisited
        visited[src] = false;
    }
}
int main()
{
    // Stores the graph
    unordered_map<int, vector<pair<int,int> > > graph;
    graph[0] = { { 1, 2 }, { 2, 3 }, { 3, 2 } };
    graph[1] = { { 4, 4 }, { 0, 1 } };
    graph[2] = { { 4, 5 }, { 5, 6 } };
    graph[3] = { { 5, 7 }, { 0, 1 } };
    graph[4] = { { 6, 4 } };
    graph[5] = { { 6, 2 } };
    graph[6] = { { 7, 11 } };
 
    // Number of nodes
    int n = 7;
    // Source
    int source = 0;
    // Destination
    int dest = 6;
    // Keeps a check on visited and unvisited nodes
    vector<bool> visited(n, false);
    // Stores intermediate nodes
    vector<int> necessary{ 2, 4 };
    getMinPathSum(graph, visited, necessary,source, dest, 0);
 
    // If no path is found
    if (minSum == INT_MAX)
        cout << "-1\n";
    else
        cout << minSum << '\n';
    return 0;
}
