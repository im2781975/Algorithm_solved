// implement Queue using two stacks with costly deQueue()
#include <bits/stdc++.h>
using namespace std;
struct Queue {
    stack<int> s1, s2;
    // Enqueue an item to the queue
    void enQueue(int x)
    {
        s1.push(x);
    }
    // Dequeue an item from the queue
    int deQueue()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty())
            return -1;
        // if s2 is empty, move elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // return the top item from s2
        int x = s2.top();
        s2.pop();
        return x;
    }
};
int main()
{
    Queue q;
    cout << q.deQueue() << '\n';
    q.enQueue(1);
    cout << q.deQueue() << '\n';
    return 0;
}
