//You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
pair<int, int> findTwoSum(vector<int>& nums, int x) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = x - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return make_pair(numMap[complement], i);
        }
        numMap[nums[i]] = i;
    }
    return make_pair(-1, -1);  // Return (-1, -1) if no such pair is found.
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    pair<int, int> result = findTwoSum(nums, target);
    if (result.first != -1) {
        cout << "Indices: " << result.first << " and " << result.second ;
        cout << "Values: " << nums[result.first] << " and " << nums[result.second] ;
    } else {
        cout << "No such pair found." ;
    }
    return 0;
}

