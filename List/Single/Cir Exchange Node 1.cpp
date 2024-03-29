//exchange first & last node in circular linked list
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
struct Node* addToEmpty(struct Node* head, int data)
{
    // This function is only for empty list
    if (head != NULL)
        return head;
    // Creating a node dynamically.
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    head = temp;
    // Creating the link.
    head->next = head;
    return head;
}
struct Node* addBegin(struct Node* head, int data)
{
    if (head == NULL)
        return addToEmpty(head, data);
 
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
 
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
    return head;
}
void traverse(struct Node* head)
{
    struct Node* p;
    // If list is empty, return.
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    // Pointing to first Node of the list.
    p = head;
    // Traversing the list.
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}
struct Node* exchangeNodes(struct Node* head)
{
    // If list is of length less than 2
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* tail = head;
    // Find pointer to the last node
    while (tail->next != head) {
        tail = tail->next;
    }
    // Exchange first and last nodes using head and p 
   
    //temporary variable to store head data
    int temp = tail->data; 
    tail->data = head->data;
    head->data = temp;
    return head;
}
int main()
{
    int i;
    struct Node* head = NULL;
    head = addToEmpty(head, 6);
 
    for (i = 5; i > 0; i--)
        head = addBegin(head, i);
    cout << "List Before: ";
    traverse(head);
    cout << endl;
 
    cout << "List After: ";
    head = exchangeNodes(head);
    traverse(head);
    return 0;
}
