// find median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;
// returns median of ar1[] and ar2[].
double getMedian(int ar1[], int ar2[], int n)
{
    int i = 0; 
    // Current index of i/p array ar1[] 
    int j = 0; 
    // Current index of i/p array ar2[] 
    int count;
    int m1 = -1, m2 = -1;
    //Since there are 2n elements, median will be average of elements
   // at index n-1 and n in the array obtained after merging ar1 and ar2 
    for (count = 0; count <= n; count++) {
        //Below is to handle case where all elements of ar1[] are
        // smaller than smallest(or first) element of ar2[]
        if (i == n) {
            m1 = m2;
            m2 = ar2[0];
            break;
        }
        // Below is to handle case where all elements of ar2[] are
        // smaller than smallest(or first) element of ar1[]
        else if (j == n) {
            m1 = m2;
            m2 = ar1[0];
            break;
        }
        // equals sign because if two arrays have some common elements 
        if (ar1[i] <= ar2[j]) {
            // Store the prev median 
            m1 = m2;
            m2 = ar1[i];
            i++;
        }
        else {
            // Store the prev median 
            m1 = m2;
            m2 = ar2[j];
            j++;
        }
    }
    return (1.0 * (m1 + m2)) / 2;
}
// returns median of ar1[] and ar2[].
int getMedian(int ar1[], int ar2[], int n)
{
    int j = 0;
    int i = n - 1;
    while (ar1[i] > ar2[j] && j < n && i > -1)
        swap(ar1[i--], ar2[j++]);
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);
    return (ar1[n - 1] + ar2[0]) / 2;
}
double getMedian(int arr1[], int arr2[], int n)
{
    // according to given constraints all numbers are in this range
    int low = (int)-1e9, high = (int)1e9;
 
    int pos = n;
    double ans = 0.0;
    // binary search to find the element which will be present at pos = totalLen/2 after merging two arrays in sorted order
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        // total number of elements in arrays which are less than mid
        int ub = upper_bound(arr1, arr1 + n, mid) - arr1
                 + upper_bound(arr2, arr2 + n, mid) - arr2;
 
        if (ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
 
    ans = low;
    // As there are even number of elements, we will also have to find element at pos = totalLen/2 - 1
    pos--;
    low = (int)-1e9;
    high = (int)1e9;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        int ub = upper_bound(arr1, arr1 + n, mid) - arr1
                 + upper_bound(arr2, arr2 + n, mid) - arr2;
 
        if (ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // average of two elements in case of even number of elements
    ans = (ans + low) / 2;
    return ans;
}
int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
             << " of unequal size";
    getchar();
    double median = getMedian(arr1, arr2, n);
 
    cout << "Median is " << median << endl
    return 0;
}
