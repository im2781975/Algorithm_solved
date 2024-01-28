// count occurrences in a linked list using recursion
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
// global variable for counting frequency of given element k
int frequency = 0;
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    // put in the data
    new_node->data = new_data;
 
    // link the old list of the new node 
    new_node->next = (*head_ref);
    // move the head to point to the new node 
    (*head_ref) = new_node;
}
// Counts the no. of occurrences of a node
int count(struct Node* head, int key)
{
    if (head == NULL)
        return frequency;
    if (head->data == key)
        frequency++;
    return count(head->next, key);
}
int main()
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
 
    cout << "count of 1 is " << count(head, 1);
    return 0;
}
