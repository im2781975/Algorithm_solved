//search an element in linked list
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    struct Node* next;
};
void push(struct Node** head_ref, int new_key)
{
    // allocate node
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    // put in the key
    new_node->key = new_key;
    // link the old list of the new node 
    new_node->next = (*head_ref);
    // move the head to point to the new node 
    (*head_ref) = new_node;
}
// Checks whether the value x is present in linked list 
bool search(struct Node* head, int x)
{
    // Base case
    if (head == NULL)
        return false;
    // If key is present in current node, return true
    if (head->key == x)
        return true;
    // Recur for remaining list
    return search(head->next, x);
}
int main()
{
    struct Node* head = NULL;
    int x = 21;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
 
    search(head, x) ? cout << "Yes" : cout << "No";
    return 0;
}
 
