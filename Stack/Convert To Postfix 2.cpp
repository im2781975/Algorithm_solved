#include<iostream>
#include<stack>
using namespace std;
bool IsOperator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    return false;
}
string PrefixToPostfix(string str){
    stack < string> st;
    for(int i = str.size() -1; i >= 0; i--){
        if(IsOperator(str[i])){
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            string tmp = x + y + str[i];
            st.push(tmp);
        }
        else
            st.push(string(1, str[i]));
    }
    return st.top();
}
int main(){
    string str = "*-A/BC-/AKL";
    cout << PrefixToPostfix(str);
}
