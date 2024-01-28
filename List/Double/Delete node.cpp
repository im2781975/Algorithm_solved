//delete a node from Doubly Linked List 
#include <bits/stdc++.h> 
using namespace std; 
class Node  
{  
    public: 
    int data;  
    Node* next;  
    Node* prev;  
};  
//head_ref --> pointer to head node pointer.  
//del --> pointer to node to be deleted.
void deleteNode(Node** head_ref, Node* del)  
{  
    if (*head_ref == NULL || del == NULL)  
        return;  
  
    //If node to be deleted is head node
    if (*head_ref == del)  
        *head_ref = del->next;  
  
    //Change next only if node to be deleted is NOT the last node 
    if (del->next != NULL)  
        del->next->prev = del->prev;  
    // Change prev only if node to be deleted is NOT the first node 
    if (del->prev != NULL)  
        del->prev->next = del->next;  
    free(del);  
    return;  
}  
void push(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
  
    // put in the data
    new_node->data = new_data;  
  
    // since we are adding at the beginning,prev is always NULL 
    new_node->prev = NULL;  
    //link the old list of the new node
    new_node->next = (*head_ref);  
  
    //change prev of head node to new node
    if ((*head_ref) != NULL)  
        (*head_ref)->prev = new_node;  
    // move the head to point to the new node
    (*head_ref) = new_node;  
}  
void printList(Node* node)  
{  
    while (node != NULL)  
    {  
        cout << node->data << " ";
        node = node->next;  
    }  
}  
int main()  
{  
    Node* head = NULL;  
    push(&head, 2);  
    push(&head, 4);  
    push(&head, 8);  
    push(&head, 10);  
    cout << "Original Linked list ";  
    printList(head);  
  
    deleteNode(&head, head);
    deleteNode(&head, head->next);
    deleteNode(&head, head->next); 
    cout << "\nModified Linked list ";  
    printList(head);  
  
    return 0; 
}  
  
