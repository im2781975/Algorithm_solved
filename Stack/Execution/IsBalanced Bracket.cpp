#include<iostream>
#include<stack>
using namespace std;
// Function to check if brackets are balanced
bool IsBalanced(string str){
    stack <char> st;
    for(int i = 0; i < str.length(); i++){
        if(st.empty())
            st.push(str[i]);
        else{
            if((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']'))
                st.pop();
            else{
                st.push(str[i]);
            }
        }
    }
    if(st.empty())
        return true;
    return false;
}
bool IsBalanced(string str){
    int i = -1;
    for(auto &ch : str){
        if(ch == '(' || ch == '{'|| ch == '[')
            str[++i] = ch;
        else{
            if(i >= 0 && ((str[i] == '(' && ch == ')') || (str[i] == '{' && ch == '}') || (str[i]== '[' && ch == ']')))
                return true;
            return false;
        }
    }
    //If i is -1, it means all opening brackets have been matched with 
    //closing brackets, and the brackets are balanced. The function returns true.
    return i == -1;
}
int main(){
    string str = "{()}[]";
    (IsBalanced(str)) ?cout << "Yes":
    cout << "No";
}
