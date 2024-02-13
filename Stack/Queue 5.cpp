// implement a stack using one queue and recursion
#include <bits/stdc++.h>
using namespace std;
// Stack Class that acts as a queue
class Stack {
    queue<int> q;
    public:
    void push(int data, int c);
    void pop();
    int top();
    int size();
    bool empty();
};
void Stack::push(int data, int c)
{
    // Push the current element first & After every recursion add the front element again
    q.push(data);
    // Return if size becomes 0
    if (c <= 0)
        return;
    // Store current front
    int x = q.front();
    // Delete front element
    q.pop();
    // Decrement size by 1 in every recursion
    c--;
    Stack::push(x, c);
}
// Removes the top element
void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}
// Returns top of stack
int Stack::top() { return (q.empty()) ? -1 : q.front(); }
// Returns true if Stack is empty else false
bool Stack::empty() { return (q.empty()); }
int Stack::size() { return q.size(); }
int main()
{
    Stack st;
    st.push(1, st.size()); 
        // Value and size
    st.push(2, st.size());
    st.push(3, st.size());
    cout << "current size: " << st.size() << "\n";
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    cout << "current size: " << st.size();
    return 0;
}
