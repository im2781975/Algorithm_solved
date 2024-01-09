//given strings s & t. Find one longest string that is a subsequence of both s and t.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string longestCommonSubsequence(const string& s, const string& t) {
    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Building the dynamic programming table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int length = dp[m][n];
    string lcs(length, ' ');
    // Backtrack to find the LCS
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs[--length] = s[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}
int main() {
    string s = "AGGTAB";
    string t = "GXTXAYB";

    string lcs = longestCommonSubsequence(s, t);

    cout << "Longest Common Subsequence: " << lcs ;
    return 0;
}
