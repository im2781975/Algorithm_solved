// calculate stock span values
#include <bits/stdc++.h>
using namespace std;
// Fills array S[] with span values
void calculateSpan(int price[], int n, int S[])
{
    // Span value of first day is always 1
    S[0] = 1;
    // Calculate span value of remaining day by linearly checking previous days
    for (int i = 1; i < n; i++) {
        S[i] = 1; 
        // Initialize span value
        // Traverse left while the next element on left is smaller than price[i]
        for (int j = i - 1;
             (j >= 0) && (price[i] >= price[j]); j--)
            S[i]++;
    }
}
// A stack based efficient method to calculate stock span values
void calculateSpan(int price[], int n, int S[])
{
    // Create a stack and push index of first element to it
    stack<int> st;
    st.push(0);
    // Span value of first element is always 1
    S[0] = 1;
    // Calculate span values for rest of the elements
    for (int i = 1; i < n; i++) {
        // Pop elements from stack while stack is not empty and top of stack is smaller than price[i]
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
        // If stack becomes empty, then price[i] is greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else price[i] is greater than elements after top of stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
 
        // Push this element to stack
        st.push(i);
    }
}
// calculate stock span values implementing the same idea without using stack
void calculateSpan(int A[], int n, int ans[])
{
    // Span value of first element is always 1
    ans[0] = 1;
    // Calculate span values for rest of the elements
    for (int i = 1; i < n; i++) {
        int counter = 1;
        while ((i - counter) >= 0
               && A[i] >= A[i - counter]) {
            counter += ans[i - counter];
        }
        ans[i] = counter;
    }
}
vector<int> calculateSpan(int arr[], int n)
{
    // Your code here
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while (!s.empty() and arr[s.top()] <= arr[i])
            s.pop();
 
        if (s.empty())
            ans.push_back(i + 1);
        else {
            int top = s.top();
            ans.push_back(i - top);
        }
        s.push(i);
    }
 
    return ans;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
int main()
{
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];
 
    // Fill the span values in array S[]
    calculateSpan(price, n, S);
 
    // print the calculated span values
    printArray(S, n);
    vector<int> arr = calculateSpan(price, n);
    printArray(arr);
    return 0;
}
