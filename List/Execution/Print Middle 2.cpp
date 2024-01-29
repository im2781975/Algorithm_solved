#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
void printMiddle(struct node* head)
{
    int count = 0;
    struct node* mid = head;
    while (head != NULL)
    {
        // Update mid, when 'count'
        // is odd number 
        if (count & 1)
            mid = mid->next;
        ++count;
        head = head->next;
    }
    // If empty list is provided 
    if (mid != NULL)
        printf("The middle element is [%d]\n\n", 
                mid->data);
}
void push(struct node** head_ref, int new_data)
{
    // Allocate node 
    struct node* new_node = (struct node*)malloc(
        sizeof(struct node));
 
    new_node->data = new_data;
    // Link the old list of the new node 
    new_node->next = (*head_ref);
    // Move the head to point to the new node 
    (*head_ref) = new_node;
}
void printList(struct node* ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node* head = NULL;
    int i;
    for(i = 5; i > 0; i--) 
    {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }
    return 0;
}
