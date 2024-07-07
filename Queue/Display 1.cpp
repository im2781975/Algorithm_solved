#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *nxt;
    node(int val):data(val), nxt(NULL){}
};
struct Queue{
    node *front, *rear;
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void enQueue(int val){
        node *newnode = new node(val);
        if(rear == NULL){
            front = rear = newnode;
            return;
        }
        rear ->nxt = newnode;
        rear = newnode;
    }
    void deQueue(){
        if(front == NULL)
            return;
        node *tmp = front;
        front = front->nxt;
        if(front == NULL)
            rear = NULL;
        delete tmp;
    }
};
//Another Implementation
struct node{
    int data;
    node *nxt;
    node(int val):data(val), nxt(NULL){}
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
int main(){
    Queue q;
    for(int i = 10; i <=100; i+= 10)
        q.enQueue(i);
    q.deQueue();
    cout << "Queue Front : " << ((q.front != NULL) ? (q.front)->data : -1)<< endl;
    cout << "Queue Rear : " << ((q.rear != NULL) ? (q.rear)->data : -1);
    //
    Queue q;
    for(int i = 1; i < 100; i+= 10)
        enqueue(&q, i);
    cout << "Front Element is: " << Front(&q);
    cout << "\nBack Element is: " << Back(&q);
}
