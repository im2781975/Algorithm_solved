//delete a linked list
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
//delete the entire linked list
void deleteList(Node** head_ref)
{
    // deref head_ref to get the real head 
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
    // deref head_ref to affect the real head back in the caller
    *head_ref = NULL;
}
// Given a reference (pointer to pointer) to the head of a list and an int, push a new node on the front of the list. 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    //link the old list of the new node 
    new_node->next = (*head_ref);
    // move the head to point to the new node 
    (*head_ref) = new_node;
}
int main()
{
    Node* head = NULL;

    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
 
    cout << "Deleting linked list";
    deleteList(&head);
    cout << "\nLinked list deleted";
}
