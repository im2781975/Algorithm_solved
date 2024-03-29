// simplify algebraic string
#include <bits/stdc++.h>
using namespace std;
// Function to simplify the string
char* simplify(string str)
{
    int len = str.length();
    // resultant string of max length equal to length of input string
    char* res = new char(len);
    int index = 0, i = 0;
 
    // create empty stack
    stack<int> s;
    s.push(0);
    while (i < len) {
          // Don't do any operation
        if(str[i] == '(' && i == 0) {
            i++;
              continue;
        }
        if (str[i] == '+') {
            // If top is 1, flip the operator
            if (s.top() == 1)
                res[index++] = '-';
 
            // If top is 0, append the same operator
            if (s.top() == 0)
                res[index++] = '+';
 
        } else if (str[i] == '-') {
            if (s.top() == 1) {
                  if(res[index-1] == '+' || res[index-1] == '-') res[index-1] = '+'; // Overriding previous sign 
                else res[index++] = '+';
            }
            else if (s.top() == 0) {
                  if(res[index-1] == '+' || res[index-1] == '-') res[index-1] = '-'; // Overriding previous sign
                else res[index++] = '-'; 
            }
        } else if (str[i] == '(' && i > 0) {
            if (str[i - 1] == '-') {
 
                // x is opposite to the top of stack
                int x = (s.top() == 1) ? 0 : 1;
                s.push(x);
            }
            // push value equal to top of the stack
            else if (str[i - 1] == '+')
                s.push(s.top());
        }
        // If closing parentheses pop the stack once
        else if (str[i] == ')')
            s.pop();
        // copy the character to the result
        else
            res[index++] = str[i];
        i++;
    }
    return res;
}
int main()
{
    string s1 = "(a-(b+c)+d)";
    string s2 = "a-(b-c-(d+e))-f";
    cout << simplify(s1) << endl;
    cout << simplify(s2) << endl;
    return 0;
}
