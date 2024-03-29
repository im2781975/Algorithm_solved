// print next greater number of Q queries
#include <bits/stdc++.h>
using namespace std;
// array to store the next greater element index
void next_greatest(int next[], int a[], int n)
{
    stack<int> s;
    // push the 0th index to the stack
    s.push(0);
    // traverse in the loop from 1-nth index
    for (int i = 1; i < n; i++)
    {
        // iterate till loop is empty
        while (!s.empty()) {
            // get the topmost  index in the stack
            int cur = s.top();
            // if the current element is   greater than the top indexth 
            // element, then this will be the next greatest index of the top indexth element
            if (a[cur] < a[i])
            {
                // initialise the cur index position's next greatest as index
                next[cur] = i;
                // pop the cur index as its greater element has been found
                s.pop();
            }
            // if not greater then break
            else
                break;
        }
        // push the i index so that its next greatest can be found
        s.push(i);
    }
    // iterate for all other index left inside stack
    while (!s.empty()) 
    {
        int cur = s.top();
        // mark it as -1 as no  element in greater then it in right
        next[cur] = -1;
        s.pop();
    }
}
int answer_query(int a[], int next[],int n, int index)
{
    // stores the next greater element positions
    int position = next[index];
    // if position is -1 then no  greater element is at right.
    if (position == -1)
        return -1;
    // if there is a index that has greater element  at right then return its value as a[position]
    else
        return a[position];
}
int main()
{
    int a[] = {3, 4, 2, 7, 5, 8, 10, 6 };
    int n = sizeof(a) / sizeof(a[0]);
    int next[n] = { 0 };
    // calls the function to pre-calculate the next greatest element indexes
    next_greatest(next, a, n);
    // query 1 answered
    cout << answer_query(a, next, n, 3) << " ";
    // query 2 answered
    cout << answer_query(a, next, n, 6) << " ";
    // query 3 answered
    cout << answer_query(a, next, n, 1) << " ";
}
