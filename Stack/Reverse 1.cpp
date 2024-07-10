// reverse the number using a stack
#include<iostream>
#include<stack>
using namespace std;
stack <int> st;
void PushDigit(int num){
    while(num !=0){
        st.push(num % 10);
        num /= 10;
    }
}
int Reverse(int num){
    PushDigit(num);
    int rev = 0, i = 1;
    while(!st.empty()){
        rev = rev + (st.top() * i);
        st.pop();
        i *= 10;
    }
    return rev;
}
int main(){
    int num; cin >> num;
    cout << Reverse(num);
}
