//convert insert an element at a specific position in a circular doubly linked list
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
// function to create a node in memory
struct node* getNode()
{
    return ((struct node*)malloc(sizeof(struct node)));
}
int displayList(struct node* temp)
{
    struct node* t = temp;
    if (temp == NULL)
        return 0;
    else {
        cout << "The list is: ";
 
        while (temp->next != t) {
            cout << temp->data << " ";
            temp = temp->next;
        }
 
        cout << temp->data << endl;
        return 1;
    }
}
// Function to count number of elements in the list
int countList(struct node* start)
{
    // Declare temp pointer to traverse the list
    struct node* temp = start;
    int count = 0;
    // Iterate the list and increment the count
    while (temp->next != start) {
        temp = temp->next;
        count++;
    }
    // As the list is circular, increment the counter at last
    count++;
    return count;
}
// Function to insert a node at a given position in the circular doubly linked list
bool insertAtLocation(struct node* start, int data, int loc)
{
    // Declare two pointers
    struct node *temp, *newNode;
    int i, count;
    // Create a new node in memory
    newNode = getNode();
    // Point temp to start
    temp = start;
    // count of total elements in the list
    count = countList(start);
    // If list is empty or the position is not valid, return false
    if (temp == NULL || count < loc)
        return false;
 
    else {
        newNode->data = data;
        // Iterate till the loc
        for (i = 1; i < loc - 1; i++)
            temp = temp->next;
 
        // See in Image, circle 1
        newNode->next = temp->next;
        // See in Image, Circle 2
        (temp->next)->prev = newNode;
        // See in Image, Circle 3
        temp->next = newNode;
        // See in Image, Circle 4
        newNode->prev = temp;
        return true;
    }
    return false;
}
// Function to create circular doubly linked list from array elements
void createList(int arr[], int n, struct node** start)
{
    // Declare newNode and temporary pointer
    struct node *newNode, *temp;
    int i;
    // Iterate the loop until array length
    for (i = 0; i < n; i++) {
        // Create new node
        newNode = getNode();
        // Assign the array data
        newNode->data = arr[i];
        // If it is first element Put that node prev and next as start as it is circular
        if (i == 0) {
            *start = newNode;
            newNode->prev = *start;
            newNode->next = *start;
        }
        else {
            // Find the last node
            temp = (*start)->prev;
 
            // Add the last node to make them in circular fashion
            temp->next = newNode;
            newNode->next = *start;
            newNode->prev = temp;
            temp = *start;
            temp->prev = newNode;
        }
    }
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // Start Pointer
    struct node* start = NULL;
    createList(arr, n, &start);
    // Display the list before insertion
    displayList(start);
    // Inserting 8 at 3rd position
    insertAtLocation(start, 8, 3);
    displayList(start);
    return 0;
}
