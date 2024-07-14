#include<iostream>
#include <stack>
#include<algorithm>
using namespace std;
bool IsOperator(char ch){
    return (!isalpha(ch) && !isdigit(ch));
}
int prec(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    return 0;
}
string InfixToPostfix(string str) {
    stack<char> st;
    string final;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i]) || isdigit(str[i])) {
            final += str[i];
        } else if (str[i] == '(') {
            st.push(str[i]);
        } else if (str[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                final += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        } else {
            while (!st.empty() && prec(st.top()) >= prec(str[i])) {
                final += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty()) {
        final += st.top();
        st.pop();
    }
    return final;
}
string InfixToPrefix(string str){
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }
        string prefix = InfixToPostfix(str);
        reverse(prefix.begin(), prefix.end());
        return prefix;
}
int main(){
    string str =("x+y*z/w+u");
    cout << InfixToPrefix(str);
}
