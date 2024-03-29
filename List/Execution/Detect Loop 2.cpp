//return first node of loop
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
// Function to detect first node of loop in a linked list that may contain loop
bool detectLoop(Node* head)
{
    // Create a temporary node
    Node* temp = new Node;
    while (head != NULL) {
        // This condition is for the case when there is no loop
        if (head->next == NULL)
            return false;
        // Check if next is already pointing to temp
        if (head->next == temp)
            return true;
        // Store the pointer to the next node in order to get to it in the next step
        Node* next = head->next;
        // Make next point to temp
        head->next = temp;
        // Get to the next node in the list
        head = next;
    }
    return false;
}
int main()
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = head->next->next;
    bool found = detectLoop(head);
    if (found)
        cout << "Loop Found";
    else
        cout << "No Loop";
    return 0;
}
