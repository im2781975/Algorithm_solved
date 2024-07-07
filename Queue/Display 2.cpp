#include <iostream>
#include <climits>
using namespace std;
const int MAX_SIZE = 100;
struct QNode {
    int data;
    QNode* next;
    QNode(int d) {
        data = d;
        next = nullptr;
    }
};
struct Queue {
    QNode *front, *rear;
    Queue() {
        front = rear = nullptr;
    }
};
// check whether the queue is empty or not
bool isEmpty(Queue* queue) {
    return (queue->front == nullptr);
}
// Function to check whether the queue is full or not
//queue is never considered full under the current implementation. This is because the queue uses dynamic memory allocation (i.e., it creates new nodes using the new operator), allowing it to grow as long as there is available memory.
bool isFull(Queue* queue) {
    // Assuming dynamic memory allocation for nodes
    return false;  // You need to handle dynamic memory allocation to make this check meaningful
}
// Function to enqueue an element into the queue
void queueEnqueue(Queue* queue, int data) {
    The function isFull always returns false, which means the check if (isFull(queue)) in the queueEnqueue function will never be true under the current implementation. Therefore, the message "\nQueue is full\n" will never be printed, and the function will always proceed to create a new node and add it to the queue.
    if (isFull(queue)) {
        cout << "\nQueue is full\n";
        return;
    }
    QNode* newNode = new QNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
// dequeue an element from the queue
void queueDequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "\nQueue is empty\n";
        return;
    }
    QNode* temp = queue->front;
    queue->front = temp->next;

    if (queue->front == nullptr) {
        queue->rear = nullptr;
    }

    delete temp;
}
int front(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->front->data;
}
int rear(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->rear->data;
}
int main() {
    Queue myQueue;
    queueEnqueue(&myQueue, 10);
    queueEnqueue(&myQueue, 20);
    queueDequeue(&myQueue);

    cout << "Front of the queue: " << front(&myQueue) << "\n";
    cout << "Rear of the queue: " << rear(&myQueue) << "\n";
    return 0;
}
