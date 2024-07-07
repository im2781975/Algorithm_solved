#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
    // Declare Variable to store values
    int front, rear, cap, size, *arr;
};
Queue *create(int cap){
    Queue *q = new Queue();
    q->cap = cap;q->size = 0;
    q->front = 0; q->rear = -1;
    q->arr = new int[q->cap];
    return q;
}
bool IsFull(Queue *q){
    return (q->size == q->cap);
}
bool IsEmpty(Queue *q){
    return (q->size == 0);
}
void enque(Queue *q, int val){
    if(IsFull(q)){
        cout << "Queue is full";
        return;
    }
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = val;
    q->size = q->size + 1;
    cout << "\nValue is: " << val;
}
int Deque(Queue *q){
    if(IsEmpty(q))
        return INT_MIN;
    int item = q->arr[q->front];
    q->front = (q->front + 1) % q->cap;
    q->size = q->size -1;
    return item;
}
int Front(Queue *q){
    if(IsEmpty(q))
        return INT_MIN;
    return q->arr[q->front];
}
int Back(Queue *q){
    if(IsEmpty(q))
        return INT_MIN;
    return q->arr[q->rear];
}
int main(){
    Queue *q = create(100);
    for(int i = 0; i < 100; i+= 10)
        enque(q, i);
   cout << "\nFront: " << Front(q);
   cout << "\nBack: " << Back(q);
}
