// find the sum of last 'n' nodes of the Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
// insert a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    // put in the data
    new_node->data = new_data;
 
    // link the old list to the new node 
    new_node->next = (*head_ref);
 
    //move the head to point to the new node 
    (*head_ref) = new_node;
}
void reverseList(struct Node** head_ref)
{
    struct Node* current, *prev, *next;
    current = *head_ref;
    prev = NULL;
 
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
// function to find the sum of last 'n' nodes
int sumOfLastN_NodesUtil(struct Node* head, int n)
{
    // if n == 0
    if (n <= 0)
        return 0;
    // reverse the linked list
    reverseList(&head);
    int sum = 0;
    struct Node* current = head;
 
    // traverse the 1st 'n' nodes of the reversed linked list and add them
    while (current != NULL && n--) {                   
        // accumulate node's data to 'sum'
        sum += current->data;
        // move to next node
        current = current->next;
    }
    // reverse back the linked list
    reverseList(&head);
    // required sum
    return sum;
}
int main()
{
    struct Node* head = NULL;
    push(&head, 12);
    push(&head, 4);
    push(&head, 8);
    push(&head, 6);
    push(&head, 10);
 
    int n = 2;
    cout << "Sum of last " << n << " nodes = "
         << sumOfLastN_NodesUtil(head, n);
    return 0;
}
