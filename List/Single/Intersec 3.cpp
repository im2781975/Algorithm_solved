#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* sortedIntersect(struct Node* a,struct Node* b)
{
    if (a == NULL || b == NULL)
        return NULL;
 
    //If both lists are non-empty Advance the smaller list & call recursively 
    if (a->data < b->data)
        return sortedIntersect(a->next, b);
 
    if (a->data > b->data)
        return sortedIntersect(a, b->next);
 
    // Below lines are executed only when a->data == b->data
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = a->data;
    // Advance both lists and call recursively
    temp->next = sortedIntersect(a->next, b->next);
    return temp;
}
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data = new_data;
    new_node->next = (*head_ref);
 
    //Move the head to point to the new node
    (*head_ref) = new_node;

void printList(struct Node* node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
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
 
    cout << "\n Linked list containing "
         << "common items of a & b \n ";
    printList(intersect);
    return 0;
}
