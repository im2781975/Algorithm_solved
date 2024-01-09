//Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int minDistance(string word1,string word2) {
    int m = word1.length();
    int n = word2.length();
    
    // Create a 2D DP array to store the minimum steps
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill in the DP array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // The minimum steps to make two strings the same is the sum of their lengths minus twice the length of their longest common subsequence
    int longestCommonSubsequence = dp[m][n];
    int minSteps = m + n - 2 * longestCommonSubsequence;
    return minSteps;
}
int main() {
    string word1 = "sea";
    string word2 = "eat";
    int minSteps = minDistance(word1, word2);
    cout << "Minimum steps to make the strings the same: " << minSteps ;
    return 0;
}
