// implement Queue using one stack and recursive call stack.
stack follows LIFO.but queue follows FIFO.convert stack to queue
#include <bits/stdc++.h>
using namespace std;
struct Queue {
    stack<int> s;
    void enQueue(int x)
    {
        s.push(x);
    }
    // Dequeue an item from the queue
    int deQueue()
    {
        if (s.empty())
            return -1;
        // pop an item from the stack
        int x = s.top();
        s.pop();
        // if stack becomes empty, return the popped item
        if (s.empty())
            return x;
        // recursive call
        int item = deQueue();
        // push popped item back to the stack
        s.push(x);
        // return the result of deQueue() call
        return item;
    }
};
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    return 0;
}
