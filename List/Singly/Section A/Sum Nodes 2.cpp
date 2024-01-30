//find the sum of last 'n' nodes of the Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
// insert a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = new Node;
    // put in the data
    new_node->data = new_data;
    //link the old list to the new node 
    new_node->next = (*head_ref);
    //move the head to point to the new node
    (*head_ref) = new_node;
}
// find the sum of last 'n' nodes
int sumOfLastN_NodesUtil(struct Node* head, int n)
{
    // if n == 0
    if (n <= 0)
        return 0;
    int sum = 0, len = 0;
    struct Node* temp = head;
    // calculate the length of the linked list
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    // count of first (len - n) nodes
    int c = len - n;
    temp = head;
    // just traverse the 1st 'c' nodes
    while (temp != NULL && c--)
        // move to next node
        temp = temp->next;
    // now traverse the last 'n' nodes and add them
    while (temp != NULL) {
        // accumulate node's data to sum
        sum += temp->data;
        // move to next node
        temp = temp->next;
    }
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
