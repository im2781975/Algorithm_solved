#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> st;
    for(int i = 21; i <= 30; i++)
        st.push(i);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
