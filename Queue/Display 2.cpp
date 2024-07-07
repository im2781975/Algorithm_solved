#include<iostream>
#include<climits>
using namespace std;
struct node{
    int data;
    node *nxt;
    node(int val):data(val), nxt(nullptr){}
};
struct Queue{
    node *front, *rear;
    Queue():front(nullptr), rear(nullptr){}
};
bool IsEmpty(Queue *q){
    return(q->front == nullptr);
}
// Function to check whether the queue is full or not
//queue is never considered full under the current implementation.
//because the queue uses dynamic memory allocation (i.e., it creates new nodes using the new operator), 
//allowing it to grow as long as there is available memory.
bool IsFull(Queue *q){
    return false;
}
void enqueue(Queue *q, int data){
    if(IsFull(q)){
        cout << "Queue is Full";
        return;
    }
    node *newnode = new node(data);
    if(IsEmpty(q)){
        q->front = q->rear = newnode;
    }
    else{
        q->rear->nxt = newnode;
        q->rear = newnode;
    }
}
void dequeue(Queue *q){
    if(IsEmpty(q)){
        cout << "Queue is empty";
        return;
    }
    node *tmp = q->front;
    q->front = tmp->nxt;
    if(q->front == nullptr)
        q->rear = nullptr;
    free(tmp);
};
int Front(Queue *q){
    if(IsEmpty(q))
        return INT_MIN;
    return q->front->data;
}
int Back(Queue *q){
    if(IsEmpty(q))
        return INT_MIN;
    return q->rear->data;
};
int main(){
    Queue q;
    for(int i = 1; i < 100; i+= 10)
        enqueue(&q, i);
    cout << "Front Element is: " << Front(&q);
    cout << "\nBack Element is: " << Back(&q);
}
