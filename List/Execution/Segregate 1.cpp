#include <bits/stdc++.h> 
  
using namespace std; 
struct Node { 
    int data; 
    struct Node* next; 
  
    Node(int x) 
    { 
        data = x; 
        next = NULL; 
    } 
}; 
void p(Node* node) 
{ 
    while (node) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
Node* divide(Node* head) 
{ 
  
    queue<Node*> qe, qo,q; 
    Node* cur = head; 
    while (cur) { 
        if (cur->data % 2 == 0) 
            qe.push(cur); 
        else
            qo.push(cur); 
        cur = cur->next; 
    } 
    Node* node = new Node(-100); 
    Node* ans = node; 
  
    while (!qe.empty()) { 
        q.push(qe.front()); 
        qe.pop(); 
    } 
  
    while (!qo.empty()) { 
        q.push(qo.front()); 
        qo.pop(); 
    } 
    while (!q.empty()) { 
        node->next = q.front(); 
        node = q.front(); 
        q.pop(); 
    } 
  
    node->next = NULL; 
    return ans->next; 
} 
  
int main() 
{ 
    Node* head; 
    head = new Node(9); 
    head->next = new Node(1); 
    head->next->next = new Node(6); 
    head->next->next->next = new Node(7); 
    head->next->next->next->next = new Node(3); 
    head->next->next->next->next->next = new Node(4); 
    Node* temp = divide(head); 
    p(temp); 
  
    return 0; 
}
