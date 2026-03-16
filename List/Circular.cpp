
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Insert at beginning of circular list
void push(Node*& head, int data) {
    Node* newNode = new Node{data, head};
    
    if (!head) {
        newNode->next = newNode;  // Single node
    } else {
        // Find tail and link it to newNode
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = newNode;
    }
    head = newNode;
}

// Print circular list
void print(Node* head) {
    if (!head) return;
    
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    
    cout << "Circular list: ";
    print(head);
}
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};
void convertToCircular(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head;
}
void printList(Node* head) {
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
 
    convertToCircular(head);
 
    cout << "The circular linked list is: ";
    printList(head);
    return 0;
}
#include <bits/stdc++.h>
//exchange first and last node in circular linked list
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Convert singly linked list to circular
Node* makeCircular(Node* head) {
    if (!head) return head;
    
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;
    return head;
}

// Insert at head
void push(Node** head, int data) {
    Node* newNode = new Node{data, *head};
    *head = newNode;
}

// Display circular list
void display(Node* head) {
    if (!head) return;
    
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    
    push(&head, 15);
    push(&head, 14);
    push(&head, 13);
    push(&head, 22);
    push(&head, 17);
    
    head = makeCircular(head);
    cout << "Circular list: ";
    display(head);
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at front (handles empty list)
void insertFront(Node*& head, int data) {
    Node* newNode = new Node{data, head ? head->next : nullptr};
    
    if (!head) {
        newNode->next = newNode;
        head = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
}

// Display circular list
void display(Node* head) {
    if (!head) return;
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

// Swap first and last nodes (actual pointer swap)
Node* swapFirstLast(Node* head) {
    if (!head || head->next == head) return head;  // 0 or 1 node
    
    // Case: exactly 2 nodes
    if (head->next->next == head) {
        head->next->next = head;
        head = head->next;
        return head;
    }
    
    // Find second last node
    Node *prevLast = head, *last = head->next;
    while (last->next != head) {
        prevLast = last;
        last = last->next;
    }
    
    // Swap: last becomes new head
    prevLast->next = head;
    head->next = last->next;
    last->next = head;
    return last;
}
#include <iostream> 
using namespace std; 
  
class LinkedList { 
private: 
    class Node { 
    public: 
        int data; 
        Node* next; 
        Node(int data) { 
            this->data = data; 
            this->next = nullptr; 
        } 
    }; 
    Node* head; 
  
    public: 
    LinkedList() { 
        head = nullptr; 
    } 
    void addToFront(int data) { 
        Node* newNode = new Node(data); 
        newNode->next = head; 
        head = newNode; 
    } 
    bool isCircular() { 
        if (head == nullptr) { 
            return false; 
        } 
        Node* slow = head; 
        Node* fast = head->next; 
        while (fast != nullptr && fast->next != nullptr) { 
            if (slow == fast) { 
                return true; 
            } 
            slow = slow->next; 
            fast = fast->next->next; 
        } 
        return false; 
    } 
}; 
int main() { 
    LinkedList list; 
    list.addToFront(1); 
    list.addToFront(2); 
    list.addToFront(3); 
    list.addToFront(4); 
    cout << boolalpha << list.isCircular() << endl; 
    return 0; 
} 
int main() {
    Node* head = nullptr;
    
    // Create: 1->2->3->4->5->6
    for (int i = 1; i <= 6; ++i) insertFront(head, i);
    
    cout << "Before: "; display(head);
    head = swapFirstLast(head);
    cout << "After:  "; display(head);
}

