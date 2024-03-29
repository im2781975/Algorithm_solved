#include <iostream>
#include <queue>
using namespace std;
int kthSmallest(int arr[], int N, int K)
{
    // Create a max heap (priority queue)
    priority_queue<int> pq;
    // Iterate through the array elements
    for (int i = 0; i < N; i++) {
        // Push the current element onto the max heap
        pq.push(arr[i]);
 
        // If the size of the max heap exceeds K, remove the largest element
        if (pq.size() > K)
            pq.pop();
    }
    // Return the Kth smallest element (top of the max heap)
    return pq.top();
}
int kthSmallest(int arr[][4], int n, int k)
{
    // Create a min-heap (priority queue) to store elements in sorted order
    priority_queue<int, vector<int>, greater<int> > pq;
    // Add all elements of the 2D array to the min-heap
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pq.push(arr[i][j]);
        }
    }
    int c = 0;
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        c++;
 
        if (c == k)
            return temp;
    }
    // If kth smallest element not found, return -1
    return -1;
}
int kthSmallest(int mat[4][4], int n, int k)
{
 
    int a[n*n];
    int v = 0;
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[v] = mat[i][j];
            v++;
        }
    } 
    sort(a, a + (n*n));
    int result = a[k - 1];
    return result;
}
// kth largest element in a 2d array sorted row-wise & column-wise
int kthSmallest(int mat[4][4], int n, int k)
{
    // USING LAMBDA FUNCTION
    // [=] IN LAMBDA FUNCTION IS FOR CAPTURING VARIABLES WHICH 
    // ARE OUT OF SCOPE i.e. mat[r]
    // NOW, IT'LL COMPARE ELEMENTS OF HEAP BY ELEMENTS AT mat[first][second]
      // Capturing the value of mat by reference to prevent copying
    auto cmp = [&](pair<int,int> a,pair<int,int> b){
        return mat[a.first][a.second] > mat[b.first][b.second];
    };
    //DECLARING priority_queue AND PUSHING FIRST ROW IN IT
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i=0; i<n; i++){
        pq.push({i,0});
    }
    for(int i=1; i<k; i++){
        auto p = pq.top();
        pq.pop();
        //AFTER POPPING, WE'LL PUSH NEXT ELEMENT OF THE ROW IN THE HEAP
        if(p.second+1 < n) pq.push({p.first,p.second + 1});
    }
    // ON THE k'th ITERATION, pq.top() will be our answer.
    return mat[pq.top().first][pq.top().second];
}
// returns count of elements in matrix less than of equal to num
int getElementsGreaterThanOrEqual(int num, int n, int mat[4][4]) {
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        // if num is less than the first element then no more element in matrix further are less than or equal to num
        if (mat[i][0] > num) {
            return ans;
        }
        // if num is greater than last element, it is greater than all elements in that row
        if (mat[i][n - 1] <= num) {
            ans += n;
            continue;
        }
        // This contain the col index of last element in matrix less than of equal to num
        int greaterThan = 0;
        for (int jump = n / 2; jump >= 1; jump /= 2) {
            while (greaterThan + jump < n &&
                   mat[i][greaterThan + jump] <= num) {
                greaterThan += jump;
            }
        }
        ans += greaterThan + 1;
    }
    return ans;
}
// returns kth smallest index in the matrix
int kthSmallest(int mat[4][4], int n, int k) {
    //  We know the answer lies between the first and the last element So do a binary search on answer based on the number of elements
    // our current element is greater than the elements in the matrix
    int l = mat[0][0], r = mat[n - 1][n - 1];
 
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);
 
        if (greaterThanOrEqualMid >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
// A structure to store entry of heap. The entry contains value from 2D array, row and column numbers of the value
struct HeapNode {
    int val;
    // value to be stored
    int r; 
    // Row number of value in 2D array
    int c; 
    // Column number of value in 2D array
};
// function to minheapify the node harr[i] of a heap stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
     if(l < heap_size&& r<heap_size && harr[l].val < harr[i].val && harr[r].val < harr[i].val){
            HeapNode temp=harr[r];
            harr[r]=harr[i];
            harr[i]=harr[l];
            harr[l]=temp;
            minHeapify(harr ,l,heap_size);
            minHeapify(harr ,r,heap_size);
        }
          if (l < heap_size && harr[l].val < harr[i].val){
            HeapNode temp=harr[i];            
            harr[i]=harr[l];
            harr[l]=temp;
            minHeapify(harr ,l,heap_size);
        }
}
// kth largest element in a 2d array sorted row-wise & column-wise
// This function returns kth smallest element in a 2D array mat[][]
int kthSmallest(int mat[4][4], int n, int k)
{
    // k must be greater than 0 and smaller than n*n
    if (k < 0 || k >= n * n)
        return INT_MAX;
    // Create a min heap of elements from first row of 2D array
    HeapNode harr[n];
    for (int i = 0; i < n; i++)
        harr[i] = { mat[0][i], 0, i };
 
    HeapNode hr;
    for (int i = 0; i < k; i++) {
        // Get current heap root
        hr = harr[0];
 
        // Get next value from column of root's value. If
        // the value stored at root was last value in its column, then assign INFINITE as next value
        int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c]: INT_MAX;
 
        // Update heap root with next value
        harr[0] = { nextval, (hr.r) + 1, hr.c };
        // Heapify root
        minHeapify(harr, 0, n);
    }
    // Return the value at last extracted root
    return hr.val;
}
int main()
{
    int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 25, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
 
    int res = kthSmallest(mat, 4, 7);
 
    cout << "7th smallest element is " << res << endl;
    cout << "7th smallest element is "
        << kthSmallest(mat, 4, 7);
    cout << "7th smallest element is "
        << kthSmallest(arr, 4, 7);
    return 0;
}
