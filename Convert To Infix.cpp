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
bool isOperand(char x){
    if((x >= 'a' && x <= 'z') || x >= 'A' && x <= 'Z')
        return true;
    return false;
}
string PostfixToInfix(string str){
    stack < string> st;
    for(int i = 0; str[i]; i++){
        if(isOperand(str[i]))
            // creates a string from the single character str[i] 
            //this string is then pushed onto the stack st
            st.push(string(1, str[i]));
        else{
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push("(" + y + str[i] + x + ")");
        }
    }
    return st.top();
}
int main(){
    string st = "*-A/BC-/AKL";
    cout << PrefixToInfix(st);
    
    string str ="ab*c+";
    cout << "\n" << PostfixToInfix(str);
}
