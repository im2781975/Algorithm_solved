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
