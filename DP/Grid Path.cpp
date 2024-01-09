//Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
//Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int countPaths(int n, vector<vector<bool>>& traps) {
    vector<vector<int>> dp(n,vector<int>(n, 0));

    // Initialize the top-left square.
    dp[0][0] = traps[0][0] ? 0 : 1;
    // Initialize the first column.
    for (int i = 1; i < n; ++i) {
        if (!traps[i][0]) {
            dp[i][0] = dp[i - 1][0];
        }
    }
    // Initialize the first row.
    for (int j = 1; j < n; ++j) {
        if (!traps[0][j]) {
            dp[0][j] = dp[0][j - 1];
        }
    }
    // Fill in the DP table.
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (!traps[i][j]) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    return dp[n - 1][n - 1];
}
int main() {
    int n; 
    cin >> n;

    vector<vector<bool>> traps(n, vector<bool>(n, false));

    // Input trap locations (1 for trap, 0 for empty square)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int trap;
            cin >> trap;
            traps[i][j] = (trap == 1);
        }
    }
    int result = countPaths(n, traps);
    cout << result ;
    return 0;
}
