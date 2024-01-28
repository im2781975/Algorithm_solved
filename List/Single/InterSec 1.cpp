#include <bits/stdc++.h>
struct Node {
    int data;
    struct Node* next;
};
void push(struct Node** head_ref,
          int new_data);
struct Node* sortedIntersect(
    struct Node* a,
    struct Node* b)
{
    struct Node* result = NULL;
    struct Node** lastPtrRef = &result;
 
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            // found a node for the intersection 
            push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next; /* advance the smaller list */
        else
            b = b->next;
    }
    return (result);
}
void push(struct Node** head_ref,
          int new_data)
{
    /* allocate node */
    struct Node* new_node = (struct Node*)malloc(
        sizeof(struct Node));
 
    // put in the data
    new_node->data = new_data;
 
    //link the old list of the new node
    new_node->next = (*head_ref);
    // move the head to point to the new node 
    (*head_ref) = new_node;
}
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct Node* a = NULL;
    struct Node* b = NULL;
    struct Node* intersect = NULL;
 
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);
 
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);
 
    intersect = sortedIntersect(a, b);
    printf("\n Linked list containing common items of a & b \n ");
    printList(intersect);
    return 0;
}
