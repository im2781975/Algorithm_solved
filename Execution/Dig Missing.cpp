#include <bits/stdc++.h>
using namespace std;
void findMissing(int arr[], int N)
{
    int i;
    int temp[N + 1];
    for(int i = 0; i <= N; i++){
      temp[i] = 0;
    }
   
    for(i = 0; i < N; i++){
      temp[arr[i] - 1] = 1;
    }
    int ans;
    for (i = 0; i <= N ; i++) {
        if (temp[i] == 0)
            ans = i  + 1;
    }
    cout << ans;
}
// Function to get the missing number
int getMissingNo(int a[], int n)
{
    // Given the range of elements are 1 more than the size of array
    int N = n + 1;
   
    int total = (N) * (N + 1) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}
// Function to get the missing element
int getMissingNo(int a[], int n)
{
    int i, total = 1;
 
    for (i = 2; i < (n + 1); i++) {
        total += i;
        total -= a[i - 2];
    }
    return total;
}
int getMissingNo(int a[], int n)
{
    // For xor of all the elements in array
    int x1 = a[0];
 
    // For xor of all the elements from 1 to n+1
    int x2 = 1;
 
    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];
 
    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;
 
    return (x1 ^ x2);
}
int getMissingNo(int a[], int n)
{
    int i = 0;
    while (i < n) {
        int correct = a[i] - 1;
        if (a[i] < n && a[i] != a[correct]) {
            swap(a[i], a[correct]);
        }
        else {
            i++;
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (i != a[i] - 1) {
            return i + 1;
        }
    }
 
    return n;
}
void findMissing(int arr[], int size)
{
    int i;
   
    for (i = 0; i < size; i++) {
        if(abs(arr[i]) - 1 == size){
          continue;
        }
        int ind = abs(arr[i]) - 1;
        arr[ind] *= -1;
    }
 
 
    int ans = size + 1;
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            ans = i  + 1;
    }
    cout << ans;
}
int main()
{
    int arr[] = { 1, 3, 7, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMissing(arr, n);
    cout << getMissingNo(arr, n);
    cout << getMissingNo(arr, n);
    cout << getMissingNo(arr, n);
    cout << getMissingNo(arr, n);
    findMissing(arr, n);
}
