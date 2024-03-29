#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
bool checkStackPermutation(const vector<int>& input, const vector<int>& output) {
    stack<int> s;
    int j = 0;
 
    for (int i = 0; i < input.size(); i++) {
        s.push(input[i]);
 
        while (!s.empty() && s.top() == output[j]) {
            s.pop();
            j++;
        }
    }
    if(j==output.size())
        return true;
    return false;
}
 
int main() {
    vector<int> input = {4, 5, 6, 7, 8};
    vector<int> output = {8, 7, 6, 5, 4};
 
    if (input.size() != output.size()) {
        cout << "Not Possible" << endl;
        return 0;
    }
 
    checkStackPermutation(input, output) ? cout << "Yes" << endl : cout << "Not Possible" << endl;
 
    return 0;
}
