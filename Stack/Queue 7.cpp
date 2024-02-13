#include <bits/stdc++.h>
using namespace std;
class Stack {
    // Indices to keep track of the front, rear and size of the queue
    int front, rear, size;
    // Maximum capacity of the queue
    unsigned capacity;
    // Pointer to the array used to store the elements
    int* arr;
    public:
    Stack(unsigned capacity)
    {
        this->capacity = capacity;
        // Initially, front index and size are set to 0
        front = size = 0;
        // Rear index is set to the last index of the array
        rear = capacity - 1;
        // Dynamic allocation of memory for the array
        arr = new int[this->capacity];
    }
    bool isFull()
    {
        // If size is equal to the capacity, the queue is full
        return (size == capacity);
    }
    bool isEmpty()
    {
        // If size is 0, the queue is empty
        return (size == 0);
    }
    void push(int x)
    {
        if (isFull())
            // If the queue is full, return without adding the element
            return;
        // Increase the rear index by 1 (with wraparound)
        rear = (rear + 1) % capacity;
        // Add the element to the rear position
        arr[rear] = x;
        // Increase the size of the queue by 1
        size++;
    }
    void pop()
    {
        if (isEmpty())
            return;
            // If the queue is empty, return without doing anything
        // Increase the front index by 1 (with wraparound)
        front = (front + 1) % capacity;
        // Decrease the size of the queue by 1
        size--;
    }
    int top()
    {
        if (isEmpty())
            // If the queue is empty, return -1
            return -1;
        // Return the element at the front position
        return arr[front];
    }
    int getSize()
    {
        // Return the current size of the queue
        return size;
    }
};
int main()
{
    // Create a stack of maximum size 3
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
 
    cout << "current size: " << s.getSize() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
 
    cout << "current size: " << s.getSize() << endl;
    return 0;
}
