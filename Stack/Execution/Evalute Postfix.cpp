#include<ioatream>
#include<stack>
using namespace std;
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
    string str ="231*+9-";
    cout << postfix(str);
}
