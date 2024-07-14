#include<iostream>
#include<stack>
using namespace std;
bool IsOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
        return true;
    return false;
}
string PrefixToInfix(string str){
    stack <string> st;
    for(int i = str.size() -1; i >= 0; i--){
        if(IsOperator(str[i])){
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            //concat the operands and operator
            string tmp = "(" + x + str[i] + y + ")";
            st.push(tmp);
        }
        else
            //Convert the character to a string and push it onto the stack.
             //first arg(1) specifies the number of times to copy the char.second arg (str[i]) is the character to be copied
            st.push(string(1, str[i]));
    }
    return st.top();
}
int main(){
    string str = "*-A/BC-/AKL";
    cout << PrefixToInfix(str);
}
