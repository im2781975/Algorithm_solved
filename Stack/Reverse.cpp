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
}
