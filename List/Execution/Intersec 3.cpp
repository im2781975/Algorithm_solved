#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* intersectPoint(Node* headA, Node* headB)
{
    stack<Node*> stackA;
    stack<Node*> stackB;
    Node* intersectNode = NULL;
 
    while (headB != NULL) {
        stackB.push(headB);
        headB = headB->next;
    }
    while (headA != NULL) {
        stackA.push(headA);
        headA = headA->next;
    }
    if (!stackA.top()->data == stackB.top()->data) {
        return NULL;
    }
 
    while (!stackA.empty() && !stackB.empty()
           && stackA.top()->data == stackB.top()->data) {
        intersectNode = stackA.top();
        stackA.pop();
        stackB.pop();
    }
    return intersectNode;
}
int main()
{
 
    Node* newNode;
    Node* head1 = new Node();
    head1->data = 10;
    Node* head2 = new Node();
    head2->data = 3;
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
    head1->next->next->next = NULL;
    Node* intersect_node = NULL;
 
    // Find the intersection node of two linked lists
    intersect_node = intersectPoint(head1, head2);
 
    cout << "INTERSECTION POINT: " << intersect_node->data;
}
