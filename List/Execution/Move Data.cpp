// move last element to front
#include <bits/stdc++.h> 
using namespace std; 
class Node { 
public: 
    int data; 
    Node* next; 
};
void moveToFront(Node** head_ref) 
{ 
    // If linked list is empty, or it contains only one node, the
    //nothing needs to be done,simply return
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 
    Node* secLast = NULL; 
    Node* last = *head_ref; 
  
    //After this loop secLast contains address of second last node 
    //and last contains address of last node in Linked List
    while (last->next != NULL) { 
        secLast = last; 
        last = last->next; 
    } 
    secLast->next = NULL; 
    // Set next of last as head node 
    last->next = *head_ref; 
    //Change the head pointer 
    to point to last node now
    *head_ref = last; 
}
void push(Node** head_ref, int new_data) 
{
    Node* new_node = new Node(); 
    new_node->data = new_data; 
    //link the old list of the new node 
    new_node->next = (*head_ref); 
    // move the head to point to the new node 
    (*head_ref) = new_node; 
}
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
}
int main() 
{ 
    Node* start = NULL; 
    push(&start, 5); 
    push(&start, 4); 
    push(&start, 3); 
    push(&start, 2); 
    push(&start, 1); 
  
    cout << "Linked list before moving last to front\n"; 
    printList(start); 
    moveToFront(&start); 
  
    cout << "\nLinked list after removing last to front\n"; 
    printList(start); 
    return 0; 
} 
