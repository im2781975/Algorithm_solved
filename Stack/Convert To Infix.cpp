#include<bits/stdc++.h>
using namespace std;
bool IsOperand(char x){
    if((x >= 'a' && x <= 'z') || x >= 'A' && x <= 'Z')
        return true;
    return false;
}
string GetInfix(string str){
    stack < string> st;
    for(int i = 0; str[i]; i++){
        if(IsOperand(str[i]))
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
    string str ="ab*c+";
    cout << GetInfix(str);
}
