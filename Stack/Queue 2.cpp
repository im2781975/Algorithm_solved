// implement a stack using two queue
#include <iostream>
#include <queue>
using namespace std;
class Stack{
    queue <int > a, b;
    public:
    void pop(){
        if(a.empty())
            return;
        if(a.size() !=1){
            b.push(a.front());
            a.pop();
        }
        // Pop the only left element from a
        a.pop();
        queue <int> q = a;
        a = b; b = q;
    }
    void push(int x){
        a.push(x);
    }
    int top(){
        if(a.empty())
            return -1;
        if(a.size() !=1){
            b.push(a.front());
            a.pop();
        }
        int tmp = a.front();
        a.pop();
        b.push(tmp);
        queue <int> q = a;
        a = b; b = q;
        return tmp;
    }
};
int main(){
    Stack st;
    for(int i = 1; i <= 5; i++){
        st.push(i);
        cout << st.top() << " ";
        st.pop();
    }
}
