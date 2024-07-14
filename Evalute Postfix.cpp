#include<iostream>
#include<stack>
using namespace std;
// evaluate value of a postfix expression having multiple digit operands
int EvalutePostfix(char *str){
    stack <int> st;
    int i;
    //in loop str[i] means str[i]!=NULL
    for(i = 0; str[i]; i++){
        if(str[i] == ' ')
            continue;
        // If the scanned character is an operand (number here)
        //extract the full number Push it to the stack.
        else if(isdigit(str[i])){
            int num = 0;
            while(isdigit(str[i])){
                num = num * 10 + (int)(str[i] - '0');
                i++;
            }
            //After the loop exits, i has been incremented one extra time 
            //(pointing to a non-digit character). i-- decrements the index back to the last digit character.
            i--;
            st.push(num);
        } else {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            switch(str[i]){
                case '+':
                     st.push(x + y);
                     break;
                case '-':
                    st.push(y - x);
                    break;
                case '*':
                    st.push(x * y);
                    break;
                case '/':
                    st.push(y / x);
                    break;
            }
        }
    }
    return st.top();
}
// evaluate value of a postfix expression
int postfix(string str){
    stack<char>st;
    for(int i = 0; i < str.length(); i++){
        if(isdigit(str[i]))
            st.push(str[i] - '0');
        else{
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            switch(str[i]){
                case '+':
                    st.push(x + y);
                    break;
                case '-':
                    st.push(y - x);
                    break;
                case '*':
                    st.push(x * y);
                    break;
                case '/':
                    st.push(y / x);
                    break;
            }
        }
    }
    return st.top();
}
int main(){
    char str[] = "100 200 + 2 / 5 * 7 +";
    cout << EvalutePostfix(str);
    string st ="231*+9-";
    cout << postfix(st);
}
