#include <bits/stdc++.h>
using namespace std;
int max_cost(int n, vector<vector<int> >& edges, int src,
             int dst, int k)
{
    // We use 2 arrays for this algorithm.temp is the shortest distances array in current pass
    vector<int> temp(n, INT_MAX);
    temp[src] = 0;
    for (int i = 0; i <= k; i++) {
        // c is the shortest distances array in previous pass For every iteration current pass becomes the previous
        vector<int> c(temp);
        for (auto edge : edges) {
            int a = edge[0], b = edge[1], d = edge[2];
            // Updating the current array using previous array Subtracting d is same as adding -d
            temp[b]
                = min(temp[b],
                      c[a] == INT_MAX ? INT_MAX : c[a] - d);
        }
    }
    // Checking is dst is reachable from src or not
    if (temp[dst] != INT_MAX) {
        // Returning the negative value of the shortest distance to return the longest distance
        return -temp[dst];
    }
    return -1;
}
int main()
{
    vector<vector<int> > edges = {
        { 0, 1, 100 },
        { 1, 2, 100 },
        { 0, 2, 500 },
    };
    int src = 0;
    int dst = 2;
    int k = 1;
    int n = 3;
 
    cout << max_cost(n, edges, src, dst, k) << endl;
    return 0;
}

