// evaluate value of a postfix expression having multiple digit operands
#include <bits/stdc++.h>
using namespace std;
// returns value of a given postfix expression
int evaluatePostfix(char* exp)
{
    // Create a stack of capacity equal to expression size
    stack<int> st;
    int i;
    // Scan all characters one by one
    for (i = 0; exp[i]; ++i){
        // If the character is blank space then continue
        if (exp[i] == ' ')
            continue;
        // If the scanned character is an operand (number here),extract the full number
        // Push it to the stack.
        else if (isdigit(exp[i])) {
            int num = 0;
            // Extract full number
            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            After the loop exits, i has been incremented one extra time (pointing to a non-digit character). i-- decrements the index back to the last digit character.
            i--;
            // Push the element in the stack
            st.push(num);
        }
        // If the scanned character is an operator, pop two elements from stack apply the operator
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
 
            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    char exp[] = "100 200 + 2 / 5 * 7 +";
    cout << evaluatePostfix(exp);
    return 0;
}
