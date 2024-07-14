#include<iostream>
#include<stack>
using namespace std;
void InsertBottom(stack <int> &st, int x){
    if(st.size() == 0)
        st.push(x);
    else{
        int p = st.top();
        st.pop();
        InsertBottom(st, x);
        st.push(p);
    }
}
void Reverse(stack <int> &st){
    if(st.size() > 0){
        int x = st.top();
        st.pop();
        Reverse(st);
        InsertBottom(st, x);
    }
}
// reverse the number using a stack
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
    stack <int> a, b;
    for(int i = 1; i <= 4; i++)
        a.push(i);
    b = a;
    while(!b.empty()){
        cout << b.top() << " ";
        b.pop();
    }
    Reverse(a);
    cout << "\n";
    while(!a.empty()){
        cout << a.top() <<  " ";
        a.pop();
    }
    //****//
    int num; cin >> num;
    cout << Reverse(num);
}

