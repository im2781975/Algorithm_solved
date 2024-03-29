//check is circular
#include<bits/stdc++.h> 
using namespace std; 
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
bool isCircular(struct Node *head) 
{ 
    if (head == NULL) 
       return true; 
  
    // Next of head 
    struct Node *node = head->next;
    
    // This loop would stop in both cases (1) If Circular (2) Not circular 
    while (node != NULL && node != head) 
       node = node->next; 
    // If loop stopped because of circular condition 
    return (node == head); 
}
Node *newNode(int data) 
{ 
    struct Node *temp = new Node; 
    temp->data = data; 
    temp->next = NULL; 
    return temp; 
} 
int main() 
{ 
    struct Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
  
    isCircular(head)? cout << "Yes\n" : cout << "No\n" ; 
  
    // Making linked list circular 
    head->next->next->next->next = head; 
    isCircular(head)? cout << "Yes\n" :cout << "No\n" ; 
    return 0; 
} 
