#include <bits/stdc++.h>
using namespace std;
// Function to return the length of
// the longest valid substring
int solve(string s, int n)
{
 
    // Variables for left and right counter.
    // maxlength to store the maximum length found so far
    int left = 0, right = 0, maxlength = 0;
 
    // Iterating the string from left to right
    for (int i = 0; i < n; i++) 
    {
        // If "(" is encountered,
        // then left counter is incremented
        // else right counter is incremented
        if (s[i] == '(')
            left++;
        else
            right++;
 
        // Whenever left is equal to right, it signifies
        // that the subsequence is valid and
        if (left == right)
            maxlength = max(maxlength, 2 * right);
 
        // Resetting the counters when the subsequence
        // becomes invalid
        else if (right > left)
            left = right = 0;
    }
 
    left = right = 0;
 
    // Iterating the string from right to left
    for (int i = n - 1; i >= 0; i--) {
 
        // If "(" is encountered,
        // then left counter is incremented
        // else right counter is incremented
        if (s[i] == '(')
            left++;
        else
            right++;
 
        // Whenever left is equal to right, it signifies
        // that the subsequence is valid and
        if (left == right)
            maxlength = max(maxlength, 2 * left);
 
        // Resetting the counters when the subsequence
        // becomes invalid
        else if (left > right)
            left = right = 0;
    }
    return maxlength;
}
 
 
//A much shorter and concise version of the above code
int solve2(string s, int n){
    int left=0,right=0,maxlength=0,t=2;
      while(t--){
        left=0;
        right=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')left++;
            else right++;
                 
            if(left==right){
                maxlength=max(maxlength,2*left);
            }
            //when travelling from 0 to n-1    
            if(t%2==1 && right>left){
                left=0;
                right=0;
              }
              //when travelling from n-1 to 0
              if(t%2==0 && left>right){
                  left=0;
                  right=0;
              }
            }
              //now we need to do the same thing from the other side;
            reverse(s.begin(),s.end());
        }
        return maxlength;
}
 
// Function to return the length of
// the longest valid substring
int lonParen(int i, string& s, vector<int>& memo)
{
    // base condition
    if (i <= 0) {
        return 0;
    }
    // checking if value already present in the dp array
    if (memo[i] != -1) {
        return memo[i];
    }
    // check for beginning bracket
    if (s[i] == '(') {
        memo[i] = 0;
    } // check if beginning and ending brackets satisfy
    else if (s[i] == ')' && s[i - 1] == '(') {
        memo[i] = lonParen(i - 2, s, memo) + 2;
    }
    // check if the bracket at the ith position is same as
    // bracket at i-1th position
    else if (s[i] == ')' && s[i - 1] == ')') {
        int len = lonParen(i - 1, s, memo);
        if (i - 1 - len >= 0 && s[i - 1 - len] == '(') {
            memo[i]
                = len + 2 + lonParen(i - len - 2, s, memo);
        }
        else {
            // if none of the condition satisfy store 0 in
            // the dp array
            memo[i] = 0;
        }
    }
    // return the value at the last index
    return memo[i];
}
 
int longestValidParentheses(string s)
{
 
    int n = s.size(), maxLen = 0;
    // dp vector for storing the results
    vector<int> memo(n, -1);
    // getting the maximum length
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, lonParen(i, s, memo));
    }
    // return the maximum length
    return maxLen;
}
int main()
{
    cout << solve("((()()()()(((())", 16);
    cout << longestValidParentheses("((()()()()(((())");
    return 0;
}
