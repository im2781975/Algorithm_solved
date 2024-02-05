// find 3 elements such that max(abs(A[i]-B[j]), abs(B[j]-C[k]), abs(C[k]-A[i])) is minimized
#include<bits/stdc++.h>
using namespace std;
 
void findClosest(int A[], int B[], int C[], int p, int q, int r)
{
    //Three variable to store answer
    int a,b,c;
    //To Store minimum of max(abs(A[i]-B[j]),abs(B[j]-C[k]),abs(C[k]-A[i]))
    int ans=INT_MAX;
    //Run three nested loop
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            for(int k=0;k<r;k++){
                int curr=max(abs(A[i]-B[j]),abs(B[j]-C[k]));
                int temp=max(curr,abs(C[k]-A[i]));
                //If that is minimum than previous then update answer
                if(temp<ans){
                    ans=temp;
                    a=A[i];
                    b=B[j];
                    c=C[k];
                }
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
}
void findClosest(int A[], int B[], int C[], int p, int q, int r)
{
 
    int diff = INT_MAX;  
    // Initialize min diff
    // Initialize result
    int res_i =0, res_j = 0, res_k = 0;
 
    // Traverse arrays
    int i=0,j=0,k=0;
    while (i < p && j < q && k < r)
    {
        // Find minimum and maximum of current three elements
        int minimum = min(A[i], min(B[j], C[k]));
        int maximum = max(A[i], max(B[j], C[k]));
 
        // Update result if current diff is less than the min diff so far
        if (maximum-minimum < diff)
        {
             res_i = i, res_j = j, res_k = k;
             diff = maximum - minimum;
        }
        // We can't get less than 0 as values are absolute
        if (diff == 0) break;
        // Increment index of array with smallest value
        if (A[i] == minimum) i++;
        else if (B[j] == minimum) j++;
        else k++;
    }
    cout << A[res_i] << " " << B[res_j] << " " << C[res_k];
}
void findClosest(int A[], int B[], int C[], int p, int q, int r)
{
 
    sort(A, A+p);
    sort(B, B+q);
    sort(C, C+r);
 
    int diff = INT_MAX;
    // Initialize min diff
    // Initialize result
    int res_i =0, res_j = 0, res_k = 0;
    // Traverse arrays
    int i=0,j=0,k=0;
    while (i < p && j < q && k < r)
    {
        // Find minimum and maximum of current three elements
        int minimum = min(A[i], min(B[j], C[k]));
        int maximum = max(A[i], max(B[j], C[k]));
 
        // Calculate the maximum difference for the current combination
        int curDiff = abs(maximum - minimum);
 
        // Update result if current diff is less than the min diff so far
        if (curDiff < diff)
        {
            res_i = i, res_j = j, res_k = k;
            diff = curDiff;
        }
        // If the maximum element of A is the smallest among the three,
        // we move the A pointer forward
        if (A[i] == minimum && A[i] <= B[j] && A[i] <= C[k]) i++;
 
        // If the maximum element of B is the smallest among the three, we move the B pointer forward
        else if (B[j] == minimum && B[j] <= A[i] && B[j] <= C[k]) j++;
 
        // If the maximum element of C is the smallest among the three, we move the C pointer forward
        else k++;
    }
    cout << A[res_i] << " " << B[res_j] << " " << C[res_k];
}
int main()
{
    int A[] = {1, 4, 10};
    int B[] = {2, 15, 20};
    int C[] = {10, 12};
 
    int p = sizeof A / sizeof A[0];
    int q = sizeof B / sizeof B[0];
    int r = sizeof C / sizeof C[0];
 
    findClosest(A, B, C, p, q, r);
    return 0;
}
