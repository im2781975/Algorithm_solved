//Given a string s, find the longest palindromic subsequence's length in s. 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1; // Every single character is a palindrome of length 1.
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}
int main() {
    string s = "babad";
    int result = longestPalindromeSubseq(s);
    cout << "Longest Palindromic Subsequence Length: " << result ;
    return 0;
}
