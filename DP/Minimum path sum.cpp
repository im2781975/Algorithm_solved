//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
//which minimizes the sum of all numbers along its path. You can only move either down or right at any point in time.
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Create a 2D vector to store the minimum path sums
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the first element of dp with the value from the grid
    dp[0][0] = grid[0][0];

    // Initialize the first row of dp
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    // Initialize the first column of dp
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    // Fill in the rest of the dp array
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    // The value in the bottom-right cell of dp will be the minimum sum path
    return dp[m - 1][n - 1];
}
int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int minSum = minPathSum(grid);
    cout << "Minimum sum path: " << minSum ;
    return 0;
}
