// check if a queue of first n natural number can be sorted using a stack
#include<bits/stdc++.h>
using namespace std;
bool CheckSorted(int n, queue <int> &q){
    stack <int> st;
    int expect = 1;
    int first;
    while(!q.empty()){
        first = q.front();
        q.pop();
        if(first == expect)
            expect++;
        else {
            if(st.empty())
                st.push(first);
            // if top element is less than element which need to be pushed, then return false.
            else if(!st.empty() && st.top() < first)
                return false;
            else
                st.push(first);
        }
        //while expected element are coming from stack, pop them out
        while(!st.empty() && st.top() == expect){
            st.pop();
            expect++;
        }
    }
    // while expected element are coming from stack, pop them out.
    if(expect - 1 == n && st.empty())
        return true;
    return false;
}
int main(){
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int n = q.size();
    (CheckSorted(n, q) ? (cout << "Yes") :(cout << "No"));
}
