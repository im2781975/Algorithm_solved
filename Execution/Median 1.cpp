#include <bits/stdc++.h>
using namespace std;
int Solution(int arr[], int n)
{
    // If length of array is even
    if (n % 2 == 0) {
        int z = n / 2;
        int e = arr[z];
        int q = arr[z - 1];
        int ans = (e + q) / 2;
        return ans;
    }
    // If length if array is odd
    else {
        int z = round(n / 2);
        return arr[z];
    }
}
//This function returns median of ar1[] and ar2[].
int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0; 
    // Current index of input array ar1[] 
    int j = 0; 
    // Current index of input array ar2[] 
    int count;
    int m1 = -1, m2 = -1;
    // loop till (m+n)/2
    for (count = 0; count <= (m + n) / 2; count++) {
        // store (n+m)/2-1 in m2
        m2 = m1;
        if (i != n && j != m) {
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
        }
        else if (i < n) {
            m1 = ar1[i++];
        }
        // for case when j<m,
        else {
            m1 = ar2[j++];
        }
    }
    // Since there are (n+m) elements,
    // There are following two cases
    // if n+m is odd then the middle index is median i.
    // other wise median will be average of elements at index ((m+n)/2 - 1) and (m+n)/2 in the array obtained after merging ar1 and ar2
    if ((m + n) % 2 == 1)
        return m1;
    else
        return (m1 + m2) / 2;
}
int main()
{
    int arr1[] = { -5, 3, 6, 12, 15 };
    int arr2[] = { -12, -10, -6, -3, 4, 10 };
 
    int i = sizeof(arr1) / sizeof(arr1[0]);
    int j = sizeof(arr2) / sizeof(arr2[0]);
 
    cout << getMedian(arr1, arr2, i, j);
    int arr3[i + j];
    int l = i + j;
    // Merge two array into one array
    for (int k = 0; k < i; k++) {
        arr3[k] = arr1[k];
    }
    int a = 0;
    for (int k = i; k < l; k++) {
        arr3[k] = arr2[a++];
    }
    // Sort the merged array
    sort(arr3, arr3 + l);
    cout << "Median = " << Solution(arr3, l);
}

