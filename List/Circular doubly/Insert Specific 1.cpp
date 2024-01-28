#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
// Function to create a new node
struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void displayList(struct Node* start)
{
    if (start == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "The list is: ";
    struct Node* temp = start;
 
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
 
    cout << endl;
}
// Function to count the number of elements in the list
int countList(struct Node* start)
{
    if (start == NULL)
        return 0;
    int count = 0;
    struct Node* temp = start;
 
    do {
        count++;
        temp = temp->next;
    } while (temp != start);
 
    return count;
}
// Function to insert a node at a given position
bool insertAtLocation(struct Node** start, int data, int loc)
{
    int count = countList(*start);
    if (loc < 1 || loc > count + 1)
        return false;
 
    struct Node* newNode = getNode(data);
 
    // If the list is empty
    if (*start == NULL) {
        *start = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    // If the node is to be inserted at the beginning
    else if (loc == 1) {
        newNode->next = *start;
        newNode->prev = (*start)->prev;
        (*start)->prev->next = newNode;
        (*start)->prev = newNode;
        *start = newNode;
    }
    else {
        struct Node* temp = *start;
        int currPos = 1;
        // Traverse to the node before the desired position
        while (currPos < loc - 1) {
            temp = temp->next;
            currPos++;
        }
        // Insert the new node
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    return true;
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // Start Pointer
    struct Node* start = NULL;
    // Create the List
    for (int i = 0; i < n; i++)
        insertAtLocation(&start, arr[i], i + 1);
    displayList(start);

    // Inserting 8 at 3rd position
    insertAtLocation(&start, 8, 3);
    displayList(start);
    return 0;
}
