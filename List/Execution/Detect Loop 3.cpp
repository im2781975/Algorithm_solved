// return first node of loop
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    struct Node* next;
};
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
//returns distance between first and last node every time last node moves forwards
int distance(Node* first, Node* last)
{
    //counts no of nodes between first and last
    int counter = 0;
    Node* curr;
    curr = first;
    while (curr != last) {
        counter += 1;
        curr = curr->next;
    }
    return counter + 1;
}
// Function to detect first node of loop in a linked list that may contain loop
bool detectLoop(Node* head)
{
    Node* temp = new Node;
    Node *first, *last;
    //first always points to head
    first = head;
    //last pointer initially points to head
    last = head;
    //current_length stores no of nodes between current position of first and last
    int current_length = 0;
    //prev_length stores no of nodes between previous position of first and last
    int prev_length = -1;
    while (current_length > prev_length && last != NULL) {
        // set prev_length to current length then update the current length
        prev_length = current_length;
        // distance is calculated
        current_length = distance(first, last);
        // last node points the next node
        last = last->next;
    }
    if (last == NULL) {
        return false;
    }
    else {
        return true;
    }
}
int main()
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    //Create a loop for testing(5 is pointing to 3)
    head->next->next->next->next->next = head->next->next;
 
    bool found = detectLoop(head);
    if (found)
        cout << "Loop Found";
    else
        cout << "No Loop Found";
    return 0;
}
