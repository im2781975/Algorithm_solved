// CPP code to answer the query in constant time
#include <bits/stdc++.h>
using namespace std;
 
/*
BOP[] stands for "Balanced open parentheses" 
BCP[] stands for "Balanced close parentheses"
 
*/
 
// function for precomputation
void constructBalanceArray(int BOP[], int BCP[],
                          char* str, int n)
{
 
    // Create a stack and push -1 as initial index to it.
    stack<int> stk;
 
    // Initialize result
    int result = 0;
 
    // Traverse all characters of given string
    for (int i = 0; i < n; i++) {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
 
        else // If closing bracket, i.e., str[i] = ')'
        {
            // If closing bracket, i.e., str[i] = ')'
            // && stack is not empty then mark both
            // "open & close" bracket indexes as 1 .
            // Pop the previous opening bracket's index
            if (!stk.empty()) {
                BCP[i] = 1;
                BOP[stk.top()] = 1;
                stk.pop();
            }
 
            // If stack is empty.
            else
                BCP[i] = 0;
        }
    }
 
    for (int i = 1; i < n; i++) {
        BCP[i] += BCP[i - 1];
        BOP[i] += BOP[i - 1];
    }
}
 
// Function return output of each query in O(1)
int query(int BOP[], int BCP[],
          int s, int e)
{
    if (BOP[s - 1] == BOP[s]) {
        return (BCP[e] - BOP[s]) * 2;
    }
 
    else {
        return (BCP[e] - BOP[s] + 1) * 2;
    }
}
 
// Driver program to test above function
int main()
{
 
    char str[] = "())(())(())(";
    int n = strlen(str);
 
    int BCP[n + 1] = { 0 };
    int BOP[n + 1] = { 0 };
 
    constructBalanceArray(BOP, BCP, str, n);
 
    int startIndex = 5, endIndex = 11;
 
    cout << "Maximum Length Correct Bracket"
            " Subsequence between "
         << startIndex << " and " << endIndex << " = "
         << query(BOP, BCP, startIndex, endIndex) << endl;
 
    startIndex = 4, endIndex = 5;
    cout << "Maximum Length Correct Bracket"
            " Subsequence between "
         << startIndex << " and " << endIndex << " = "
         << query(BOP, BCP, startIndex, endIndex) << endl;
 
    startIndex = 1, endIndex = 5;
    cout << "Maximum Length Correct Bracket"
            " Subsequence between "
         << startIndex << " and " << endIndex << " = "
         << query(BOP, BCP, startIndex, endIndex) << endl;
 
    return 0;
}
