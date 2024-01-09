//You are given an n×m grid a of non-negative integers. The value ai,j represents the depth of water at the i-th row and j-th column.
//A lake is a set of cells such that:each cell in the set has ai,j>0, and there exists a path between any pair of cells in the lake by going up, down, left, or right a number of times and without stepping on a cell with ai,j=0
//The volume of a lake is the sum of depths of all the cells in the lake.Find the largest volume of a lake in the grid.
#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& current_volume) {
    visited[x][y] = true;
    current_volume += grid[x][y];
    
    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        
        if (isValid(new_x, new_y) && grid[new_x][new_y] > 0 && !visited[new_x][new_y]) {
            dfs(grid, visited, new_x, new_y, current_volume);
        }
    }
}

int findLargestLakeVolume(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    int largest_volume = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                int current_volume = 0;
                dfs(grid, visited, i, j, current_volume);
                largest_volume = max(largest_volume, current_volume);
            }
        }
    }

    return largest_volume;
}

int main() {
    // Input your grid as a vector of vectors of integers.
    vector<vector<int>> grid = {
        {1, 0, 2, 3, 4},
        {0, 1, 4, 0, 2},
        {2, 4, 5, 0, 1}
    };

    int largest_volume = findLargestLakeVolume(grid);

    cout << "The largest volume of a lake in the grid is: " << largest_volume ;
    return 0;
}

