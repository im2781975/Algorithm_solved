// rotate a linked list block wise
#include<bits/stdc++.h>
using namespace std;
class Node 
{ 
    public:
    int data; 
    Node* next; 
};
// Recursive function to rotate one block 
Node* rotateHelper(Node* blockHead, Node* blockTail, 
    int d, Node** tail, int k) 
{ 
    if (d == 0) 
        return blockHead; 
    // Rotate Clockwise 
    if (d > 0) 
    { 
        Node* temp = blockHead; 
        for (int i = 1; temp->next->next && 
                        i < k - 1; i++) 
            temp = temp->next; 
        blockTail->next = blockHead; 
        *tail = temp; 
        return rotateHelper(blockTail, temp, 
                            d - 1, tail, k); 
    } 
    // Rotate anti-Clockwise 
    if (d < 0) 
    { 
        blockTail->next = blockHead; 
        *tail = blockHead; 
        return rotateHelper(blockHead->next, 
                blockHead, d + 1, tail, k); 
    } 
} 
// Function to rotate the linked list block wise 
Node* rotateByBlocks(Node* head,int k, int d) 
{ 
    // If length is 0 or 1 return head 
    if (!head || !head->next) 
        return head; 
    // if degree of rotation is 0, return head 
    if (d == 0) 
        return head; 
 
    Node* temp = head, *tail = NULL; 
    // Traverse upto last element of this block 
    int i; 
    for (i = 1; temp->next && i < k; i++) 
        temp = temp->next; 
    // storing the first node of next block 
    Node* nextBlock = temp->next; 
 
    // If nodes of this block are less than k. Rotate this block also 
    if (i < k) 
        head = rotateHelper(head, temp, d % k, 
                                    &tail, i); 
    else
        head = rotateHelper(head, temp, d % k, &tail, k); 
    // Append the new head of next block to the tail of this block 
    tail->next = rotateByBlocks(nextBlock, k, d % k); 
    // return head of updated Linked List 
    return head; 
}
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}
void printList(Node* node) 
{ 
    while (node != NULL) 
    { 
        cout << node->data << " ";
        node = node->next; 
    } 
}
int main() 
{
    Node* head = NULL; 
    for (int i = 9; i > 0; i -= 1) 
        push(&head, i); 
 
    cout<<"Given linked list \n"; 
    printList(head); 
    // k is block size and d is number of rotations in every block. 
    int k = 3, d = 2; 
    head = rotateByBlocks(head, k, d); 
 
    cout << "\nRotated by blocks Linked list \n"; 
    printList(head); 
    return (0); 
} 
