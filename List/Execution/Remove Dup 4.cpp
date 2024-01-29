//remove duplicates
#include <bits/stdc++.h>
using namespace std;
//Link list node
class Node {
public:
    int data;
    Node* next;
};
//removes duplicates
void removeDuplicates(Node* head)
{
    // Pointer to traverse the linked list
    Node* current = head;
    // Pointer to store the next pointer of a node to be deleted
    Node* next_next;
    // do nothing if the list is empty 
    if (current == NULL)
        return;
    // Traverse the list till last node 
    while (current->next != NULL) {
        // Compare current node with next node 
        if (current->data == current->next->data) {
            // The sequence of steps is important
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
            current = current->next;
    }
}
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
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
    cout << "Linked list before duplicate removal " << endl;
    printList(head);
    removeDuplicates(head);
    cout << "\nLinked list after duplicate removal "
         << endl;
    printList(head);
    return 0;
}
