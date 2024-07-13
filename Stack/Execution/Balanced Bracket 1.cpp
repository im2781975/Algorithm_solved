#include<iostream>
using namespace std;
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

