//make middle node as head of  linked list. 
#include <bits/stdc++.h>
using namespace std;
class Node 
{ 
    public:
    int data; 
    Node* next; 
}; 
void setMiddleHead(Node** head) 
{ 
    if (*head == NULL) 
        return; 
    // To traverse list nodes one by one 
    Node* one_node = (*head); 
    // To traverse list nodes by skipping 
    // one. 
    Node* two_node = (*head); 
    // To keep track of previous of middle 
    Node* prev = NULL; 
    while (two_node != NULL && two_node->next != NULL) 
    { 
        // for previous node of middle node
        prev = one_node; 
        // move one node each time
        two_node = two_node->next->next; 
 
        //move two node each time
        one_node = one_node->next; 
    } 
    // set middle node at head 
    prev->next = prev->next->next; 
    one_node->next = (*head); 
    (*head) = one_node; 
} 
// To insert a node at the beginning of linked list. 
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node(); 
    new_node->data = new_data; 
    //link the old list of the new node
    new_node->next = (*head_ref); 
    //move the head to point to the new node 
    (*head_ref) = new_node; 
}
void printList(Node* ptr) 
{ 
    while (ptr != NULL)
    { 
        cout << ptr->data << " "; 
        ptr = ptr->next; 
    } 
    cout<<endl; 
}
int main() 
{
    Node* head = NULL; 
    int i; 
    for (i = 5; i > 0; i--) 
        push(&head, i); 
 
    cout << " list before: "; 
    printList(head); 
    setMiddleHead(&head); 
    cout << " list After: "; 
    printList(head); 
 
    return 0; 
} 
