//You are given an integer array nums and an integer target.
//You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
//For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
//Return the number of different expressions that you can build, which evaluates to target.
#include <vector>
#include <unordered_map>
using namespace std;
int findWaysToEvaluateExpression(vector<int>& nums, int target) {
    unordered_map<int, int> dp;
    dp[nums[0]] = 1;
    dp[-nums[0]] += 1;

    for (int i = 1; i < nums.size(); i++) {
        unordered_map<int, int> next_dp;
        for (const auto& pair : dp) {
            next_dp[pair.first + nums[i]] += pair.second;
            next_dp[pair.first - nums[i]] += pair.second;
        }
        dp = next_dp;
    }
    return dp[target];
}
int main() {
    vector<int> nums = {2, 1};
    int target = 1;
    int ways = findWaysToEvaluateExpression(nums, target);
    cout << "Number of ways to evaluate the expression to target: " << ways ;
    return 0;
}
