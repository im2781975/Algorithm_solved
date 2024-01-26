//return the length of the longest increasing path in matrix.
#include <vector>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int longestPath = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longestPath = max(longestPath, dfs(matrix, i, j, memo));
            }
        }
        return longestPath;
    }
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& memo) {
        if (memo[x][y] != 0) {
            return memo[x][y];
        }
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxPath = 1;

        for (const auto& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size() && matrix[newX][newY] > matrix[x][y]) {
                maxPath = std::max(maxPath, 1 + dfs(matrix, newX, newY, memo));
            }
        }
        memo[x][y] = maxPath;
        return maxPath;
    }
};
int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    Solution solution;
    int result = solution.longestIncreasingPath(matrix);
    cout << "Length of the longest increasing path: " << result << endl;

    return 0;
}
