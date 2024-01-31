#include <bits/stdc++.h>
using namespace std;
struct Node {
    int number;
    Node* next;
};
//Given a reference (pointer to pointer) to the head of a list and an int, appends a new node at the end
void append(Node** head_ref, int new_data)
{
    //allocate node
    Node* new_node = new Node();
    // Used in step 5
    Node* last = *head_ref;
    //Put in the data
    new_node->data = new_data;
    // This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;
 
    // If the Linked List is empty,then make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }
    // Change the next of last node
    last->next = new_node;
    return;
}
void Push(Node** head, int A)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->number = A;
    n->next = *head;
    *head = n;
}
 
void deleteN(Node** head, int position)
{
    Node* temp;
    Node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
 
                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}
 
void printList(Node* head)
{
    while (head) {
        if (head->next == NULL)
            cout << "[" << head->number << "] "
                 << "[" << head << "]->"
                 << "(nil)" << endl;
        else
            cout << "[" << head->number << "] "
                 << "[" << head << "]->" << head->next
                 << endl;
        head = head->next;
    }
    cout << endl << endl;
}
int main()
{
    Node* list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    Push(&list, 1);
    Push(&list, 2);
    Push(&list, 3);
 
    printList(list);
    // Delete any position from list
    deleteN(&list, 1);
    printList(list);
    return 0;
}
