//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
#include <iostream>
#include <vector>
using namespace std;
bool canPartition(std::vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    if (sum % 2 != 0) {
        return false; // If the sum is not even, it can't be divided into two equal subsets.
    }
    int target = sum / 2;
    int n = nums.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}
int main() {
    vector<int> nums = {1, 5, 11, 5};
    bool result = canPartition(nums);
    if (result) {
        cout << "The array can be partitioned into two equal-sum subsets." ;
    } else {
        cout << "The array cannot be partitioned into two equal-sum subsets." ;
    }
    return 0;
}
