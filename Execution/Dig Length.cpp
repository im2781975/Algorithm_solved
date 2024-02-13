// find length of the longest valid substring
#include <bits/stdc++.h>
using namespace std;
int findMaxLen(string str)
{
    int n = str.length();
    // Create a stack and push -1 as initial index to it.
    stack<int> stk;
    stk.push(-1);
    // Initialize result
    int result = 0;
    // Traverse all characters of given string
    for (int i = 0; i < n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
        // If closing bracket, i.e.,str[i] = ')'
        else
        {
            // Pop the previous opening bracket's index
            if (!stk.empty()) 
                stk.pop();
             
            // Check if this length formed with base of current valid substring is more than max so far
            if (!stk.empty())
                result = max(result, i - stk.top());
            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else
                stk.push(i);
        }
    }
    return result;
}
int findMaxLen(string s)
{
    if (s.length() <= 1)
        return 0;
 
    // Initialize curMax to zero
    int curMax = 0;
 
    vector<int> longest(s.size(), 0);
 
    // Iterate over the string starting from second index
    for (int i = 1; i < s.length(); i++) 
    {
        if (s[i] == ')' && i - longest[i - 1] - 1 >= 0
            && s[i - longest[i - 1] - 1] == '(') 
        {
            longest[i]
                = longest[i - 1] + 2
                  + ((i - longest[i - 1] - 2 >= 0)
                  ? longest[i - longest[i - 1] - 2]
                  : 0);
            curMax = max(longest[i], curMax);
        }
    }
    return curMax;
}
int main()
{
    string str = "((()()";
    cout << findMaxLen(str) << endl;
    str = "()(()))))";
    cout << findMaxLen(str) << endl;
    return 0;
}
