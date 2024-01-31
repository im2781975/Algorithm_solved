#include <bits/stdc++.h>
using namespace std;
class node 
{ 
    public:
    int data; 
    node* next; 
}; 
// Helper function for kAltReverse()
node * _kAltReverse(node *node, int k, bool b); 
// Alternatively reverses the given linked list in groups of given size k. 
node *kAltReverse(node *head, int k) 
{ 
    return _kAltReverse(head, k, true); 
} 
// Helper function for kAltReverse(). It reverses k nodes of the list only if 
 //the third parameter b is passed as true, otherwise moves the pointer k nodes ahead and recursively calls itself 
node * _kAltReverse(node *Node, int k, bool b) 
{ 
    if(Node == NULL) 
        return NULL; 
     
    int count = 1; 
    node *prev = NULL; 
    node *current = Node; 
    node *next; 
    // If b is true, then it reverses the k nodes. If b is false, then it moves the current pointer
    while(current != NULL && count <= k) 
    { 
        next = current->next; 
        //Reverse the nodes only if b is true
        if(b == true) 
            current->next = prev; 
                 
        prev = current; 
        current = next; 
        count++; 
    } 
    // If b is true, then node is the kth node.  So attach rest of the list after node. 
    // After attaching, return the new head 
    if(b == true) 
    { 
        Node->next = _kAltReverse(current, k, !b); 
        return prev;         
    } 
    /* If b is not true, then attach 
    rest of the list after prev. 
    So attach rest of the list after prev */
    else
    { 
        prev->next = _kAltReverse(current, k, !b); 
        return Node;     
    } 
}
void push(node** head_ref, int new_data) 
{
    node* new_node = new node();
    // put in the data 
    new_node->data = new_data; 
    // link the old list of the new node
    new_node->next = (*head_ref); 
    // move the head to point to the new node 
    (*head_ref) = new_node; 
}
void printList(node *node) 
{ 
    int count = 0; 
    while(node != NULL) 
    { 
        cout << node->data << " "; 
        node = node->next; 
        count++; 
    } 
}
int main(void) 
{
    node* head = NULL; 
    int i; 
    for(i = 20; i > 0; i--) 
    push(&head, i); 
 
    cout << "Given linked list \n"; 
    printList(head); 
    head = kAltReverse(head, 3); 
 
    cout << "\nModified Linked list \n"; 
    printList(head); 
    return(0); 
} 
