//You are given two integer numbers, n and x. You may perform several operations with the integer x
//Each operation you perform is the following one: choose any digit y that occurs in the decimal representation of x at least once, and replace x by x⋅y
//You want to make the length of decimal representation of x(without leading zeroes) equal to n.What is the minimum number of operations required to do that?
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    string x_str = to_string(x); // Convert x to a string to work with digits.
    int operations = 0;

    while (x_str.length() < n) {
        char digit_to_multiply = x_str[0]; // Choose the first digit.
        x_str = x_str.substr(1); // Remove the first digit.
        x *= (digit_to_multiply - '0'); // Convert char to int and multiply.
        x_str = to_string(x) + x_str; // Update the string representation.
        operations++;
    }
    cout << operations ;
    return 0;
}
