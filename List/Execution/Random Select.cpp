// randomly select a node
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node {
public:
    int key;
    Node* next;
    void printRandom(Node*);
    void push(Node**, int);
};
 
Node* newNode(int new_key)
{
    // allocate node
    Node* new_node = (Node*)malloc(sizeof(Node));
    // put in the key
    new_node->key = new_key;
    new_node->next = NULL;
    return new_node;
}
void Node::push(Node** head_ref, int new_key)
{
    Node* new_node = new Node;
    new_node->key = new_key;
    //link the old list of the new node
    new_node->next = (*head_ref);
    // move the head to point to the new node 
    (*head_ref) = new_node;
}
void printRandom(Node* head)
{
    Node* temp = head;
    vector<int> v;
    while (temp != NULL) {
        v.push_back(temp->key);
        temp = temp->next;
    }
    int n = v.size();
    int randIndex = rand() % n;
    cout << v[randIndex] << endl;
}
int main()
{
    Node n1;
    Node* head = NULL;
    n1.push(&head, 5);
    n1.push(&head, 20);
    n1.push(&head, 4);
    n1.push(&head, 3);
    n1.push(&head, 30);
    printRandom(head);
    return 0;
}
