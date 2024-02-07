#include <bits/stdc++.h>
using namespace std;
double Median(vector<int>& A, vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return Median(B, A); 
        // Swapping to make A smaller
 
    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? A[leftAsize - 1]
                  : INT_MIN; 
                  // checking overflow of indices
        int leftB
            = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? B[leftBsize] : INT_MAX;
 
        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0.0;
}
double Median(vector<int>& A, vector<int>& B)
{
    int i;
    int n = A.size();
    int m = B.size();
    // initializing Priority Queue (Min Heap)
    priority_queue<int, vector<int>, greater<int> > pq;
    // pushing array A values to priority Queue
    for (i = 0; i < n; i++)
        pq.push(A[i]);
    // pushing array B values to priority Queue
    for (i = 0; i < m; i++)
        pq.push(B[i]);
    int check = n + m;
    double count = -1;
    double mid1, mid2;
    while (!pq.empty()) {
        count++;
        // returning mid value if combined length(n+m) is odd
        if (check % 2 != 0 && count == check / 2) {
            double ans = pq.top();
            return ans;
        }
        // maintaining mid1 value if combined length(n+m) is
        // even where we need to maintain both mid values in
        // case of even combined length
        if (check % 2 == 0 && count == (check / 2) - 1)
            mid1 = pq.top();
        // now returning the mid2 value with previous maintained mid1 value by 2
        if (check % 2 == 0 && count == check / 2) {
            mid2 = pq.top();
            double ans = (mid1 + mid2) / 2;
            return ans;
        }
        pq.pop();
    }
    return 0.00000;
}
int main()
{
    vector<int> arr1 = { -5, 3, 6, 12, 15 };
    vector<int> arr2 = { -12, -10, -6, -3, 4, 10 };
    cout << "Median of the two arrays are" << endl;
    cout << Median(arr1, arr2);
    return 0;
}
