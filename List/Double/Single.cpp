#include <bits/stdc++.h>
struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverse(head);
    
    Node* curr = head;
    int carry = 1;
    
    while (curr && carry) {
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;
        curr = curr->next;
    }
    
    if (carry) {
        Node* newHead = newNode(1);
        newHead->next = head;
        head = newHead;
    }
    
    return reverse(head);
}
void push(Node** head, int data) {
    Node* node = newNode(data);
    node->next = *head;
    *head = node;
}
Node* addOne(Node* head) {
    // Reverse to process from LSD
    head = reverse(head);
    
    Node* curr = head;
    int carry = 1;
    
    // Add 1 with carry propagation
    while (curr && carry) {
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;
        curr = curr->next;
    }
    
    // If still carry, add new node
    if (carry) {
        push(&head, 1);
    }
    
    return reverse(head);
}
// Recursively add 1 from end to beginning and returns carry after all nodes are processed.
int addWithCarry(Node* head)
{
    // If linked list is empty, then return carry
    if (head == NULL)
        return 1;
    // Add carry returned be next node call
    int res = head->data + addWithCarry(head->next);
    // Update data and return new carry
    head->data = (res) % 10;
    return (res) / 10;
}
// This function mainly uses addWithCarry().
Node* addOne(Node* head)
{
    // Add 1 to linked list from end to beginning
    int carry = addWithCarry(head);
    // If there is carry after processing all nodes, then we need to add a new node to linked list
    if (carry) {
        Node* newNode = new Node;
        newNode->data = carry;
        newNode->next = head;
        return newNode; // New node becomes head now
    }
    return head;
}
void printList(Node* node) {
    while (node) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL
");
}
//Adds contents of two linked lists and return the head node
Node* addTwoLists(Node* first, Node* second)
{
    // res is head node of the resultant list
    Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;
    // while both lists exist
    while (first != NULL || second != NULL) {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things  (i) Carry  (ii) Next digit of first list (if there is a next digit) 
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        // update sum if it is greater than 10
        sum = sum % 10;
        // Create a new node with sum as data
        temp = newNode(sum);
        // if this is the first node then set it as head of the resultant list
        if (res == NULL)
            res = temp;
        // If this is not the first node then connect it to the rest
        else
            prev->next = temp;
        // Set prev for next insertion
        prev = temp;
        // Move first and second pointers to next nodes
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    // return head of the resultant list
    return res;
}
Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // reverse the rest list and put the first element at the end 
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    // fix the head pointer
    return rest;
}
int main() {
    Node* head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);
    
    printf("List is ");
    printList(head);
    
    head = addOne(head);
    printf("Resultant list is ");
    printList(head);
    
    return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}
void push(Node** head, int data) {
    Node* node = newNode(data);
    node->next = *head;  // Push at front (simpler)
    *head = node;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node* addTwoLists(Node* l1, Node* l2) {
    Node dummy(0);  // Dummy head
    Node* tail = &dummy;
    int carry = 0;
    
    // Process until both lists + carry are exhausted
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) sum += l1->data, l1 = l1->next;
        if (l2) sum += l2->data, l2 = l2->next;
        
        carry = sum / 10;
        tail->next = newNode(sum % 10);
        tail = tail->next;
    }
    
    return dummy.next;
}
Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertAfter(Node* prev, int data) {
    if (!prev) return;
    Node* node = newNode(data);
    node->next = prev->next;
    prev->next = node;
}
Node* addTwoLists(Node* first, Node* second) {
    // Reverse both lists (LSD first)
    first = reverseList(first);
    second = reverseList(second);
    
    Node dummy(0);  // Dummy head simplifies linking
    Node* tail = &dummy;
    int carry = 0;
    
    // Process both lists + carry
    while (first || second || carry) {
        int sum = carry;
        if (first) sum += first->data, first = first->next;
        if (second) sum += second->data, second = second->next;
        
        carry = sum / 10;
        tail->next = newNode(sum % 10);
        tail = tail->next;
    }
    
    return reverseList(dummy.next);  // Reverse back to MSD-first
}
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverse(head);  // LSD first
    
    Node* curr = head;
    int carry = 1;
    
    // Add 1 digit-by-digit
    while (curr && carry) {
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;
        curr = curr->next;
    }
    
    // Handle remaining carry
    if (carry) {
        Node* newHead = newNode(1);
        newHead->next = head;
        head = newHead;
    }
    
    return reverse(head);  // MSD first
}
int main() {
    Node* first = NULL;
    Node* second = NULL;
    
    push(&first, 6); push(&first, 4); push(&first, 9);
    push(&first, 5); push(&first, 7);  // 75946
    
    push(&second, 8); push(&second, 4);  // 84
    
    cout << "First:  ";
    printList(first);
    cout << "Second: ";
    printList(second);
    
    Node* sum = addTwoLists(first, second);
    cout << "Sum:    ";
    printList(sum);  // 10430
    
    return 0;
}
