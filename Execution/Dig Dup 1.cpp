#include <iostream>
#include <vector>
using namespace std;
int x, y;
// Function to find the repeating and missing elements in an array
void getTwoElements(vector<int>& arr, int n)
{
    int xor1 = 0; 
    // Will hold xor of all elements and numbers from 1 to n
    int set_bit_no; 
    // Will have only a single set bit of xor1
    x = 0;
    y = 0;
    xor1 = arr[0];
    // Get the xor of all array elements
    for (int i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
    // XOR the previous result with numbers from 1 to n
    for (int i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
    // Get the rightmost set bit in set_bit_no
    set_bit_no = xor1 & ~(xor1 - 1);
 
    // Divide elements into two sets by comparing rightmost set bit of xor1 with bit at the same position in each
    // element. Also, get XORs of two sets. The two XORs are the output elements.
    for (int i = 0; i < n; i++) {
        if ((arr[i] & set_bit_no) != 0)
            x = x ^ arr[i];
                // arr[i] belongs to the first set
        else
            y = y ^ arr[i]; 
            // arr[i] belongs to the second set
    }
    for (int i = 1; i <= n; i++) {
        if ((i & set_bit_no) != 0)
            x = x ^ i; 
            // i belongs to the first set
        else
            y = y ^ i;
            // i belongs to the second set
    }
    // *x and *y hold the desired output elements
}
int main()
{
    vector<int> arr = { 1, 3, 4, 5, 1, 6, 2 };
    int n = arr.size();
    getTwoElements(arr, n);
    cout << "The missing element is " << x << " and the repeating number is " << y << endl;
    return 0;
}
