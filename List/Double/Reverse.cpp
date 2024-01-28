//reverse a doubly linked list
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};
void reverse(Node** head_ref)
{
    Node* temp = NULL;
    Node* current = *head_ref;
 
    //swap next and prev for all nodes 
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    // Before changing the head, check for the cases like
    //empty list and list with only one node 
    if (temp != NULL)
        *head_ref = temp->prev;
}
//Function to insert a node at the beginning
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->prev = NULL;
 
    // link the old list of the new node 
    new_node->next = (*head_ref);
 
    //change prev of head node to new node 
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    //move the head to point to the new node 
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
    Node* head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    cout << "Original Linked list" << endl;
    printList(head);
    reverse(&head);
    cout << "\nReversed Linked list" << endl;
    printList(head);
    return 0;
}
