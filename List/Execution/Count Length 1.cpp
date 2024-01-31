//find length or count of nodes in a linked list
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    // link the old list of the new node 
    new_node->next = (*head_ref);
    // move the head to point to the new node 
    (*head_ref) = new_node;
}
// A tail recursive function to count the nodes of a linked list default value of the count is used as zero
int getCount(Node* head, int count = 0)
{
    // base case
    if (head == NULL)
        return count;
    // move the pointer to next node and increase the count
    return getCount(head->next, count + 1);
}
int main()
{
    Node* head = NULL;

    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
 
    cout << "Count of nodes is " << getCount(head);
    return 0;
}
