// remove duplicates
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void removeDuplicates(Node* head)
{
    // Pointer to store the pointer of a node to be deleted
    Node* to_free;
    // do nothing if the list is empty
    if (head == NULL)
        return;
    // Traverse the list till last node 
    if (head->next != NULL) {
        // Compare head node with next node 
        if (head->data == head->next->data) {
            // The sequence of steps is important.to_free pointer stores the next of head pointer which is to be deleted.
            to_free = head->next;
            head->next = head->next->next;
            free(to_free);
            removeDuplicates(head);
        }
        else
            removeDuplicates(head->next);
    }
}
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    // put in the data
    new_node->data = new_data;
   //link the old list of the new node 
    new_node->next = (*head_ref);
    //move the head to point to the new node
    (*head_ref) = new_node;
}
void printList(Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}
int main()
{
    Node* head = NULL;
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);
 
    cout << "Linked list before duplicate removal ";
    printList(head);
    removeDuplicates(head);
 
    cout << "\nLinked list after duplicate removal ";
    printList(head);
    return 0;
}
