// reverse alternate k nodes in a linked list
#include <bits/stdc++.h>
using namespace std;
class Node 
{ 
    public:
    int data; 
    Node* next; 
}; 
// Reverses alternate k nodes and returns the pointer to the new head node
Node *kAltReverse(Node *head, int k) 
{ 
    Node* current = head; 
    Node* next; 
    Node* prev = NULL; 
    int count = 0; 
 
    // reverse first k nodes of the linked list 
    while (current != NULL && count < k) 
    { 
    next = current->next; 
    current->next = prev; 
    prev = current; 
    current = next; 
    count++; 
    } 
    // Now head points to the kth node.So change next  of head to (k+1)th node
    if(head != NULL) 
    head->next = current; 
    // We do not want to reverse next k nodes. So move the current  pointer to skip next k nodes
    count = 0; 
    while(count < k-1 && current != NULL ) 
    { 
    current = current->next; 
    count++; 
    } 
    //Recursively call for the list starting from current->next. And make rest of the list as next of first node
    if(current != NULL) 
    current->next = kAltReverse(current->next, k); 
    // prev is new head of the input list 
    return prev; 
}
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node();
    // put in the data
    new_node->data = new_data; 
    // link the old list of the new node 
    new_node->next = (*head_ref);
    // move the head to point to the new node 
    (*head_ref) = new_node; 
} 
void printList(Node *node) 
{ 
    int count = 0; 
    while(node != NULL) 
    { 
        cout<<node->data<<" "; 
        node = node->next; 
        count++; 
    } 
} 
int main(void) 
{
    Node* head = NULL; 
    int i; 
    for(i = 20; i > 0; i--) 
    push(&head, i); 
 
    cout<<"Given linked list \n"; 
    printList(head); 
    head = kAltReverse(head, 3); 
 
    cout<<"\n Modified Linked list \n"; 
    printList(head); 
    return(0); 
} 
