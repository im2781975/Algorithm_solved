// rearrange nodes as alternate odd even nodes in
#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
    int data; 
    struct Node* next; 
};
void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
    cout << endl; 
}
// Function to create newNode in a linkedlist 
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
// insert at beginning 
Node* insertBeg(Node* head, int val) 
{ 
    Node* temp = newNode(val); 
    temp->next = head; 
    head = temp; 
    return head; 
}
void rearrangeOddEven(Node* head) 
{ 
    stack<Node*> odd; 
    stack<Node*> even; 
    int i = 1; 
  
    while (head != nullptr) { 
        if (head->data % 2 != 0 && i % 2 == 0) { 
  
            // Odd Value in Even Position Add pointer to current node in odd stack 
            odd.push(head); 
        } 
        else if (head->data % 2 == 0 && i % 2 != 0) { 
  
            // Even Value in Odd Position Add pointer to current node  in even stack
            even.push(head); 
        }
        head = head->next; 
        i++; 
    } 
    while (!odd.empty() && !even.empty()) { 
        // Swap Data at the top of two stacks 
        swap(odd.top()->data, even.top()->data); 
        odd.pop(); 
        even.pop(); 
    } 
}
int main() 
{ 
    Node* head = newNode(8); 
    head = insertBeg(head, 7); 
    head = insertBeg(head, 6); 
    head = insertBeg(head, 5); 
    head = insertBeg(head, 3); 
    head = insertBeg(head, 2); 
    head = insertBeg(head, 1); 
  
    cout << "Linked List:" << endl; 
    printList(head); 
    rearrangeOddEven(head); 
  
    cout << "Linked List after "
         << "Rearranging:" << endl; 
    printList(head); 
    return 0; 
} 
