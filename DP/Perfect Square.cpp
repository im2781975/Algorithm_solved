//Given an integer n, return the least number of perfect square numbers that sum to n.
#include <vector>
#include <algorithm>
using namespace std;
int numSquares(int n) {
    // Create a vector to store the minimum number of perfect squares needed to sum to each number from 0 to n.
    vector<int> dp(n + 1, INT_MAX);
    // Initialize dp[0] to 0, since it takes 0 perfect squares to sum to 0.
    dp[0] = 0;
    // Generate a list of perfect squares up to n.
    vector<int> perfectSquares;
    for (int i = 1; i * i <= n; i++) {
        perfectSquares.push_back(i * i);
    }
    for (int i = 1; i <= n; i++) {
        for (int square : perfectSquares) {
            if (i - square >= 0) {
                dp[i] = std::min(dp[i], dp[i - square] + 1);
            }
        }
    }
    return dp[n];
}
int main() {
    int n = 12; 
    int result = numSquares(n);
    std::cout << "The least number of perfect squares that sum to " << n << " is: " << result ;
    return 0;
}

