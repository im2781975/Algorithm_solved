#include<bits/stdc++.h>
using namespace std;
// Function to return precedence of operators
int prec(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '/' || ch == '*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
void InfixToPostfix(string str){
    stack <char> st;
    string result;
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <= '9'))
            result += ch;
        else if(ch == '(')
            st.push(ch);
        else if(ch == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        // If an operator is scanned
        else{
            while(!st.empty() && prec(str[i]) <= prec(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    // Pop all the remaining elements from the stack
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << result;
}
int main(){
    string str ="a+b*(c^d-e)^(f+g*h)-i";
    InfixToPostfix(str);
}
