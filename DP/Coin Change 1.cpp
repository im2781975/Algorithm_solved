//given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
#include <vector>
using namespace std;
int change(int amount, vector<int>& coins) {
    // Create a vector to store the number of combinations for each amount from 0 to the target amount.
    vector<int> dp(amount + 1, 0);
    
    // There is one way to make amount 0, which is by not selecting any coin.
    dp[0] = 1;
    
    // Loop through each coin denomination.
    for (int coin : coins) {
        // Update the dp array for each amount from the current coin value to the target amount.
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    // The value at dp[amount] contains the number of combinations to make up the amount.
    return dp[amount];
}
int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int result = change(amount, coins);
    cout << "Number of combinations: " << result ;
    
    return 0;
}
