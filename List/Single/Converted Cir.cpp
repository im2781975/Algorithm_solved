//converting singly linked list into circular linked list.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
struct Node* circular(struct Node* head)
{
    // declare a node variable start & assign head node into start node.
    struct Node* start = head;
    while (head->next != NULL)
        head = head->next;
    head->next = start;
    return start;
}
void push(struct Node** head, int data)
{
    // Allocate dynamic memory for newNode.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 
    // Assign the data into newNode
    newNode->data = data;
    // newNode->next assign the address of head node.
    newNode->next = (*head);
    // newNode become the headNode.
    (*head) = newNode;
}
void displayList(struct Node* node)
{
    struct Node* start = node;
 
    while (node->next != start) {
        cout << " " << node->data;
        node = node->next;
    }
    // Display the last node of circular linked list.
    cout << " " << node->data;
}
int main()
{
    // Start with empty list
    struct Node* head = NULL;
    push(&head, 15);
    push(&head, 14);
    push(&head, 13);
    push(&head, 22);
    push(&head, 17);
 
    circular(head);
    cout << "Display list: \n";
    displayList(head);
    return 0;
}
