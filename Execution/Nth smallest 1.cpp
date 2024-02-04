#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int i,j,n=matrix.size();
   
    //using built-in priority queue which acts as max Heap i.e. largest element will be on top
    //Kth smallest element can also be seen as largest element in a priority queue of size k
    //By this logic we pop elements from priority queue when its size becomes greater than k
    //thus top of priority queue is kth smallest element in matrix
    priority_queue<int> maxH;
    if(k==1)
        return matrix[0][0];
   
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            maxH.push(matrix[i][j]);
            if(maxH.size()>k)
                maxH.pop();
        }
    }
    return maxH.top();
}
int main() {
 
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
      int k = 8;
    cout << "8th smallest element is " << kthSmallest(matrix,k);
    return 0;
}
