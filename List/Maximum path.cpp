#include <bits/stdc++.h>
using namespace std;
// find the longest distance from source to destination with at most K intermediate nodes
int findShortestPath(
    int n, vector<vector<int> >& edges,
    int src, int dst, int K)
{
    // Initialize the adjacency list
    vector<vector<pair<int, int> > > adjlist(
        n, vector<pair<int, int> >());
    // Initialize a queue to perform BFS
    queue<pair<int, int> > q;
    unordered_map<int, int> mp;
 
    // Store the maximum distance of every node from source vertex
    int ans = INT_MIN;
    // Initialize adjacency list
    for (int i = 0; i < edges.size(); i++) {
 
        auto edge = edges[i];
 
        adjlist[edge[0]].push_back(
            make_pair(edge[1], edge[2]));
    }
    // Push the first element into queue
    q.push({ src, 0 });
    int level = 0;
 
    // Iterate until the queue becomes empty and the number of nodes between src
    // and dst vertex is at most to K
    while (!q.empty() && level < K + 2) {
        // Current size of the queue
        int sz = q.size();
 
        for (int i = 0; i < sz; i++) {
            // Extract the front
            // element of the queue
            auto pr = q.front();
            // Pop the front element of the queue
            q.pop();
            // If the dst vertex is reached
            if (pr.first == dst)
                ans = max(ans, pr.second);
            // Traverse the adjacent nodes
            for (auto pr2 : adjlist[pr.first]) {
                // If the distance is greater than the current distance
                if (mp.find(pr2.first)
                        == mp.end()
                    || mp[pr2.first]
                           > pr.second
                                 + pr2.second) {
                    // Push it into the queue
                    q.push({ pr2.first,
                             pr.second
                                 + pr2.second });
                    mp[pr2.first] = pr.second
                                    + pr2.second;
                }
            }
        }
        // Increment the level by 1
        level++;
    }
    // Finally, return the maximum distance
    return ans != INT_MIN ? ans : -1;
}
int main()
{
    int n = 3, src = 0, dst = 2, k = 1;
    vector<vector<int> > edges
        = { { 0, 1, 100 },
            { 1, 2, 100 },
            { 0, 2, 500 } };
 
    cout << findShortestPath(n, edges, src, dst, k);
 
    return 0;
}
