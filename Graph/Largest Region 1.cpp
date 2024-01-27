#include <bits/stdc++.h>
using namespace std;
//find unit area of the largest region of 1s.
int largestRegion(vector<vector<int> >& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // creating a queue that will help in bfs traversal
    queue<pair<int, int> > q;
    int area = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // if the value at any particular cell is 1 then
            // from here we need to do the BFS traversal
            if (grid[i][j] == 1) {
                ans = 0;
                // pushing the pair<i,j> in the queue
                q.push(make_pair(i, j));
                // marking the value 1 to -1 so that we
                // don't again push this cell in the queue
                grid[i][j] = -1;
                while (!q.empty()) {
 
                    pair<int, int> t = q.front();
                    q.pop();
                    ans++;
                    int x = t.first;
                    int y = t.second;
                    // now we will check in all 8 directions
                    if (x + 1 < m) {
                        if (grid[x + 1][y] == 1) {
                            q.push(make_pair(x + 1, y));
                            grid[x + 1][y] = -1;
                        }
                    }
                    if (x - 1 >= 0) {
                        if (grid[x - 1][y] == 1) {
                            q.push(make_pair(x - 1, y));
                            grid[x - 1][y] = -1;
                        }
                    }
                    if (y + 1 < n) {
                        if (grid[x][y + 1] == 1) {
                            q.push(make_pair(x, y + 1));
                            grid[x][y + 1] = -1;
                        }
                    }
                    if (y - 1 >= 0) {
                        if (grid[x][y - 1] == 1) {
                            q.push(make_pair(x, y - 1));
                            grid[x][y - 1] = -1;
                        }
                    }
                    if (x + 1 < m && y + 1 < n) {
                        if (grid[x + 1][y + 1] == 1) {
                            q.push(make_pair(x + 1, y + 1));
                            grid[x + 1][y + 1] = -1;
                        }
                    }
                    if (x - 1 >= 0 && y + 1 < n) {
                        if (grid[x - 1][y + 1] == 1) {
                            q.push(make_pair(x - 1, y + 1));
                            grid[x - 1][y + 1] = -1;
                        }
                    }
                    if (x - 1 >= 0 && y - 1 >= 0) {
                        if (grid[x - 1][y - 1] == 1) {
                            q.push(make_pair(x - 1, y - 1));
                            grid[x - 1][y - 1] = -1;
                        }
                    }
                    if (x + 1 < m && y - 1 >= 0) {
                        if (grid[x + 1][y - 1] == 1) {
                            q.push(make_pair(x + 1, y - 1));
                            grid[x + 1][y - 1] = -1;
                        }
                    }
                }
 
                area = max(ans, area);
                ans = 0;
            }
        }
    }
    return area;
}
int main()
{
    vector<vector<int> > M = 
    { { 0, 0, 1, 1, 0 },{ 1, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },{ 0, 0, 0, 0, 1 } };
    cout << largestRegion(M);
    return 0;
}
