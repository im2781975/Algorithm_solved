//N-bonacci series is a series where the 1st n numbers in the series are all 1-s and after that the i-th number is the sum of the previous n numbers in the series. 
//For example, for n = 4, the series looks like this:1,  1,  1,  1,  4,  7,  13,  25,  49,  94,  181,  349,  673, 1297 ..
//You will be given two integers n and k. You have to determine the k-th integer (1-indexed) in the N-bonacci series.
#include <iostream>
#include <vector>
using namespace std;

long long n_bonacci(int n, int k) {
    vector<long long> sequence(k);
    
    for (int i = 0; i < k; ++i) {
        if (i < n) {
            sequence[i] = 1;
        } else {
            for (int j = i - 1; j >= i - n; --j) {
                sequence[i] += sequence[j];
            }
        }
    }
    return sequence[k - 1];
}
int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    long long result = n_bonacci(n, k);
    
    cout << "The " << k << "-th number in the N-bonacci series with n = " << n << " is: " << result ;

    return 0;
}

